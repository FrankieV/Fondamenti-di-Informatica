#include <iostream>

using namespace std;



int main()
{
    int n;
    cin >> n;
    if(n % 2 == 0)
    {
        return 0;
    }
    int M[n][n];

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            M[i][j] = 0;
        }
    }

    int cont = 0;
    for(int i = 0; i <= n/2; i++)
    {
        for(int j = n/2 - cont ; j <= n/2 + cont; j++)
        {
            M[i][j] = 1;
        }

        cont++;
    }

    cont = 0;
    for(int i = n-1; i > n/2; i--)
    {
        for(int j = n/2 - cont ; j <= n/2 + cont; j++)
        {
            M[i][j] = 1;
        }

        cont++;
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cout <<  M[i][j] <<" ";
        }

        cout << endl;
    }

    return 0;
}
