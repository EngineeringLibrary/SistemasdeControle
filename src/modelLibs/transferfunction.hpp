#ifdef testModel
    #include "../../../headers/modelLibs/transferfunction.h"
    #include "../../../headers/modelLibs/statespace.h"
    #include "../../../headers/modelLibs/conversions.h"
#else
    #include "SistemasdeControle/headers/modelLibs/transferfunction.h"
    #include "SistemasdeControle/headers/modelLibs/statespace.h"
    #include "SistemasdeControle/headers/modelLibs/conversions.h"
#endif
//#include "../../../../headers/modelLibs/transferfunction.h"
//#include "../../../../headers/modelLibs/conversions.h"
template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(unsigned rows, unsigned cols)
{
    this->var            = 's';
    this->step           = 0.1;
    this->Continuous     = 1;
    this->timeSimulation = 10;
    this->simulationFlag = false;
    this->estOutput      = 0;
    this->lmax           = 0;
    this->lmin           = 0;
    this->input          = 0;
    this->output         = 0;

    this->TF = LinAlg::Matrix< PolynomHandler::Polynom<Type> >(rows, cols);
}

template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(const LinAlg::Matrix<Type> &numPol, const LinAlg::Matrix<Type> &denPol)
{
    this->TF = LinAlg::Matrix< PolynomHandler::Polynom<Type> >(1,1);
    this->TF(1,1)        = PolynomHandler::Polynom<Type>(numPol,denPol);
    this->var            = 's';
    this->Continuous     = 1;
    this->step           = 0.1;
    this->timeSimulation = 10;
    this->simulationFlag = false;
    this->estOutput      = 0;
    this->lmax           = 0;
    this->lmin           = 0;
    this->input          = 0;
    this->output         = 0;
}

template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(const PolynomHandler::Polynom<Type> &TFSISO)
{
    this->TF = LinAlg::Matrix< PolynomHandler::Polynom<Type> >(1,1);
    this->TF(1,1)        = TFSISO;
    this->var            = 's';
    this->step           = 0.1;
    this->Continuous     = 1;
    this->timeSimulation = 10;
    this->simulationFlag = false;
    this->estOutput      = 0;
    this->lmax           = 0;
    this->lmin           = 0;
    this->input          = 0;
    this->output         = 0;
}

template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(LinAlg::Matrix< PolynomHandler::Polynom<Type> > TF)
{
    this->TF             = TF;
    this->var            = 's';
    this->step           = 0.1;
    this->Continuous     = 1;
    this->timeSimulation = 10;
    this->simulationFlag = false;
    this->estOutput      = 0;
    this->lmax           = 0;
    this->lmin           = 0;
    this->input          = 0;
    this->output         = 0;
}

template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(unsigned rows, unsigned cols, double sampleTime)
{
    this->var            = 'z';
    this->step           = sampleTime;
    this->Continuous     = 0;
    this->timeSimulation = 10;
    this->simulationFlag = false;
    this->TF = LinAlg::Matrix< PolynomHandler::Polynom<Type> >(rows, cols);
    this->estOutput      = 0;
    this->lmax           = 0;
    this->lmin           = 0;
    this->input          = 0;
    this->output         = 0;
}

template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(const LinAlg::Matrix<Type> &numPol, const LinAlg::Matrix<Type> &denPol, double sampleTime)
{
    this->TF = LinAlg::Matrix< PolynomHandler::Polynom<Type> >(1,1);
    this->simulationFlag = false;
    this->TF(1,1)        = PolynomHandler::Polynom<Type>(numPol,denPol);
    this->var            = 'z';
    this->Continuous     = 0;
    this->step           = sampleTime;
    this->timeSimulation = 10;
    this->estOutput      = 0;
    this->lmax           = 0;
    this->lmin           = 0;
    this->input          = 0;
    this->output         = 0;
}

template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(const PolynomHandler::Polynom<Type> &TFSISO, double sampleTime)
{
    this->TF = LinAlg::Matrix< PolynomHandler::Polynom<Type> >(1,1);
    this->simulationFlag = false;
    this->TF(1,1)        = TFSISO;
    this->var            = 'z';
    this->step           = sampleTime;
    this->Continuous     = 0;
    this->timeSimulation = 10;
    this->estOutput      = 0;
    this->lmax           = 0;
    this->lmin           = 0;
    this->input          = 0;
    this->output         = 0;
}

template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(LinAlg::Matrix< PolynomHandler::Polynom<Type> > TF, double sampleTime)
{
    this->TF             = TF;
    this->var            = 'z';
    this->step           = sampleTime;
    this->Continuous     = 0;
    this->timeSimulation = 10;
    this->simulationFlag = false;
    this->estOutput      = 0;
    this->lmax           = 0;
    this->lmin           = 0;
    this->input          = 0;
    this->output         = 0;
}

