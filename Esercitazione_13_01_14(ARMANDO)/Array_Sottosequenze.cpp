#include <iostream>
using namespace std;

void leggi_sequenza( int A[], int dim)
{
	int n, cont = 0;
	for( int i = 0; i < dim; i++)
		A[i] = -1;
	cin >> n;
	while( n != -1)
		{
			if( n % 5 != 0)
				 A[cont] = n;
			else 
				cont--;
			cin >> n;
			cont++;
		}
}

void scansiona_array( int A[], int dim)
{
	int cont = 0;
	for( int i = 0; i < dim && A[i] != -1; i++)
		{
			 while ( A[i] != 2 && A[i] != -1)
						{
						 cout << A[i] << " ";
	                	 i++;
						}
				  cout << endl;
		}
	for( int i = 0; i < dim; i++)
		{
			if( A[i] == 2)
				cout << i << " ";
		}
}

int main()
{
	const int dim = 100;
	int A[dim];
	leggi_sequenza( A, dim);
	scansiona_array( A, dim);
	return 0;

}
