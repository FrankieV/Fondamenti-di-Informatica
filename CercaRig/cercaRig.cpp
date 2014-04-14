/* Developed by FrankV */

#include <iostream>
using namespace std;
void TrovaElementi(int[],int[],int[],int);
int ControllaUltimaRiga(int[],int[],int);

int main()
{
    int dim;
    cin >> dim;
    const int n = dim;
    int M[n][n];
    int V[n*n];
    int A[n];
    int B[n];
    int U[n];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> M[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        A[i] = M[0][i];
    }

    for(int i=0; i<n; i++)
    {
        B[i] = M[n-1][i];
    }

    int pos = 0;
    while(pos < n*n)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                V[pos] = M[i][j];
                pos++;
            }
        }

    }
    TrovaElementi(A,V,U,dim);
    int elementiTrovati = ControllaUltimaRiga(U,B,dim);
    if(elementiTrovati >= n)
    {
        cout << "VERO";
    }
    else
    {
        cout << "FALSO";
    }

    return 0;
}

void TrovaElementi(int A[],int V[],int U[],int dim)
{
    for(int i = 0; i<dim; i++)
    {
        int temp = A[i];
        U[i] = V[temp-1];
    }
}

int ControllaUltimaRiga(int U[],int B[],int dim)
{
    int pos = 0;
    int trovati = 0;
    while(pos < dim)
    {
        for(int i = 0; i<dim; i++)
        {
            if(U[pos] == B[i])
            {
                trovati++;
            }
        }
        pos++;
    }
    return trovati;
}



