#include <iostream>
using namespace std;

void init_matrix( int ** A, int N)
{
	int numero;
	for( int i = 0; i < N; i++)
		{
			for( int j = 0; j < N; j++)
				{
					cin >> numero;
					A[i][j] = numero;
				}
		}
}


bool Cornici_Decrescenti( int ** A, int N)
{
	const int dim = N * 4;
	int cornice_esterna[dim];
	int cornice_interna[dim];
	int cornici_salvate = 1;
	int indice_finale = N - 1;
	int indice_iniziale = 0;
	int conti = 0;
	int conte = 0;
	bool controllo = false;
	for( int i = 0; i < dim; i++)
		{
			cornice_esterna[i] = 0;
			cornice_interna[i] = 0;
		}
	
	while( indice_iniziale != indice_finale)
		{
			for( int i = indice_iniziale; i <= indice_finale; i++)
				{
					for( int j = indice_iniziale; j <= indice_finale; j++)
						{
							if( j == indice_iniziale || i == indice_iniziale || j == indice_finale || i ==  indice_finale)
								{
									if(( cornici_salvate % 2) == 0)				
										{
											cornice_interna[conti] = A[i][j];
											conti++;
											controllo = true;
										}
									if(( cornici_salvate % 2) != 0)
										{
											cornice_esterna[conte] = A[i][j];
											conte++;
										}
								}
						}
				}
			for( int i = 0; cornice_interna[i] != 0; i++)
				{
					for( int e = 0; cornice_esterna[e] != 0; e++)
						{
							if(cornice_interna[i]  >= cornice_esterna[e])
								return false;
						}
				}
			conte = 0;
			conti = 0;
			indice_iniziale++;
			indice_finale--;
			cornici_salvate++;
			if( controllo == true)
				{
						for( int i = 0; i < dim; i++)
							{
								cornice_esterna[i] = 0;
								cornice_interna[i] = 0;
							}
						controllo = false;
				}

		}
	return true;
}


int main() 
{
	int Dimensione;
	cin >> Dimensione;
	const int N = Dimensione;
	int ** M = new int *[N];
	for(int i = 0; i < N; i++)
    	{
        	M[i] = new int[N];
    	} 
    init_matrix( M, N);
    if(Cornici_Decrescenti( M, N))
    		cout << " Cornici decrescenti ";
    else 
    	cout << " Cornici NON decrescenti";
    return 0;
}
