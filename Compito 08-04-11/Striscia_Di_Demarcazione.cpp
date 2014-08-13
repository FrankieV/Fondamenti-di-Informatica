#include <iostream>
using namespace std;

void Init_Matrice( int **A, int N, int M)
{
    int Numero;
    for( int i = 0; i < N; i++)
        {
            for( int j = 0; j < M; j++)
                {
                    cin >> Numero;
                    A[i][j] = Numero;
                }
        }
}

bool Striscia_Di_Demarcazione( int **A, int N, int M)
{
    int riga = 0;
    int colonna = 0;
    bool Settore_Inferiore = false;
    int Massimo = 0;
    int Minimo = A[0][0];
    int Cont = 0;
    int Cont_Elementi_Settore_Inferiore = 0;
    int Somma = 0;
    int Media = 0;
    int Scarto = 0;
    for( int i = 0; i < M; i++)
        {
            for( int j = 0; j < N; j++)
                {
                    if( A[j][i] != 0 && Settore_Inferiore == false)
                        {
                            Cont++;
                            if( A[j][i] > Massimo)
                                Massimo = A[j][i];
                            if( A[j][i] < Minimo)
                                Minimo = A[j][i];
                        }
                    else
                        {
                            if( A[j][i] != 0 && Settore_Inferiore == true)
                                {
                                    Somma += A[j][i];
                                    Cont_Elementi_Settore_Inferiore++;
                                    Cont++;
                                }
                        }
                    if( A[j][i] == 0 && Cont != 0)
                        {
                            Cont = 0;
                            Settore_Inferiore = true;
                        }
                    else
                        {
                            if( A[j][i] == 0 && Cont == 0)
                                return false;
                        }
                    if( j == N - 1 && Cont == 0)
                        return false;
                }
            Cont = 0;
            Settore_Inferiore = false;
        }
    for( int j = 0; j < N; j++)
        {
            if( A[j][colonna] == 0)
                {
                    riga = j;
                    while( colonna != M-1)
                        {
                            if( A[riga][colonna+1] == 0)
                                colonna += 1;
                            else
                                {
                                    if( A[riga+1][colonna+1] == 0)
                                        {
                                            riga += 1;
                                            colonna += 1;
                                        }
                                    else
                                        {
                                            if( A[riga-1][colonna+1] == 0)
                                                {
                                                    riga -= 1;
                                                    colonna += 1;
                                                }
                                            else
                                                return false;
                                        }
                                }
                        }
                }
        }
    Media = Somma / Cont_Elementi_Settore_Inferiore;
    Scarto = Massimo - Minimo;
    if( Media == Scarto)
        return true;
    else
        return false;
}

int main()
{
    int n, m;
    cin >> m >> n;
    const int M = m;
    const int N = n;
    int **Matrice = new int *[N];
    for( int i = 0; i < N; i++)
        Matrice[i] = new int [M];
    Init_Matrice( Matrice, N, M);
    if( Striscia_Di_Demarcazione( Matrice, N, M))
        cout << "OK ";
    else
        cout << "NO";
    return 0;
}
