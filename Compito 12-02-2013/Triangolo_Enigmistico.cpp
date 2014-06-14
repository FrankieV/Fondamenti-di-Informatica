#include <iostream>
#include <cstring>
using namespace std;

void stampa( char *Parola)
{
	for( int i = 0; i < strlen ( Parola); i++)
		{
			Parola[i] = *" ";
			cout << Parola << endl;
		}
}
int main() 
{	
	int dim = 100;
	char parola[dim];
	cin.getline( parola, dim);
	stampa( parola);
	return 0;
}
