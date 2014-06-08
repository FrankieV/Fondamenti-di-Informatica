#include <iostream>
using namespace std;

void init_array( int A[], int dim)
{
	int n;
	for( int i = 0; i < dim; i++)
		{
			cin >> n;
			A[i] = n;
		}
}

int minimo_ricorsivo( int A[], int dim, int min, int cont)
{
	while( cont < dim)
		{
			if( A[cont] < min)
				min = A[cont];
			return minimo_ricorsivo( A, dim, min, cont+=1);
		}
	return min;
}

int main() 
{
	int d, cont = 0;
	cout << "Inserire dim:" << endl;
	cin >> d;
	const int dim = d;
	int A[dim], min = A[0];
	init_array( A, dim);
	cout<< minimo_ricorsivo( A, dim, min, cont);
	return 0;
}
