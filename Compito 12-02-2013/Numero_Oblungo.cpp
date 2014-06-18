#include <iostream>
using namespace std;

bool numero_oblungo( int numero, unsigned &n, int cont)
{
	while( cont < numero)
		{
			if(( cont * (cont + 1)) == numero)
				{
					n = cont;
					return true;
				}
			numero_oblungo( numero, n, cont += 1);
		}
	return false;
}

void init_matrix( int n)
{
	const int dim = n;
	int A[dim][dim+1];
	for( int i = 0; i < dim; i++)
		{
			for( int j = 0; j < dim + 1; j++)
				A[i][j] = 0;
		}
	for ( int i = 0; i < dim; i++)
		{
			for( int j = 0; j < dim + 1; j++)
				cout << A[i][j] << " ";
			cout << endl;
		}
}

int main() 
{
	int numero;
	unsigned n;
	int cont = 0;
	cin >> numero;
	if( numero_oblungo( numero, n, cont))
		{
			cout << "Il numero e' oblungo " << n << "*" << "(" << n << "+ 1) " << " lo dimostra" << endl << endl;
			init_matrix( n);
		}
	else
		cout << "Il numero non e' oblungo " << endl;
	return 0;
}
