#include <iostream>
using namespace std;
const int n = 5;

void ModificaTriangoli( int M[][n], int N[][n])
{
	if( n % 2 != 0)
		{
			for( int i = 0; i < n; i++)
				{
					for( int j = 0; j < n; j++)
						{
							if((i!=j) && ((i+j) != (n-1)))
								{
									if( (i + j) < n )
									{
										if( i < j)
											N[i][j] = M[i][j]*2;
										if( j < i)
												N[i][j] = M[i][j]*4;
									}
									if( i +j > n - 1)
										{	
											if( j < i)
												N[i][j] = M[i][j]*3;
											if( j > i)
												N[i][j] = M[i][j]*5;
											
										}
									if(((i +j)) > n && i < j)
										N[i][j] = M[i][j]*5;
									
								}
							else
								N[i][j] = M[i][j];
						}
				}
		}
}

int init_matrice( int M[][n])
{
	for( int i = 0; i < n; i++)
		{
			for( int j = 0; j < n; j++)
				{
					cin >> M[i][j];
				}	
		}
}

int main(int argc, char** argv) 
{
	int A[n][n];
	
	int B[n][n];
	init_matrice(A);
	for( int i = 0; i < n; i++)
		{
			for( int j = 0; j < n; j++)
				{
					cout << A[i][j] << " ";
				}	
			cout << endl;
		}
	cout << endl;
	ModificaTriangoli( A, B);
	for( int i = 0; i < n; i++)
		{
			for( int j = 0; j < n; j++)
				{
					cout << B[i][j] << " ";
				}	
			cout << endl;
		}
}
