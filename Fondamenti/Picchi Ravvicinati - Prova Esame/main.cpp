#include <iostream>

using namespace std;
const int n = 9;
bool PiccoRavvicinato(int[],int,int,int);
void Leggi(int[]);

int main()
{
    int V[n];
    int prec = 0;
    int corr = 1;
    int succ = 2;
    Leggi(V);
    if(PiccoRavvicinato(V, prec, corr, succ))
    {
        cout << "La funzione ha tutti i picchi ravvicinati";
    }
    else
    {
        cout << "La funzione presenta almeno un picco NON ravvicinato";
    }
}

void Leggi(int V[])
{
    for(int i=0; i<n; i++)
    {
        cin >> V[i];
    }
}

bool PiccoRavvicinato(int V[],int prec,int corr,int succ)
{
    while(succ < n-2)
    {
        if(V[corr] > V[prec] && V[corr] > V[succ])
        {
            return PiccoRavvicinato(V,prec+2,corr+2,succ+2);
        }
        else
        {
            return false;
        }
    }
return true;
}
