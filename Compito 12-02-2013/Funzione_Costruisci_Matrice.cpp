#include <iostream>
using namespace std;

int const n = 4;
int const m = 5;

int init_matrix( int ** M, int n, int m)
{
	int numero;
	for( int i = 0; i < n; i++)
		{
			for( int j = 0; j < m; j++)
				{
					cin >> numero;
					M[i][j] = numero;
				}
		}
}

int costruisci_matrice ( int ** M, int ** S, int n, int m)
{
	int somma = 0;
	for( int i = 0; i < n; i++)
		{
			for( int j = 0; j < m; j++)
				{
					for( int e = 0; e < n; e++)
						{
							if( e != i)
								{
									for( int f = 0; f < m; f++)
										{
											if( f != j)
												somma = somma + M[e][f];
										}
								}
						}
					S[i][j] = somma;
					somma = 0;
				}
		}
}

void stampa_matrice( int ** S, int n, int m)
{
	for( int i = 0; i < n; i++)
		{
			for( int j = 0; j < m; j++)
				cout << S[i][j] << " ";
			cout << endl;
		}
	
}

int main() 
{
	int a,b;
	cin >> a >> b;
	const int n = a;
	const int m = b;
	int ** M = new int *[n];
	for(int i =0; i<n; i++)
    {
        M[i] = new int[m];
    }
    int ** S = new int *[n];
	for(int i =0; i<n; i++)
    {
        S[i] = new int[m];
    }
	init_matrix( M, n, m);
	costruisci_matrice( M, S, n, m);
	stampa_matrice( S, n, m);
	return 0;
}
