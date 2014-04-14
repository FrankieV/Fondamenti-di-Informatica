#include <iostream>
using namespace std;
const int n = 100;
void RicercaDoppi(int[],int);
int Posizione(int[],int);
bool Ricerca(int[],int);
void Cancella(int[],int&,int);
int leggi(int[]);
void stampa_array(int[],int);

int main()
{
    int V[n];
    int dim_array = leggi(V);
    RicercaDoppi(V,dim_array);
    while(Ricerca(V,dim_array))
    {
        int pos = Posizione(V,dim_array);
        if(pos != -1)
        {
            Cancella(V,dim_array,pos);
        }
    }
    stampa_array(V,dim_array);
    return 0;
}


int leggi(int V[])
{
    int seq = 0;
    int cont = 0;
    cin >> seq;
    while (seq!=-1 && cont<n)
    {
        V[cont]= seq;
        cont++;
        cin>>seq;
    }
    return cont;
}

void RicercaDoppi(int V[],int dim)
{
    int a = 0;
    int b = 1;
    while(b<dim)
    {
        for(; b<dim; b++)
        {
            if(V[a] == V[b])
            {
                V[b] = -1;
            }
        }
        a+=1;
        b= a+1;
    }
}

bool Ricerca(int V[],int dim)
{
    for(int i = 0; i<dim; i++)
    {
        if(V[i] == -1)
            return true;

    }
     return false;
}

int Posizione(int V[],int dim)
{
    for(int i=0; i<dim; i++)
    {
        if(V[i] == -1)
            return i;
    }
    return -1;
}

void Cancella(int V[],int &dim,int pos)
{
    if(pos>=0 && pos<dim)
    {
        for(int i=pos; i<dim-1; i++)
            V[i]=V[i+1];
    }
    dim--;
}

void stampa_array (int V[], int dim)
{
    for (int i=0; i<dim; i++)
        cout<<V[i]<<" ";
}


