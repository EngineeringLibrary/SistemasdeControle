#include <windows.h>
#include <stdio.h>
//#include <cstdlib>
//#include <string>
#include <iostream>

using namespace std;


class Serial {
	private:
	  HANDLE PortaSerial;
	  DCB dcbPortaSerialparams;
	  COMMTIMEOUTS timeouts;
	  char bytes_pra_envio[];
	  char bytes_para_receber[5];
	 
	  Serial();	

public: 
		
		    Serial(const char *namedoor);
		 	void Close();
			void Write(const char *teste);
		    void Read();
		
		
};
