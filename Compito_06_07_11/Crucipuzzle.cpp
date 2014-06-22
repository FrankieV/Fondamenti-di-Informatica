#include <iostream>
#include <cstring>
using namespace std;

/*Da provare con gli esempi forniti nella traccia, le funzioni si comportano bene!*/

void init_matrice( char **matrice, char **copia, int dim)
{
	char carattere;
	for( int i = 0; i < dim; i++)
		{
			for( int j = 0; j < dim; j++)
			 { 
			 	cin >> carattere;
				matrice[i][j] = carattere;
				copia[i][j] = carattere;
			 }
		}
	cout << endl;
}

void stampa_matrice( char **matrice, int dim)
{
	for( int i = 0; i < dim; i++)
		{
			for( int j = 0; j < dim; j++)
				cout << matrice[i][j] << " ";
			cout << endl;
		}
	cout << endl;
}

void est( char ** matrice, char ** copia, int dim, char *ParolaPtr)
{
	
	int dim_parola;
	dim_parola = strlen (ParolaPtr);
	int cont = 0;
	int y = 0;
	int x = 0;
	for( int i = 0; i < dim; i++)
		{
			for( int j = 0; j < dim; j++)
				{
					if( matrice[i][j] == *ParolaPtr)
						{
							ParolaPtr++;
							if( cont == 0)
								{
									x = i;
									y = j;
								}
							cont++;
						}		
					else 
						if( cont != dim_parola)
							{
								ParolaPtr -= cont;
								y = 0;
								x = 0;
								cont = 0;
							}			
				}
		}
	if( cont == dim_parola)
		{
			cout << "Le coordinate sono :" << x << " e " << y << " e la direzione e' EST." << endl;
			while( y < dim_parola)
				{
					copia[x][y] = '*';
					y++;
				}
		}
}

void sud( char ** matrice, char ** copia, int dim, char *ParolaPtr)
{
	
	int dim_parola;
	dim_parola = strlen (ParolaPtr);
	int cont = 0;
	int y = 0;
	int x = 0;
	for( int i = 0; i < dim; i++)
		{
			for( int j = 0; j < dim; j++)
				{
					if( matrice[j][i] == *ParolaPtr)
						{
							ParolaPtr++;
							if( cont == 0)
								{
									x = j;
									y = i;
								}
							cont++;
						}		
					else 
						if( cont != dim_parola)
							{
								ParolaPtr -= cont;
								y = 0;
								x = 0;
								cont = 0;
							}			
				}
		}
	if( cont == dim_parola)
		{
			cout << "Le coordinate sono :" << x << " e " << y << " e la direzione e' SUD." << endl;
			while( x < dim_parola)
				{
					copia[x][y] = '*';
					x++;
				}
		}
}

void ovest( char ** matrice, char ** copia, int dim, char *ParolaPtr)
{
	
	int dim_parola;
	dim_parola = strlen (ParolaPtr);
	int cont = 0;
	int y = 0;
	int x = 0;
	for( int i = 0; i < dim; i++)
		{
			for( int j = dim-1; j >= 0; j--)
				{
					if( matrice[i][j] == *ParolaPtr)
						{
							ParolaPtr++;
							if( cont == 0)
								{
									x = i;
									y = j;
								}
							cont++;
						}		
					else 
						if( cont != dim_parola)
							{
								ParolaPtr -= cont;
								y = 0;
								x = 0;
								cont = 0;
							}			
				}
		}
	if( cont == dim_parola)
		{
			cout << "Le coordinate sono :" << x << " e " << y << " e la direzione e' OVEST." << endl;
			cont = 0;
			while( cont < dim_parola)
				{
					copia[x][y] = '*';
					y--;
					cont++;
				}
		}
}

void nord( char ** matrice, char ** copia, int dim, char *ParolaPtr)
{
	
	int dim_parola;
	dim_parola = strlen (ParolaPtr);
	int cont = 0;
	int y = 0;
	int x = 0;
	for( int i = 0; i < dim; i++)
		{
			for( int j = dim - 1; j >= 0; j--)
				{
					if( matrice[j][i] == *ParolaPtr)
						{
							ParolaPtr++;
							if( cont == 0)
								{
									x = j;
									y = i;
								}
							cont++;
						}		
					else 
						if( cont != dim_parola)
							{
								ParolaPtr -= cont;
								y = 0;
								x = 0;
								cont = 0;
							}			
				}
		}
	if( cont == dim_parola)
		{
			cout << "Le coordinate sono :" << x << " e " << y << " e la direzione e' NORD." << endl;
			cont = 0;
			while( cont < dim_parola)
				{
					copia[x][y] = '*';
					x--;
					cont++;
				}
		}
}

void parola_nascosta( char ** copia, int dim)
{
	for( int i = 0; i < dim; i++)
		{
			for( int j = 0; j < dim; j++)
				{
					if(copia[i][j] != '*')
						cout << copia[i][j];
				}
		}
	cout << endl;
}

int main() 
{	
	const int dim_parola = 100;
	char Parola[dim_parola];
	char *ParolaPtr;
	const int dim = 4;
	
	char ** copia = new char *[dim];
	for(int i = 0; i < dim; i++)
    {
        copia[i] = new char[dim];
	}
    
	char ** matrice = new char *[dim];
	for(int i = 0; i < dim; i++)
    {
        matrice[i] = new char[dim];
    }
	cout << "Inserisci l'elenco delle parole da cercare nella matrice :\n";
	cin.getline( Parola, dim_parola);
	cout << "Inserisci le parole che compongono la matrice : \n";
	init_matrice( matrice, copia, dim);
	cout << "La parola inserita verra' cercata in questa matrice :\n";
	stampa_matrice( matrice, dim);
	ParolaPtr = strtok( Parola, " ");
	for( int i = 0; i < 5; i++)
		{
			est( matrice, copia, dim, ParolaPtr);
			sud( matrice, copia, dim, ParolaPtr);
			ovest( matrice, copia, dim, ParolaPtr);
			nord( matrice, copia, dim, ParolaPtr);
			ParolaPtr = strtok( NULL, " ");
		}
	cout << endl;
	stampa_matrice( copia, dim);
	cout <<"La parola nascosta e : ";
	parola_nascosta( copia, dim);
	return 0;
}
