#include <iostream>
#include <cstring>
using namespace std;

bool Controlla_Schema( char A[], char B[], char C[], char Schema[], int dim_A, int dim_B, int dim_C)
{
    int cont_A = 0;
    int cont_B = 0;
    for( int i = 0; i < dim_C; i++)
    {
        if( Schema[i] == 'a')
        {
            if( A[cont_A] == C[i])
                cont_A++;
            else
                return false;
        }
        if( Schema[i] == 'b')
        {
            if( B[cont_B] == C[i])
                cont_B++;
            else
                return false;
        }
    }
    return true;
}

int main()
{
    const int a = 100;
    const int b = 100;
    const int c = 100;
    const int s = 100;
    char A[a];
    char B[b];
    char C[c];
    char Schema[s];
    cin.getline( A, a);
    cin.getline( B, b);
    cin.getline( C, c);
    cin.getline( Schema, s);
    const int dim_A = strlen( A);
    const int dim_B = strlen( B);
    const int dim_C = strlen( C);
    if( dim_C == dim_A + dim_B)
    {
        if( Controlla_Schema( A, B, C, Schema, dim_A, dim_B, dim_C))
            cout << C << " e' uno schema di " << A << " e " << B;
        else
            cout << C << " non e' uno schema di " << A << " e " << B;
    }
    else
        cout << C << " non puo' essere uno schema di " << A << " e " << B << " perche' la sua lunghezza " << dim_C << " non e' uguale a "
        << dim_A << " + " << dim_B;
    return 0;
}
