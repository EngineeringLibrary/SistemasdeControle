#include "pso.h"
//#include <cassert>
#include <ctime>

PSO::PSO()
{
    this->varNum = 1;
    this->PopSize = 80;
    this->GenSize = 2000;
    this->phi1 = 1;
    this->phi2 = 1;
    this->omega = 1;
    this->MinMax = false;
}

PSO::PSO(int varNum, int PopSize, int GenSize)
{

    this->varNum = varNum;
    this->PopSize = PopSize;
    this->GenSize = GenSize;
    this->phi1 = 1;
    this->phi2 = 1;
    this->omega = 1;
    this->MinMax = false;

}

PSO::PSO(int varNum, int PopSize, int GenSize, double phi1, double phi2)
{
    this->varNum = varNum;
    this->PopSize = PopSize;
    this->GenSize = GenSize;
    this->phi1 = phi1;
    this->phi2 = phi2;
    this->omega = 1;
    this->MinMax = false;
}

PSO::PSO(int varNum, int PopSize, int GenSize, double phi1, double phi2, double omega, bool MinMax)
{
    this->varNum = varNum;
    this->PopSize = PopSize;
    this->GenSize = GenSize;
    this->phi1 = phi1;
    this->phi2 = phi2;
    this->omega = omega;
    this->MinMax = MinMax;
}

PSO::~PSO()
{

}

void PSO::initAlgorithm()
{
    this->X.randU(this->PopSize, this->varNum);
//    X.print();
    this->X = this->X*(4.0)-2.0;
    this->V.randU(this->PopSize, this->varNum);
    this->P = this->X;
    this->G.randU(1, this->varNum);
    this->Xfitness = Evaluation(this->X);
//    Xfitness.print();
    this->Gfitness = Evaluation(this->G);
//    Gfitness.print();
    this->Pfitness = this->Xfitness;

}

Matrix PSO::Evaluation(Matrix Matrix2Evaluate)
{
    Matrix ret(Matrix2Evaluate.getRows(), 1);

    //TODO -> Tornar a função mais fléxivel.

    for(int i = 1; i <= Matrix2Evaluate.getRows(); i++)
    {
      ret.add(i, 1, norm(this->Model.getOutput() - Model.simArxOneStep(2, 2, Matrix2Evaluate.getLine(i))));
    }

    return ret;
}

void PSO::ParticleUpdate()
{
    this->X = this->X + this->V;
}

void PSO::VelocityUpdate()
{
    srand((time(NULL)));
    double Rand1, Rand2;


    for(int i = 1; i <= this->PopSize; i++)
        for(int j = 1; j <= this->varNum; j++)
        {
            Rand1 = rand()*this->phi1/RAND_MAX;
            Rand2 = rand()*this->phi2/RAND_MAX;
            this->V.add(i, j, (this->omega*this->V(i,j) + Rand1*(this->P(i,j) - this->X(i,j)) + Rand2*(this->G(1,j) - this->X(i,j))));
        }
}

void PSO::ParticleEvaluation()
{
    this->Xfitness = Evaluation(this->X);
}

void PSO::FitnessUpdate()
{
    if(this->MinMax == true)
        FitnessUpdateMax();
    else
        FitnessUpdateMin();
}

void PSO::FitnessUpdateMin()
{
  for (int i = 1; i <= this->PopSize; i++)
  {
      if (this->Xfitness(i,1) < this->Pfitness(i,1))
      {
          this->Pfitness.add(i,1, this->Xfitness(i,1));
          for(int j = 1; j <= this->varNum; j++)
            this->P.add(i, j, this->X(i,j));
      }

      if (this->Pfitness(i,1) < this->Gfitness(1,1))
      {
          this->Gfitness.add(1,1, this->Pfitness(i,1));
          for(int j = 1; j <= this->varNum; j++)
            this->G.add(1, j, this->P(i,j));
      }
  }
}

void PSO::FitnessUpdateMax()
{
    for (int i = 1; i <= this->PopSize; i++)
    {
        if (this->Xfitness(i,1) > this->Pfitness(i,1))
        {
            this->Pfitness.add(i,1, this->Xfitness(i,1));
            for(int j = 1; j <= this->varNum; j++)
              this->P.add(i, j, this->X(i,j));
        }

        if (this->Pfitness(i,1) > this->Gfitness(1,1))
        {
            this->Gfitness.add(1,1, this->Pfitness(i,1));
            for(int j = 1; j <= this->varNum; j++)
                this->G.add(1, j, this->P(i,j));
        }
    }
}

void PSO::Run()
{
    clock_t start, stop;


    initAlgorithm();

    for(int i = 0; i < this->GenSize; i++)
    {
        VelocityUpdate();
        ParticleUpdate();

//        start = clock();
        this->Xfitness = Evaluation(this->X);
//        stop = clock();
//        this->Stime = (double) (stop-start)/CLOCKS_PER_SEC;
//        cout << this->Stime << endl;

        FitnessUpdate();
//        Gfitness.print();
//        this->GGen = this->GGen||this->G; // função lenta
//        this->GfitnessGen = this->GfitnessnTime||this->Gfitness; // função lenta
    }

}

void PSO::Run(int nTimes)
{
    this->GnTimes.init(nTimes, this->G.getCols());
    this->GfitnessnTime.init(nTimes, 1);
    for (int i = 1; i <= nTimes; i++)
    {
        Run();
//        this->GnTimes = this->GnTimes||this->G;
        this->GfitnessnTime.add(i, 1, this->Gfitness(1,1));
        this->RunTime.add(i, 1, this->Stime);
        this->Gfitness.print();
        this->G.print();
    }

//    this->GfitnessnTime.print();
}

void PSO::setData(Matrix dataIn, Matrix dataOut)
{
    this->Model.addIO(dataIn, dataOut);
}

double PSO::getTime()
{
    return this->Stime;
}
