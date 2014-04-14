#include <iostream>

using namespace std;
const int m = 4;
const int n = 5;
void LeggiMatrice(int[][n]);
int BandaPivot(int[][n]);
void BandaOrizzontale(int[][n],int&,int[],int&);


int main()
{
    int M[m][n];
    int dimV = 0;
    int V[n];
    LeggiMatrice(M);
    int pivot = BandaPivot(M);
    int index = pivot;
    BandaOrizzontale(M,dimV,V,index);

    cout << V[0];


}

void LeggiMatrice(int M[][n])
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> M[i][j];
        }
    }
}

int BandaPivot(int M[][n])
{
    bool procedi = true;
    int indice = 1;
    while(indice < m)
    {
        for(int i=0; i<n; i++)
        {
            if(M[0][i] != M[indice][i])
            {
                procedi = false;
            }
        }
        if(procedi)
        {
            indice++;
        }
        else
            return indice;
    }
    return indice;
}

void BandaOrizzontale(int M[][n],int& dimV,int V[],int &index)
{
    int contatore = 1;
    bool procedi = true;
    while(index < m-1)
    {
        for(int i=0;i<n;i++)
        {
            if(M[index][i] != M[index+1][i])
            {
                procedi = false;
            }
        }
        if(procedi)
        {
            contatore++;
            index++;
            BandaOrizzontale(M,dimV,V,index);
        }
        else
        {
            dimV++;
            V[dimV] = contatore;
        }
    }
}
