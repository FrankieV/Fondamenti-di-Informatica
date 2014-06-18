#include <iostream>
using namespace std;

bool palindroma( int D[], int dim)
{
	int *Dptr_iniziale;
	int *Dptr_finale;
	Dptr_iniziale = D;
	Dptr_finale = D + (dim -1);
	for( int i = 0; i < dim; i++)
		{
			if( *Dptr_iniziale != *Dptr_finale)
				return false;
			*Dptr_iniziale++;
			*Dptr_finale--;
		}
	return true;
}

int main()
{
	const int dim = 6;
	int D[dim] = { 1, 2, 4, 3, 2, 1};
	if (palindroma( D, dim))
		cout << "Palindroma";
	else
		cout << "Non Palindroma";
	return 0;
}
