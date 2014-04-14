#include <iostream>

using namespace std;
const int dim = 100;
int Leggi(int[],int);
int main()
{
    int V[dim];
    int dim_effettiva = Leggi(V,dim);
    cout << dim_effettiva;
}


int Leggi(int V[], int dim)
{
    int seq;
    cin >> seq;
    while(seq != -1)
    {
        for(int i=0; i<dim; i++)
        {
            V[i] = seq;
        }
        cin >> seq;
    }

    return i;

}

bool ControllaEsistenza(int V[],int dim, int seq)
{
    for(int i = 0; i<dim; i++)
    {
        if(V[i] == seq)
        {
            return true;
        }
        return false;
    }
}

