#include <iostream>
using namespace std;

void Init_Array( int A[], int Dim_A)
{
    int numero;
    for( int i = 0; i < Dim_A; i++)
        {
            cin >> numero;
            A[i] = numero;
        }
}
bool Ricorsiva_Terne( int A[], int Dim_A, bool Prima_Volta, int index)
{
    if( index < Dim_A - 2)
        {
            if( Prima_Volta == true)
                {
                    if(( A[index] == A[index+2]) && ( A[index] > A[index+1]))
                            return Ricorsiva_Terne( A, Dim_A, Prima_Volta = false, index += 3);
                    else
                        return false;
                }
            else
                {
                    if(( A[index] > A[index-1]) && ( A[index+1] > A[index-2]))
                        {
                            if(( A[index] == A[index+2]) && ( A[index] > A[index+1]))
                                return Ricorsiva_Terne( A, Dim_A, Prima_Volta, index += 3);
                            else
                                return false;
                        }
                    else
                        return false;
                }
        }
    return true;
}

int main()
{
    int dim;
    cin >> dim;
    const int Dim_A = dim;
    int A[Dim_A];
    Init_Array( A, Dim_A);
    int Index = 0;
    bool Prima_Volta = true;
    if( Ricorsiva_Terne( A, Dim_A, Prima_Volta, Index))
        cout << "OK" << endl;
    else
        cout << "NO" << endl;
    return 0;

}
