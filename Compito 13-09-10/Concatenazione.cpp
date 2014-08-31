#include <iostream>
#include <cstring>
using namespace std;
bool Concatenazione( char A[], char B[], char C[], int dim_A, int dim_C, int cont, int cont_A, int cont_B)
{
    if( strlen( A) != strlen( B))
        return false;
    if( cont < dim_C - 2)
        {
            C[cont] = A[cont_A];
            C[cont+1] = B[dim_A - cont_B - 1];
            return Concatenazione( A, B, C, dim_A, dim_C, cont += 2, cont_A += 1, cont_B += 1);
        }
    return true;
}
int main( )
{
    const int dim = 100;
    char A[dim];
    char B[dim];
    char C[dim];
    cin.getline( A, dim);
    cin.getline( B, dim);
    const int dim_A = strlen( A);
    const int dim_B = strlen( B);
    const int dim_C = dim_A + dim_B + 1;
    int cont = 0;
    int cont_A = 0;
    int cont_B = 0;
    if(Concatenazione( A, B, C, dim_A, dim_C, cont, cont_A, cont_B))
        cout << "Ok " << C << endl;
    else
        cout << "no";
    return 0;
}
