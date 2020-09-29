#include "WifiSTA.h"

bool Communication::WifiSTA::connect(void (*FunctionToCall)(std::string))
{
  this->FunctionToCall = FunctionToCall;
  ESP_ERROR_CHECK( nvs_flash_init() );
  this->initialise_wifi();
  
  return 1;
}

bool Communication::WifiSTA::initialise_wifi(void)
{
    tcpip_adapter_init();
    wifi_event_group = xEventGroupCreate();
    ESP_ERROR_CHECK( esp_event_loop_init(event_handler, NULL) );
    wifi_init_config_t initConfig = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK( esp_wifi_init(&initConfig) );
    ESP_ERROR_CHECK( esp_wifi_set_storage(WIFI_STORAGE_RAM) );

    strcpy((char *)this->config.sta.ssid, EXAMPLE_WIFI_SSID);
    strcpy((char *)this->config.sta.password, EXAMPLE_WIFI_PASS);
  
    ESP_LOGI(TAG, "Setting WiFi configuration SSID %s...", config.sta.ssid);
    ESP_ERROR_CHECK( esp_wifi_set_mode(WIFI_MODE_STA) );
    ESP_ERROR_CHECK( esp_wifi_set_config(ESP_IF_WIFI_STA, &config) );
    ESP_ERROR_CHECK( esp_wifi_start() );
  return 1;
}

void Communication::WifiSTA::communicationInit()
{
  this->conn = netconn_new(NETCONN_TCP);  //cria um novo identificador de conexão
  netconn_bind(this->conn,NULL,4000); //associa a conexão à porta 4000
  netconn_listen(this->conn); //começa a escutar a conexão
}

void Communication::WifiSTA::callFunction(const std::string &data)
{
  ((*this->FunctionToCall)(data));
}

void Communication::WifiSTA::taskRead(void* param)
{
  WifiSTA wifi = *((WifiSTA*)param);
  wifi.communicationInit();
  while(1){
    wifi.err = netconn_accept(wifi.conn, &wifi.newconn);
    if(wifi.err == ERR_OK) {// processando a nova conexão
      struct netbuf *buf; // criando um buffer para armazenar os dados recebidos via wifi
      void *data;      std::string data_char;      u16_t len;
      while((wifi.err = netconn_recv(wifi.newconn, &buf)) == ERR_OK){//entrando na rotina se algum dado for recebido
        // do{
          netbuf_data(buf,&data,&len);//lê os dados recebidos e coloca no buffer
          data_char = (char*)data; //convertendo os dados recebidos para caracter
          //wifi.setReadString(data_char);
          // wifi.write(wifi.getData());
          //std::cout << wifi.getData();
          if(wifi.getFunctionPointer())
            wifi.callFunction(data_char);
	        netbuf_free(buf);
        // }while(netbuf_next(buf) >= 0);//enquanto tiver dados recebidos, continua a executar
      }
      netconn_close(wifi.newconn);      
      netconn_delete(wifi.newconn);
    }
  }
}

void Communication::operator>> (Communication::WifiSTA &wifi, void (*FunctionToCall)(Communication::WifiSTA &wifi))
{ 
  wifi.communicationInit();
  wifi.err = netconn_accept(wifi.conn, &wifi.newconn);
  if(wifi.err == ERR_OK) {// processando a nova conexão
    struct netbuf *buf; // criando um buffer para armazenar os dados recebidos via wifi
    void *data;      std::string data_char;      u16_t len;
    while((wifi.err = netconn_recv(wifi.newconn, &buf)) == ERR_OK){//entrando na rotina se algum dado for recebido
        netbuf_data(buf, &data, &len);//lê os dados recebidos e coloca no buffer
        data_char = (char*)data; //convertendo os dados recebidos para caracter
        wifi.setReadString(data_char);
        (*FunctionToCall)(wifi);
        netbuf_free(buf);
    }
  }
  netconn_close(wifi.newconn);      
  netconn_delete(wifi.newconn);
}

static esp_err_t Communication::event_handler(void *ctx, system_event_t *event)
{
    switch(event->event_id) {
    case SYSTEM_EVENT_STA_START:
        esp_wifi_connect();
        break;
    case SYSTEM_EVENT_STA_GOT_IP:
        xEventGroupSetBits(wifi_event_group, CONNECTED_BIT);
        break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
        /* This is a workaround as ESP32 WiFi libs don't currently
           auto-reassociate. */
        esp_wifi_connect();
        xEventGroupClearBits(wifi_event_group, CONNECTED_BIT);
        break;
    default:
        break;
    }
    return ESP_OK;
}