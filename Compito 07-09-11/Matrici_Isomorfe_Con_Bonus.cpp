#include <iostream>
using namespace std;
void Init_Matrice( int **A, int N, int M)
{
    int numero;
    for( int i = 0; i < N; i++)
        {
            for( int j = 0; j < M; j++)
                {
                    cin >> numero;
                    A[i][j] = numero;
                }
        }
}
bool Matrici_Isomorfe( int **A, int **B, int N, int M)
{
    int Blocco_Piu_Esteso;
    int righe = 0;
    int cont = 0;
    bool Isomorfe = true;
    int Blocco_Numero_A = 0;
    int Blocco_Numero_B = 0;
    for( int i = 0; i < N; i++)
        {
            for( int j = 0; j < M; j++)
                {
                    Blocco_Numero_A = A[i][j];
                    Blocco_Numero_B = B[i][j];
                    for( int a = 0; a < N; a++)
                        {
                            for( int b = 0; b < M; b++)
                                {
                                    if( A[a][b] == Blocco_Numero_A)
                                        {
                                            if( B[a][b] != Blocco_Numero_B)
                                                Isomorfe= false;
                                        }
                                }
                        }
                }
        }

    for( int i = 0; i < N; i++)
        {
            for( int j = 0; j < M; j++)
                {
                    Blocco_Numero_A = A[i][j];
                    for( int a = 0; a < N; a++)
                        {
                            for( int b = 0; b < M; b++)
                                {
                                    if( cont > righe)
                                        {
                                            righe = cont;
                                            Blocco_Piu_Esteso = Blocco_Numero_A;
                                        }
                                    if( A[a][b] == Blocco_Numero_A)
                                        {
                                            cont++;
                                            b = M-1;
                                        }
                                }
                        }
                    cont = 0;
                }
        }
    if( Isomorfe == true)
        cout << "Le matrici sono isomorfe!Il numero che si estende per piu righe e': " << Blocco_Piu_Esteso << endl;
    else
        cout << "Le matrici non sono isomorfe!" << endl;
}

int main()
{
    int n, m;
    cin >> m >> n;
    const int N = n;
    const int M = m;
    int **A = new int *[N];
    for( int i = 0; i < N; i++)
        A[i] = new int [M];
    int **B = new int *[N];
    for( int i = 0; i < N; i++)
        B[i] = new int [M];
    cout << endl << endl;
    Init_Matrice( A, N, M);
    cout << endl << endl;
    Init_Matrice( B, N, M);
    cout << endl << endl;
    Matrici_Isomorfe( A, B, N, M);
    return 0;
}
