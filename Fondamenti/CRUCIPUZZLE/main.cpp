#include <iostream>

using namespace std;
const int m = 4;
const int n = 4;

void InsertMatrice(char[][n]);

int main()
{
    char A[m][n];
    InsertMatrice(A);

    for(int i = 0; i<m; i++)
    {
        for(int j = 0 ; j<n; j++)
        {
            cout << A[i][j];
        }

        cout << endl;
    }

}

void InsertMatrice(char A[][n])
{
    int cont = 0;
    while(cont < n)
    {
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
               cin >> A[i][j];
            }

            cont++;
        }

    }
}


