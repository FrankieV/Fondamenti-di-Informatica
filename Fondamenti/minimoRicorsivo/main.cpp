#include <iostream>
#include <climits>

using namespace std;
const int n = 10;
int Leggi(int[]);
int minimoRicorsivo(int[],int);
int i = 0;

int main()
{
    int V[n];
    int dimV = Leggi(V);
    int minimo = minimoRicorsivo(V,dimV);
    cout << minimo;
    return 0;
}

int Leggi(int V[])
{
    int pos = 0;
    while(pos < n)
    {
        cin >> V[pos];
        pos++;
    }
    return pos;
}

int minimoRicorsivo(int V[],int dim)
{
    int minimo = V[i];
    while(i<dim-1)
    {
        if(V[i+1] < minimo)
        {
            minimo = V[i+1];
        }
        i++;
    }
    return minimo;
}