template<typename Type> template<typename OtherType>
ModelHandler::TransferFunction<Type>::TransferFunction (const ModelHandler::TransferFunction<OtherType>& otherPolynom)
{
    this->TF = LinAlg::Matrix< PolynomHandler::Polynom<Type> >(otherPolynom.getNumberOfRows(),otherPolynom.getNumberOfColumns());
    for(unsigned i = 1; i <= otherPolynom.getNumberOfRows(); i++)
        for(unsigned j = 1; j <= otherPolynom.getNumberOfColumns(); j++)
            this->TF(i,j) = otherPolynom(i,j);

    this->var            = otherPolynom.getVar();
    this->step           = otherPolynom.getSampleTime();
    this->Continuous     = otherPolynom.isContinuous();
    this->timeSimulation = otherPolynom.getTimeSimulation();
    this->simulationFlag = false;
    this->estOutput      = 0;
    this->lmax           = 0;
    this->lmin           = 0;
    this->input          = 0;
    this->output         = 0;
}

template <typename Type>
bool ModelHandler::TransferFunction<Type>::isContinuous() const
{
    return this->Continuous;
}

template <typename Type>
unsigned ModelHandler::TransferFunction<Type>::getNumberOfRows() const
{
    return this->TF.getNumberOfRows();
}

template <typename Type>
unsigned ModelHandler::TransferFunction<Type>::getNumberOfColumns() const
{
    return this->TF.getNumberOfColumns();
}

template <typename Type>
double ModelHandler::TransferFunction<Type>::getSampleTime() const
{
    return this->step;
}

template <typename Type>
void ModelHandler::TransferFunction<Type>::setContinuous(const bool &continuous)
{
    if(continuous)
        this->var = 's';
    else
        this->var = 'z';

    this->Continuous = continuous;
}

template <typename Type>
void ModelHandler::TransferFunction<Type>::setSampleTime(const double &sampleTime)
{
    this->step = sampleTime;
}

template <typename Type>
void ModelHandler::TransferFunction<Type>::setLinearModel(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output)
{
    Input = 0;
    Output = 0;
}

template <typename Type>
PolynomHandler::Polynom<Type>& ModelHandler::TransferFunction<Type>::operator ()(unsigned row, unsigned column)
{
    return this->TF(row, column);
}

template <typename Type>
PolynomHandler::Polynom<Type> ModelHandler::TransferFunction<Type>::operator ()(unsigned row, unsigned column) const
{
    return this->TF(row, column);
}


template <typename Type>
void ModelHandler::TransferFunction<Type>::operator= (const PolynomHandler::Polynom<Type> &rhs)
{
    this->TF(1,1) = rhs;
}

template <typename Type>
ModelHandler::TransferFunction<Type>& ModelHandler::TransferFunction<Type>::operator= (const TransferFunction<Type>& otherTransferFunction)
{
    this->TF = otherTransferFunction.TF;

    this->step     = otherTransferFunction.step;
    this->Continuous   = otherTransferFunction.Continuous;
    this->timeSimulation = otherTransferFunction.timeSimulation;
    this->var = otherTransferFunction.var;
    this->simulationFlag = false;

    return *this;
}

template <typename Type> template<typename OtherTransferFunctionType>
ModelHandler::TransferFunction<Type>& ModelHandler::TransferFunction<Type>::operator= (const TransferFunction<OtherTransferFunctionType>& otherTransferFunction)
{
    this->TF = LinAlg::Matrix< PolynomHandler::Polynom<Type> >(otherTransferFunction.getNumberOfRows(),otherTransferFunction.getNumberOfColumns());
    for(unsigned i = 1; i <= otherTransferFunction.getNumberOfRows(); i++)
        for(unsigned j = 1; j <= otherTransferFunction.getNumberOfColumns(); j++)
            this->TF(i,j) = otherTransferFunction(i,j);

    this->var            = otherTransferFunction.getVar();
    this->step           = otherTransferFunction.getSampleTime();
    this->Continuous     = otherTransferFunction.isContinuous();
    this->timeSimulation = otherTransferFunction.getTimeSimulation();
    this->simulationFlag = false;

    return *this;
}

