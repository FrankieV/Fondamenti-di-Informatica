#include <iostream>

using namespace std;
const int dim = 50;
bool pari_dispari(int[], int,int,bool,bool);
int Leggi(int[]);

int main()
{
    int A[dim];
    int dimA = Leggi(A);
    int pos = 1;
    bool pari = true;
    bool prima_volta = true;
    if(pari_dispari(A,dimA,pos,pari,prima_volta))
    {
        cout << "Sequenze alternate";
    }
    else
    {
        cout << "NO";
    }

}


int Leggi(int A[])
{
    int seq;
    int cont = 0;
    cin >> seq;
    while (seq != -1 && cont < dim)
    {
        A[cont] = seq;
        cont++;
        cin >> seq;
    }

    return cont;
}

bool pari_dispari(int A[],int dimA, int pos, bool pari, bool prima_volta)
{

    if(prima_volta)
    {
        int somma = A[0] + A[1];
        if(somma % 2 != 0)
        {
            pari = false;
        }

        prima_volta = false;
    }

    while(pos < dimA-1 )
    {
        if((A[pos] + A[pos+1]) % 2 == 0 && pari == true || (A[pos] + A[pos+1]) % 2 != 0 && pari == false)
        {
            return false;
        }
        else
        {
            if(pari)
            {
                return pari_dispari(A,dimA, pos += 1, pari = false, prima_volta = false);
            }
            else
            {
                return pari_dispari(A,dimA, pos += 1, pari = true, prima_volta = false);
            }
        }

    }

    return true;
}
