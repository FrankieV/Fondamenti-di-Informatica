#include <iostream>
using namespace std;

int Leggi(int[]);
bool VerificaDimensione(int,int);
bool VerificaPari(int,int);
bool CoppieAl(int[],int[],int);
void Scambia(int[],int);
const int dim = 50;


int main()
{
    int A[dim];
    int B[dim];
    int dimA = Leggi(A);
    int dimB = Leggi(B);
    if(VerificaDimensione(dimA,dimB) && VerificaPari(dimA,dimB))
    {
        if(CoppieAl(A,B,dimA))
        {
            cout<<" le due sequenze sono a coppie alterne ";
        }
        else
        {
            cout<<" le due sequenze NON sono a coppie alterne ";
        }
    }

    return 0;
}

int Leggi(int V[])
{
    int seq;
    int pos = 0;
    cin >> seq;
    while(seq != 0 && pos < dim)
    {
        V[pos] = seq;
        pos++;
        cin >> seq;
    }
    return pos;
}

bool VerificaDimensione(int dima, int dimb)
{
    if(dima != dimb)
    {
        cout<<" le due sequenze hanno dimensioni diverse e percio' " << " non possono essere a coppie alterne ";
        return false;
    }
    return true;
}

bool VerificaPari(int dima,int dimb)
{
    if(dima % 2 != 0 && dimb % 2 != 0)
    {
        cout<<" la dimensione delle sequenze DEVE essere pari ";
        return false;
    }

    return true;
}

bool CoppieAl(int A[],int B[],int dim)
{
    Scambia(B,dim);
    int pos = 0;
    bool coppieAl = false;
    while(pos < dim)
    {
        if(A[pos] != B[pos])
        {
            return false;
        }
        pos++;
    }
    return true;
}

void Scambia(int B[],int dim)
{
    int pos = 0;
    int j = 1;
    while(pos<dim)
    {
        int temp = B[pos];
        B[pos] = B[j];
        B[j] = temp;
        pos+=2;
        j+=2;
    }
}