template <typename Type>
std::string ModelHandler::TransferFunction<Type>::print()
{    
    unsigned rows = this->TF.getNumberOfRows(), columns = this->TF.getNumberOfColumns();
    std::string polyNum[rows][columns];
    std::string polyDen[rows][columns];
    std::string numSpace[rows][columns], denSpace[rows][columns], midLine[rows][columns];
    unsigned maxSize[rows][columns];
    std::string output;
    for(unsigned i = 1; i <= rows; ++i)
    {
        for(unsigned j = 1; j <= columns; ++j)
            polyNum[i-1][j-1] = PolynomHandler::printSmallPolynom(this->TF(i,j).getNum(),this->var);

        for(unsigned j = 1; j <= columns; ++j)
            polyDen[i-1][j-1] = PolynomHandler::printSmallPolynom(this->TF(i,j).getDen(),this->var);

        for(unsigned j = 0; j < columns; ++j)
        {
            maxSize[i-1][j] = polyNum[i-1][j].length();
            if(maxSize[i-1][j] < polyDen[i-1][j].length())
                maxSize[i-1][j] = polyDen[i-1][j].length();
            maxSize[i-1][j] += 6;

            for(unsigned k = 0; k < unsigned(fabs((maxSize[i-1][j] - polyNum[i-1][j].length())/2)); ++k)
                numSpace[i-1][j] += ' ';
            for(unsigned k = 0; k < maxSize[i-1][j]; ++k)
                midLine[i-1][j] += '-';
            for(unsigned k = 0; k < unsigned(fabs((maxSize[i-1][j] - polyDen[i-1][j].length())/2)); ++k)
                denSpace[i-1][j] += ' ';
        }

        for(unsigned j = 0; j < columns; ++j)
            output += numSpace[i-1][j] + polyNum[i-1][j] + numSpace[i-1][j] + "      ";
        output += '\n';

        for(unsigned j = 0; j < columns; ++j)
            output += midLine[i-1][j] + "      ";
        output += '\n';

        for(unsigned j = 0; j < columns; ++j)
            output += denSpace[i-1][j] + polyDen[i-1][j] + denSpace[i-1][j] + "      ";
        output += '\n'; output += '\n';
    }

    return output;
}

template <typename Type>
std::string ModelHandler::TransferFunction<Type>::ContinuosFirstOrderCaracteristics()
{
    std::ostringstream str;
    Type tau;
    if(this->TF.getNumberOfRows() == 1 && this->TF.getNumberOfColumns() == 1 && this->Continuous){
       PolynomHandler::Polynom<Type> poly = this->TF(1,1);
       if(poly.getNumSize() == 1 && poly.getDenSize() == 2){
            str << "O ganho estatico: " << poly.getNum()(1,poly.getNumSize()) / poly.getDen()(1,poly.getDenSize()) << std::endl;
            tau = poly.getDen()(1,poly.getDenSize()-1) / poly.getDen()(1,poly.getDenSize());
            str << "A constante de tempo: " << tau << std::endl;
            str << "t1: " << 0.11*tau << std::endl;
            str << "t2: " << 0.23*tau << std::endl;
            str << "Tempo de subida (t2-t1): " << 2.2*tau << std::endl;
            str << "Tempo de estabilizacao: " << 4*tau << std::endl;
       }
    }
    std::string ret = str.str();
    return ret;
}

template <typename Type>
std::string ModelHandler::TransferFunction<Type>::ContinuosSecondOrderCaracteristics()
{
    std::ostringstream str;
    Type k, wn, qsi, pd, wd, ts2, tr, tp, Os, Dr;
    if(this->TF.getNumberOfRows() == 1 && this->TF.getNumberOfColumns() == 1 && this->Continuous){
       PolynomHandler::Polynom<Type> poly = this->TF(1,1);
       if(poly.getNumSize() == 1 && poly.getDenSize() == 3){

            wn  = sqrt(fabs(poly.getDen()(1,poly.getDenSize())));
            qsi = poly.getDen()(1,poly.getDenSize()-1) / (wn * 2);
            k   = poly.getNum()(1,poly.getNumSize()) / (wn * wn);
            wd  = wn*sqrt(1-qsi*qsi);
            pd  = 2*M_PI/wd;
            tr  = M_PI/(2*wd);
            tp  = M_PI/(wd);
            ts2 = 4/(qsi*wn);
            Os  = exp(-M_PI*qsi/sqrt(1-qsi*qsi));
            Dr  = exp(-2*M_PI*qsi/sqrt(1-qsi*qsi));


            str << "O ganho estatico: " << k << std::endl;
            str << "Tempo de subida: " << tr << std::endl;
//            str << "Tempo de estabilizacao a 2%: " << 4/(qsi*wn) << std::endl;
            str << "Tempo de estabilizacao a 2%: " << ts2 << std::endl;
            if(qsi > 0 && qsi < 1){
                str << "Frequencia de oscilacao Amortecida: " << wd << std::endl;
                str << "Periodo de oscilacao Amortecida: " << pd << std::endl;
                str << "Sobressinal Maximo: " << Os << std::endl;
                str << "Razao de decaimento: " << Dr << std::endl;
                str << "Tempo para o primeiro Pico: " << tp << std::endl;
            }
       }
    }
    std::string ret = str.str();
    return ret;
}

