#include <iostream>
using namespace std;

int controlla_cifre( int numero, int cont)
{
	while(( numero % 10 != 0) || (( numero / 10) % 10) != 0)
		{
			if((( numero % 10) == (( numero / 10) % 10)) || ((numero % 10) == ( numero )))
				controlla_cifre( numero = numero / 10, cont += 1);
			else 
				return -1;
		}
	return cont;
	
}

int main()
{
	int cont = 0;
	int numero;
	cin >> numero;
	cout << controlla_cifre( numero, cont);
}
