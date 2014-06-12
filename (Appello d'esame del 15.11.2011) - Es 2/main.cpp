#include <iostream>

using namespace std;
const int dim = 100;
void Ripiegatura(int [],int ,int ,int ,int ,int, bool);
int Leggi(int []);

int main()
{
    int A[dim];
    int dimA = Leggi(A);
    int prec = A[0];
    int corr = A[1];
    int succ = A[2];
    bool scambiato = false;
    int pos = 3;
     Ripiegatura(A,dimA,prec,corr,succ,pos,scambiato);

}

int Leggi(int A[])
{
    int pos = 0;
    int seq;
    cin >> seq;
    while(pos < dim && seq != -1)
    {
        A[pos] = seq;
        pos++;
        cin >> seq;
    }

    return pos;
}

void Ripiegatura(int A[],int dimA,int prec,int corr,int succ,int pos, bool scambiato)
{
    while(pos < dimA)
    {
    succ += A[pos];
    corr += A[pos+1];
    prec += A[pos+2];


    if(scambiato)
    {

        return Ripiegatura(A,dimA,succ,corr,prec,pos+=3,scambiato=false);
    }
    else
    {

        return Ripiegatura(A,dimA,succ,corr,prec,pos+=3,scambiato=true);
    }

    }

    cout << prec << " " <<  corr << " " << succ;


}
