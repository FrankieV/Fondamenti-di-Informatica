#include <iostream>

using namespace std;
const int dim = 7;
int Minimo_Ricorso(int [], int, int);

int main()
{
    int A[dim] = {3 , 5 , 2, 2, 4, 1 ,1};
    int minimo = A[0];
    int cont = 0;
    int Min = Minimo_Ricorso(A,cont,minimo);
    cout << Min;
}

int Minimo_Ricorso(int A[],int cont, int minimo)
{
    while(cont < dim)
    {
        if(A[cont] < minimo)
        {
            minimo=A[cont];
        }
        return Minimo_Ricorso(A,cont+=1,minimo);
    }

    return minimo;
}