template <typename Type>
void ModelHandler::TransferFunction<Type>::setLinearVector(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output)
{
    Input  >> this->inputState;
    Output >> this->outputState;

    LinAlg::Matrix<Type> temp;
    for(unsigned i = 1; i <= this->outputState.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= this->inputState.getNumberOfRows(); ++j)
        temp = temp|-this->outputState.getRow(i)|this->inputState.getRow(j);

    this->LinearVectorA = ~(temp);
}

template <typename Type>
Type ModelHandler::TransferFunction<Type>::sim(Type x)
{
    if(this->simulationFlag == false) // Colocar em Tf2Arx
    {
        ModelHandler::ARX<Type> arx = ModelHandler::tf2arxSISO(*this, this->step);
        this->ModelCoef      = ~arx.getModelCoef();
        this->inputState     = LinAlg::Zeros<Type>(this->getNumberOfColumns(),(arx.getNumberOfInputDelays()));
        this->outputState    = LinAlg::Zeros<Type>(this->getNumberOfColumns(),(arx.getNumberOfOutputDelays()));
        this->simulationFlag = true;
    }
    this->setLinearVector(x,this->estOutput);
//    std::cout << this->LinearVectorA << std::endl;
//    std::cout << (this->ModelCoef*this->LinearVectorA) << std::endl;
    this->estOutput = (this->ModelCoef*this->LinearVectorA)(1,1);
    return this->estOutput;
}

template <typename Type>
Type ModelHandler::TransferFunction<Type>::sim(Type x, Type y)
{
    if(this->simulationFlag == false) // Colocar em Tf2Arx
    {
        ModelHandler::ARX<Type> arx = ModelHandler::tf2arxSISO(*this, this->step);
        this->ModelCoef      = ~arx.getModelCoef();
        this->inputState     = LinAlg::Zeros<Type>(this->getNumberOfRows(),this->getNumberOfColumns()*(arx.getNumberOfInputDelays()));
        this->outputState    = LinAlg::Zeros<Type>(this->getNumberOfRows(),this->getNumberOfColumns()*(arx.getNumberOfOutputDelays()));
        this->simulationFlag = true;
    }
    this->setLinearVector(x,y);
    y = (this->ModelCoef*this->LinearVectorA)(1,1);
    return y;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::TransferFunction<Type>::sim(LinAlg::Matrix<Type> x)
{

    for(unsigned i = 1; i <= this->TF.getNumberOfRows(); ++i)
    {
        LinAlg::Matrix<Type> simTemp = LinAlg::Zeros<Type>(x.getNumberOfRows(),x.getNumberOfColumns()+1);
        for(unsigned j = 1; j <= this->TF.getNumberOfColumns(); ++j)
        {
            ModelHandler::TransferFunction<Type> TfTemp(this->TF(i,j));
            TfTemp.Continuous = this->Continuous;
            for(unsigned k = 1; k <= x.getNumberOfColumns(); ++k)
                simTemp(j,k+1) = TfTemp.sim(x(j,k),simTemp(j,k));
        }
        this->EstOutput = this->EstOutput|| sum(simTemp);
    }
    {
        this->setLinearVector(x,this->EstOutput);
        this->EstOutput = this->EstOutput|(this->ModelCoef*this->LinearVectorA);
    }
    return this->EstOutput;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::TransferFunction<Type>::sim(LinAlg::Matrix<Type> x, LinAlg::Matrix<Type> y)
{
    return x + y;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::TransferFunction<Type>::sim(Type lsim, Type lmax, Type step)
{
    return lsim+lmax+step;
}

template<typename Type>
std::ostream& ModelHandler::operator<< (std::ostream& output, ModelHandler::TransferFunction<Type> TF)
{
    if(TF.isContinuous())
    {
        output << "The continuous transfer function is:\n\n";
        output << TF.print();
    }
    else
    {
        output << "The discrete transfer function is:\n\n";
        output << TF.print() << "\n";
        output << "The sample time is: " << TF.getSampleTime();
    }
    return output;
}

template<typename Type>
std::string& ModelHandler::operator<< (std::string& output, ModelHandler::TransferFunction<Type> TF)
{
    std::stringstream ss;
    ss << TF;
    output += ss.str();
    return output;
}
