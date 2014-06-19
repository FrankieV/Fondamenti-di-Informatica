#include <iostream>
#include <cstring>
using namespace std;

void elimina_ricorrenze( char frase_iniziale[], char lista_parole[])
	{
		char *lpPtr;
		lpPtr = lista_parole;
		for( int i = 0; i < strlen( lista_parole); i++)
			{
				for( int e = 0; e < strlen( frase_iniziale); e++)
					{
						if( *(frase_iniziale + e) == *lpPtr)
							{	
								*(frase_iniziale + e) = '*';
								break;
							}
					}
				lpPtr++;
			}
	}
	
void stampa_frase( char frase_iniziale[])
	{
		for( int i = 0; i < strlen( frase_iniziale); i++)
			{
				if( frase_iniziale[i] != '*')
					cout << frase_iniziale[i];
			}
	}

int main() 
{
	const int dimensione_frase_iniziale = 100;
	const int dimensione_lista_parole = 100;
	char frase_iniziale[dimensione_frase_iniziale];
	char lista_parole[dimensione_lista_parole];
	cin.getline( frase_iniziale, dimensione_frase_iniziale);
	cin.getline( lista_parole, dimensione_lista_parole);
	elimina_ricorrenze( frase_iniziale, lista_parole);
	stampa_frase( frase_iniziale);
	return 0;
}
