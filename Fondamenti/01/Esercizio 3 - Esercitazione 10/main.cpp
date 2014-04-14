#include <iostream>

using namespace std;
const int n = 10;
int Leggi(int[]);
bool VerificaArray(int[],int);
int pos = 0;

int main()
{
    int V[n];
    int A[n];
    int dimV = Leggi(V);
   if(VerificaArray(V,dimV))
   {
       cout << "OK =)";
   }
   else
   {
       cout << "NO =(";
   }
}

int Leggi(int V[])
{
    int i = 0;
    int seq;
    while(i<n)
    {
        cin >> seq;
        V[i] = seq;
        i++;

    }
    return i;
}

bool VerificaArray(int V[],int dim)
{
    while(pos < dim/2)
    {
    if(V[pos] == V[dim/2+pos])
    {
        pos++;
        return VerificaArray(V,dim);
    }
    else
    {
        return false;
    }
    }
    return true;
}
