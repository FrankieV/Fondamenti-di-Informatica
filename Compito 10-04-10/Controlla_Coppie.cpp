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
bool Controlla_Coppie( int A[], int dim_A, int index)
{
    if( index < dim_A-2)
    {
        if(( A[index] == A[index+2]) || (A[index+1] == A[index+2]) || (A[index] == A[index+3]) || (A[index+1] == A[index+3]))
            return Controlla_Coppie( A, dim_A, index += 2);
        else
            return false;
    }
    return true;
}

int main()
{
    const int dim = 12;
    int index = 0;
    int A[dim];
    init_array( A, dim);
    if( Controlla_Coppie( A, dim, index))
        cout << "Ogni coppia ha un elemento comune con quella precedente e con quella successiva";
    else
        cout << "Non tutte le coppie hanno un elemento comune con le coppie precedenti e con quelle successive";
    return 0;
}
