#include <iostream>
using namespace std;
const int n = 9;
int VerificaOccorrenza(int[], int,int);

int main()
{
    int A[n];
    int X;
    int C = 0;
    cin >> X;
    for(int i = 0; i<n; i++)
    {
        cin >> A[i];
    }

    int a = VerificaOccorrenza(A,X,C);
    cout << a;

}

int VerificaOccorrenza(int A[], int X,int C)
{
    int num_presenze = 0;

    while(X != 0)
    {
        for(int i=0; i<n; i++)
        {
            if(A[i] == X)
            {
                A[i] = 0;
                num_presenze++;
            }
        }
        return VerificaOccorrenza(A,X=num_presenze,C+=num_presenze);

    }

    return C;
}
