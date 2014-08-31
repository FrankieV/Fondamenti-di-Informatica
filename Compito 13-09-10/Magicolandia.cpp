#include <iostream>
#include <cstring>
using namespace std;
int Confronta_Esami( char A[], char B[], int dim_Esame)
{
    int cont = 0;
    int cont_lettere_A = 0;
    int cont_lettere_B = 0;
    int cont_Parola = 0;
    char lista[dim_Esame];
    int cont_parole = 0;
    char Copia_A[dim_Esame];
    char Copia_B[dim_Esame];
    strcpy( Copia_A, A);
    strcpy( Copia_B, B);
    const int dim_Copia_A = strlen( Copia_A);
    const int dim_Copia_B = strlen( Copia_B);
    char Parola_A[dim_Esame];
    char Parola_B[dim_Esame];
    while( cont_lettere_A < dim_Copia_A)
        {
            while(( Copia_A[cont] != ' ') && ( Copia_A[cont] != '-') && ( Copia_A[cont] != ',') && ( Copia_A[cont] != '\0'))
                {
                    if( Copia_A[cont] != '*')
                        {
                            Parola_A[cont_Parola] = Copia_A[cont];
                            Copia_A[cont] = '*';
                            cont_Parola++;
                            cont_lettere_A++;
                        }
                    cont++;
                }
            cont_lettere_A++;
            Copia_A[cont] = '*';
            Parola_A[cont_Parola] = '\0';
            cont = 0;
            cont_Parola = 0;
            while( cont_lettere_B < dim_Copia_B)
                {
                    while(( Copia_B[cont] != ' ') && ( Copia_B[cont] != '-') && ( Copia_B[cont] != ',') &&( Copia_B[cont] != '\0'))
                        {
                            if( Copia_B[cont] != '*')
                                {
                                    Parola_B[cont_Parola] = Copia_B[cont];
                                    Copia_B[cont] = '*';
                                    cont_Parola++;
                                    cont_lettere_B++;
                                }
                            cont++;
                        }
                    cont_lettere_B++;
                    Copia_B[cont] = '*';
                    Parola_B[cont_Parola] = '\0';
                    cont = 0;
                    cont_Parola = 0;
                    if( strcmp( Parola_A, Parola_B) == 0)
                        cont_parole++;
                }
            strcpy( Copia_B, B);
            cont_lettere_B = 0;
        }
    return cont_parole;
}

int main()
{
    const int dim = 100;
    char A[dim];
    char B[dim];
    cin.getline( A, dim);
    cin.getline( B, dim);
    cout << Confronta_Esami( A, B, dim);
    return 0;
}
