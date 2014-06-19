#include <iostream>
#include <cstring>
using namespace std;

void parola_nascosta( char frase[])
{
	const int dim = strlen( frase);
	char Copia_frase[dim];
	strcpy( Copia_frase, frase);
	char *frasePtr;
	frasePtr = Copia_frase;
	for( int i = 0; i < strlen( frase); i++)
		{
			for( int e = i + 1; e < strlen( frase); e++)
				{
					if( *( frase + e) == *frasePtr)
						{
							*( frase + i) = '*';
							*( frase + e) = '*';
						}
				}
			frasePtr++;
		}
}

void print_parola_segreta( char frase[])
	{
		int dim_parola_nascosta = strlen( frase);
		char parola_nascosta[dim_parola_nascosta];
		int cont = 0;
		for( int i = 0; i < strlen( frase); i++)
			{
				if( *(frase + i) != '*')
					{
						*(parola_nascosta + cont ) = *(frase + i);
						cont++;
					}
			}
		*(parola_nascosta + cont) = '\0';
		if( cont == 0)
			cout << "Nella frase non sono presenti parole nascoste";
		else 
			cout << "La parola nascosta e : " << parola_nascosta;
	}
	
int main()
{
	const int dim = 100;
	char frase[dim];
	cin.getline(frase, dim);
	parola_nascosta( frase);
	print_parola_segreta( frase);
	return 0;
}
