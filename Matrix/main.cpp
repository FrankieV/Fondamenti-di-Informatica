/*

Esercizio 1. Si scriva in C++ una funzione che ricevuti come parametri un array di numeri interi e la sua dimensione
restituisca TRUE se nell’array sono presenti almeno tre elementi consecutivi uguali, e restituisca FALSE altrimenti.
ESEMPIO: Se l’array contenesse i seguenti numeri 3 2 2 2 2 4 3 3 1 5 la funzione dovrebbe restituire TRUE.

*/


#include <iostream>

using namespace std;
const int dim = 6;
int Leggi(int[]);
bool ElementiContigui(int[],int);

int main()
{
    int V[dim];
    int dim_array = Leggi(V);
    if(ElementiContigui(V,dim_array))
    {
        cout << "Ho trovato 3 elementi contigui" << endl;
    }
    else
    {
        cout << "Nessun elemento contiguo =(" << endl;
    }
}

int Leggi(int V[])
{
    int i = 0;
    int seq;
    cin >> seq;
    while(i<dim && seq!= -1)
    {
        V[i] = seq;
        i++;
        cin >> seq;
    }
    return i;
}

bool ElementiContigui(int V[],int dim)
{
    for(int i=0;i<dim;i++)
    {
        int a = V[i];
        int b = V[i+1];
        int c = V[i+2];
        cout << a << b << c << "pos " << i << endl;
        if(a == b && a == c)
        {
            return true;
        }
    }
    return false;
}

