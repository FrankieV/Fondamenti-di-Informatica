#include <iostream>
using namespace std;

void tripla( int A[], int dim, int prodotto, int contp, int conts)
	{
		while( prodotto < dim)
			{
				if( conts == dim)
					{
						conts = 0;
						return tripla( A, dim, prodotto, contp += 1, conts);
					}
				if( contp == dim)
					{
						contp = 0;
						return tripla( A, dim, prodotto += 1, contp, conts);
					}
				if(( contp != prodotto) && (conts != prodotto) && (contp != conts))
					{
						if( A[prodotto] == A[contp] * A[conts])
							{
								cout << prodotto << " " << contp << " " << conts;
								break;
							}
					}
				return tripla( A, dim, prodotto, contp, conts += 1);
			}
	}

int main(int argc, char** argv) 
{
	const int dim = 10;
	int prodotto = 0;
	int contp = prodotto + 1;
	int conts = contp + 1;
	int A[dim] = { 1, 8, 4, 3, 2, 6, 5, 9, 10, 11};
	tripla( A, dim, prodotto, contp, conts);
	return 0;
}
