#include <iostream>
using namespace std;

int init_matrix( int ** matrix, int n, int m)
{
	int numero;
	for( int i = 0; i < m; i++)
		{
			for( int j = 0; j < n; j++)
			 	{
			 		cin >> numero;
			 		matrix[i][j] = numero;
			 	}
		}
}

int bande( int **matrice, int n, int m)
	{
		int bande[m];
		int banda = 1;
		int e = 0;
		int dim_bande = 0;
		bool elementi_uguali = true;
		bool pivot = false;
		bool bande_uguali = true;
		for( int i = 0; i < m - 1; i++)
			{
				for( int j = 0; j < n; j++)
					{
						if((matrice[i][j] != matrice[i+1][j]) && ( pivot == false))
							{
								bande[e] = banda;
								e++;
								dim_bande++;
								banda = 1;
								elementi_uguali = false;
								pivot = true;
							}
						if(( j == n - 1) && ( elementi_uguali == true))
								banda++;
					}
				elementi_uguali = true;
				pivot = false;
				if( i == m - 2)
					bande[e] = banda;
			}
		for( int i = 0; i < dim_bande - 1; i++)
			{
				if( bande[i] != bande[i + 1])
					bande_uguali = false;
			}
		if( bande_uguali == true)
			cout << "La matrice e' a bande orizzontali di dimensione : " << bande[e];
		else
			cout << "La matrice non e' a bande orizzontali.";
	}

int main() 
{
	int x, y;
    cin >> x >> y;
    const int m = x;
    const int n = y;
    int ** matrice = new int *[m];
	for(int i = 0; i < m; i++)
    {
        matrice[i] = new int[n];
    }
    init_matrix( matrice, m, n);
    bande( matrice, m, n);
	return 0;
}
