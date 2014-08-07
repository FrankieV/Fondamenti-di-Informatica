#include <iostream>
using namespace std;

void init_sequenza( int sequenza[], int dim_sequenza)
{
    int numero;
    for( int i = 0; i < dim_sequenza; i++)
        {
            cin >> numero;
            sequenza[i] = numero;
        }
}

bool picchi_ravvicinati( int A[], int dim, int index, int &cont_picchi)
{
    if( index < dim-1)
        {
            if(( A[index] > A[index-1]) && (A[index] > A[index+1]))
                return picchi_ravvicinati( A, dim, index += 2, cont_picchi += 1);
            else
                {
                    cont_picchi = -1;
                    return false;
                }
        }
    return true;
}

int main()
{
    const int dim = 9;
    int Sequenza[dim];
    init_sequenza( Sequenza, dim);
    int index = 1;
    int cont_picchi = 0;
    if(( picchi_ravvicinati( Sequenza, dim, index, cont_picchi)) == true)
        cout << "Serie di " << cont_picchi << " picchi ravvicinati";
    else
        cout << "Non vi e' una serie di picchi ravvicinati " << cont_picchi;
    return 0;
}
