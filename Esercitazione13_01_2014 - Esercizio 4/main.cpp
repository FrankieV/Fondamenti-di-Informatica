#include <iostream>

using namespace std;
const int m = 5;    // This value can be changed. Remember: m and n must be odd! m and n must have same value!
const int n = 5;    // This value can be changed. Remember: m and n must be odd! m and n must have same value!

void TriangoloA(int[][n]);
void TriangoloC(int[][n]);
void TriangoloB(int[][n]);
void TriangoloD(int[][n]);

int main()
{
    int A[m][n];

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    TriangoloA(A);
    TriangoloC(A);
    TriangoloB(A);
    TriangoloD(A);

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << A[i][j];
        }

        cout << endl;
    }
}

void TriangoloA(int A[][n])
{
    int counter = 1;
    for(int i = 0; i<n/2; i++)
    {
        for(int j=i+1; j < n-counter; j++)
        {
            A[i][j] = A[i][j] * 2;
        }
        counter++;
    }
}

void TriangoloC(int A[][n])
{
    int counter = 1;
    for(int j = 0; j< n/2; j++)
    {
        for(int i=j+1; i<n-counter; i++)
        {
            A[i][j] = A[i][j] * 4;
        }

        counter++;
    }

}

void TriangoloB(int A[][n])
{
    int counter = 1;
    int indice = 0;
    for(int i = n-1; i>n/2; i--)
    {
        for(int j=1+indice; j < n-counter; j++)
        {
            A[i][j] = A[i][j] * 3;
        }

        counter++;
        indice++;
    }
}

void TriangoloD(int A[][n])
{
    int counter = 1;
    int indice = 0;
    for(int j = n-1; j > n/2; j--)
    {
        for(int i=1+indice; i<n-counter; i++)
        {
           A[i][j] = A[i][j] * 5;
        }

        indice++;
        counter++;
    }

}
