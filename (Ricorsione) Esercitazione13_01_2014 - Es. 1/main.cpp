#include <iostream>

using namespace std;
const int n = 10; // This value can be changed
int minimoRicorsivo(int[],int,int);

int main()
{
    int A[n];
    for(int i = 0; i<n; i++)
    {
        cin >> A[i];
    }

    int Min = A[0];
    int index = 1;
    int minimo = minimoRicorsivo(A,Min,index);
    cout << minimo;
}

int minimoRicorsivo(int A[],int Min,int index)
{
    while(index < n)
    {
        if(A[index] < Min)
        {
            Min = A[index];
        }

        return minimoRicorsivo(A,Min,index+=1);
    }

    return Min;
}
