#include <iostream>

using namespace std;
void my_funct(int **, int, int );

int main()
{
    int a,b;
    cin >> a >> b;

    const int n = a;
    const int m = b;

    int ** matrice = new int *[n];

    for(int i =0; i<n; i++)
    {
        matrice[i] = new int[m];
    }

    my_funct(matrice,n,m);

    for(int i =0; i<n; i++)
    {
        for(int j =0; j < m; j++)
        {
            cout << matrice[i][j];
        }

        cout << endl;
    }

}

void my_funct(int ** M, int n, int m)
{
    for(int i =0; i<n; i++)
    {
        for(int j =0; j < m; j++)
        {
            M[i][j] = 0;
        }
    }
}
