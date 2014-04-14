#include <iostream>

using namespace std;
const int dim = 50;
int Leggi(int[]);
int ControllaZeri(int[],int);

int main()
{
    int V[dim];
    int X;
    cin >> X;
    int dimV = Leggi(V);
    int numZeri = ControllaZeri(V,dimV);
    if(numZeri >= X)
    {
        cout << "OK";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}

int Leggi(int V[])
{
    int pos = 0;
    int seq = 0;
    while(seq != -1 && pos < dim)
    {
        cin >> seq;
        V[pos] = seq;
        pos++;
    }

    return pos;
}

int ControllaZeri(int V[],int dim)
{
    int prec = 0;
    int succ = 0;
    int numZeri = 0;

    for(int i=0; i<dim; i++)
    {
        prec = V[i];
        succ =  V[i+1];
        if(prec == 0 && succ == 0)
        {
            numZeri+=2;
        }
    }
    return numZeri;

}
