#include <iostream>

using namespace std;
const int dim = 50;
int Leggi(int []);
bool Funzione(int[],int,int,int);

int main()
{
    int A[dim];
    cout << "Inserisci la sequenza (min 3 coppie): ";
    int dimA = Leggi(A);
    int prec = 2, succ = 3;
    if(dimA % 2 == 0 && dimA >= 6)
    {
    if(Funzione(A,dimA,prec,succ))
        cout << "La sequenza ha tutti gli elementi in comune =)";
    else
        cout << "La sequenza NON ha tutti gli elementi in comune =(";
    }
    else if(dimA < 6)
    {
        cout << "Spiacente, devi inserire minimo tre coppie... " << endl;
    }
    else
    {
        cout << "La sequenza non e' PARI" << endl;
    }

}

int Leggi(int A[])
{
    int seq;
    int pos = 0;
    cin >> seq;
    while(seq != -1 && pos < dim)
    {
        A[pos] = seq;
        pos++;
        cin >> seq;
    }

    return pos;
}

bool Funzione(int A[], int dimA, int prec, int succ)
{
    while(succ <= dimA-2)
    {
        if(A[prec-2] == A[prec] || A[prec-1] == A[prec] || A[prec-2] == A[succ] || A[prec-2] == A[succ])
        {
            if(A[prec+2] == A[prec] || A[prec+3] == A[prec] || A[succ+1] == A[succ] || A[succ+2] == A[succ])
            {
                Funzione(A,dimA,prec+=2,succ+=2);
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}
