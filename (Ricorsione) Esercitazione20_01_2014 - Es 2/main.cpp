#include <iostream>

using namespace std;
const int n = 15;
int Leggi(int[]);
int picchiRavvicinati(int[],int,int,int);

int main()
{
    int A[n];
    int dim = Leggi(A);
    int i = 0;
    int cont = 0;
   cout << picchiRavvicinati(A,dim,i, cont);

}

int Leggi(int A[])
{
    int cont = 0;
    while(cont < n)
    {
        cin >> A[cont];
        cont++;
    }

    return cont;
}

int picchiRavvicinati(int A[],int dim, int i,int cont)
{
    while(i<dim-2)
    {
        if(A[i+1] > A[i] && A[i+1] > A[i+2])
        {
            picchiRavvicinati(A,dim,i+=2, cont+=1);
        }

        else
        {
            return false;
        }
    }

    return cont;
}
