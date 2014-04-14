#include <iostream>

using namespace std;


int main()
{
    int dim;
    cin >> dim;
    const int n = dim;
    int M[n][n];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            M[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        M[i][n/2] = 1;
        M[n/2][i] = 1;


    }


for (int i = 0; i < n; i++)
{
    for(int j = 0; j<n; j++)
        cout<< M[i][j]<<" ";
    cout<<endl;
}
}

