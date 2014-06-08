#include <iostream>
using namespace std;

int ricorsiva_occorrenze(int A[], int dim, int X, int N, int c, int cont) 
{
 	while( (X != 0))
		{
			if( cont == dim)
				{
					X = c;
					c = 0;
					cont = 0;
					return ricorsiva_occorrenze( A, dim, X, N, c, cont);
				}
			else
				if( A[cont] == X)
					{
						N += 1;
						c += 1;
						A[cont] = 0;
			  		 }
			return ricorsiva_occorrenze( A, dim, X, N, c, cont+=1);
		}
	return N;
}

int main()
{
	const int dim = 9;
	int A[dim];
	int cont = 0, N = 0, X, c = 0;
	for( int i = 0; i < dim; i++)
		{
			cin>>A[i];
		}
	cin >> X;
	cout << ricorsiva_occorrenze( A, dim, X, N, c, cont);
	return 0;
}
