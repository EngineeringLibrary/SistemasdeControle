#include "externalfunctions.h"

double random()
{
    unsigned long int n = 10000, Z, Za, M = 2147483647, a;
    double X[n];
    srand(time(NULL));
    a = rand() %M+1;
    Za = 1;
    for(unsigned int i = 0; i < n; i++)
    {
        Z = (a*Za)%M;
        X[i] = (double)Za/(M-1);
        Za = Z;
    }
    a = rand() %n;
    return X[a];
}
