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
<<<<<<< HEAD
			*Dptr_iniziale++;
			*Dptr_finale--;
=======
			Dptr_iniziale++; 
			Dptr_finale--;
>>>>>>> 33266149011b7b7f41b9a6b528e6aada05d395d7
		}
	return true;
}

<<<<<<< HEAD
int main()
{
	const int dim = 6;
	int D[dim] = { 1, 2, 4, 3, 2, 1};
=======
int main() 
{	
	const int dim = 12;
	int D[dim] = { 1, 2, 3, 4, 5, 6, 6, 5, 4, 3, 2, 1};
>>>>>>> 33266149011b7b7f41b9a6b528e6aada05d395d7
	if (palindroma( D, dim))
		cout << "Palindroma";
	else
		cout << "Non Palindroma";
	return 0;
}
