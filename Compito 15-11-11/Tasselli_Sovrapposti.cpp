#include <iostream>
using namespace std;

void init_array( int A[], int dim)
{
	int numero;
	for( int i = 0; i < dim; i++)
		{
			cin >> numero;
			A[i] = numero;
		}
}

bool tasselli_sovrapposti(int A[], int somma[], int N, int dim_som, int c,  int d, int e)
{
			if(( N % 3) == 0)
			 {
			 	while( d < N)
			 		{
						if( A[c] == A[d])
			 					{
			 						A[d] = A[c] + A[d];
									somma[e] = A[d];
			 					}
			 			else 
			 				return false;
						if( c % 3 == 0)
			 				{
			 					c = d;
			 					e = 0;
			 					return tasselli_sovrapposti( A, somma, N, dim_som, c, d += 1, e);
			 				}
			 			return tasselli_sovrapposti( A, somma, N, dim_som,  c -= 1, d += 1, e += 1);
			 		}	
			 	return true;
			}
			 else 
			 	return false;
}
int main() 
{
	int dim;
	cin >> dim;
	const int N = dim;
	const int dim_som = 3;
	int Somma[dim_som];
	int A[N];
	int d = dim_som;
	int c = dim_som - 1;
	int e = 0;
	init_array( A, dim);
	if( tasselli_sovrapposti(A, Somma, N, dim_som, c, d, e))
 		 {	
 			cout << "Tasselli Sovrapposti \n";
 			for( int i = 0; i < dim_som; i++)
 				cout << Somma[i] << " ";
		 }
	 else 
		cout <<"Tasselli non Sovrapposti \n"; 	
	return 0;
}
