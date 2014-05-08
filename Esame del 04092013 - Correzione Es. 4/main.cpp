#include <iostream>

using namespace std;
const int n = 20;
int Leggi(int[]);
int somma(int[],int);

int main()
{
    int A[n];
    int dim = Leggi(A);
    cout << somma(A,dim);

}

int somma(int A[],int dim)
{
    int sum = 0;
    int *p = &dim;

    while(*p >= 0)
    {
        sum += A[*p];
        *p -= 1;
    }

    return sum;
}

int Leggi(int A[])
{
    int seq;
    int cont = 0;
    cin >> seq;
    while(seq >= 0)
    {
        A[cont] = seq;
        cont++;
        cin >> seq;
    }
    return cont-1;
}
