#include <iostream>

using namespace std;
const int n = 10;
int Leggi(int[]);
void Prodotto(int[]);

int main()
{
    int V[n];
    Leggi(V);
    Prodotto(V);
}

int Leggi(int V[])
{
    for(int i=0; i<n; i++)
    {
        cin >> V[i];
    }
}

void Prodotto(int V[])
{
    int pos = 0;
    int index = 1;
    int indiceP = 0;
    int Pos[n];
    while(pos < n)
    {
        for(int i=index; i<n-1; i++)
        {
            if(V[pos] == (V[index]*V[i+1]))
            {
                cout << pos << " e " << index << " e " << i+1<<endl;
            }
        }
        index++;
        pos++;
    }

}
