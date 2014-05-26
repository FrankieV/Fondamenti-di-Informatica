#include <iostream>

using namespace std;
const int m = 6;
const int n = 7;

void init_matrice(int[][n], int, int);
int Dim_Pivot(int [][n], int[], int[]);
void Verifica_Bande(int[][n], int[], int[],int);

int main()
{
    int M[m][n];
    init_matrice(M,m,n);
    int A[n];
    int B[n];

    int pivot = Dim_Pivot(M,A,B);
    Verifica_Bande(M,A,B,pivot);
}

void init_matrice(int M[][n], int m, int n)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> M[i][j];
        }
    }
}

int Dim_Pivot(int M[][n], int A[] ,int B[])
{
    bool uguali = true;
    int riga = 0;
    while(uguali == true && riga < m)
    {
        for(int j = 0; j<n; j++)
        {
            A[j] = M[riga][j];
            B[j] = M[riga+1][j];

            if(A[j] != B[j])
            {
                uguali = false;
            }
        }

        if(uguali)
            riga+=1;
    }

    return riga;
}

void Verifica_Bande(int M[][n],int A[], int B[], int pivot)
{
    int riga = pivot;
    int dim_banda = 1;
    int array_bande[m] = {0};
    int index = 0;
    bool uguali = true;
    while(riga < m)
    {
        for(int j=0; j<n; j++)
        {
            A[j] = M[riga][j];
            B[j] = M[riga+1][j];

            if(A[j] != B[j] && A[j] != M[riga-1][j])
            {
                uguali = false;
            }
        }

        if(uguali)
        {
            dim_banda+=2;
        }
        else
        {
            index++;
            dim_banda = 1;
        }

        array_bande[index] = dim_banda;
        riga += 1;
    }

    for(int i=0; i<m; i++)
        {
        cout << array_bande[i];
        }
}
