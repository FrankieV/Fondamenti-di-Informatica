#include <iostream>
#include <cstring>
using namespace std;

void init_schema( char **A, int N, int M)
{
	char carattere;
	for( int i = 0; i < N; i++)
		{
			for( int j = 0; j < M; j++)
				{
					cin >> carattere;
					A[i][j] = carattere;
				}
		}
}

void controlla_parole( char **Schema, char Elenco[], int N, int M )
{
    int cont_torno_a_capo = 0;
    int dim_elenco = strlen( Elenco);
    char Copia[dim_elenco];
    strcpy( Copia,Elenco);
    char *CopiaPtr;
    CopiaPtr = strtok( Copia, " ");
    int dim_Parola = strlen( CopiaPtr);
    char Parola[dim_elenco];
    strcpy( Parola, CopiaPtr);
    int cont_lettere_parole_trovate = 0;
    int cont = 0;
    for( int i = 0; i < N; i++)
        {
            cout << "Riga " << i+1 << ": ";
            for( int j = 0; j < M; j++)
                {
                    if( *CopiaPtr == Schema[i][j])
                        {
                            cont++;
                            CopiaPtr++;
                            if( cont == dim_Parola)
                                {
                                    cont_lettere_parole_trovate += cont;
                                    cont = 0;
                                    cout << Parola << " ";
                                }
                        }
                    else
                        {
                            if( cont != 0)
                                {
                                    if( cont_torno_a_capo == 0)
                                        {
                                            CopiaPtr = CopiaPtr - cont;
                                            j--;
                                        }
                                    cont = 0;
                                }
                            cont_torno_a_capo = 0;
                        }
                    if( cont == 0 && j == M-1)
                        {
                            CopiaPtr = strtok( NULL, " ");
                            dim_Parola = strlen( CopiaPtr);
                            strcpy( Parola, CopiaPtr);
                        }
                    if(( cont_lettere_parole_trovate != M) && ( j == M-1))
                        {
                            j = -1;
                            cont_torno_a_capo++;
                        }
                    if( cont_lettere_parole_trovate == M)
                        j = M-1;
                }
            cont_lettere_parole_trovate = 0;
            cont_torno_a_capo = 0;
            cont = 0;
            strcpy( Copia, Elenco);
            CopiaPtr = strtok( Copia, " ");
            dim_Parola = strlen( CopiaPtr);
            strcpy( Parola, CopiaPtr);
            cout << endl;
        }
}

int main()
{
	int n, m;
	cin >> n >> m;
	const int N = m;
	const int M = n;
	const int dim_elenco = 500;
	char **Schema = new char *[N];
	for( int i = 0; i < N; i++)
    {
		Schema[i] = new char [M];
    }
    char Elenco[dim_elenco];
	init_schema( Schema, N, M);
	cin.getline( Elenco, dim_elenco);
    cin.getline( Elenco, dim_elenco);
    controlla_parole( Schema, Elenco, N, M);
	return 0;
}
