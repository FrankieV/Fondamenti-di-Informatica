#include <iostream>
#include <cstring>

using namespace std;
const int dim = 20;
int Occorrenze(int[],int,int, int);
int Leggi(int[]);

int main()
{
    int A[dim];
    int x;
    cin >> x;
    int C = 0;
    int dimA = Leggi(A);
    int N = Occorrenze(A,dimA,x,C);
    cout << N;
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

/*int Occorrenze(int A[],int dimA,int x, int C)
{
    int cont = 0;
    while(x != 0)
    {
        for(int i=0; i < dimA; i++)
        {
            if(A[i] == x)
            {
                A[i] = 0;
                cont++;
            }
        }

       return Occorrenze(A,dimA, x = cont, C += cont);
    }

    return C;

}*/                 RIFARE /!\
