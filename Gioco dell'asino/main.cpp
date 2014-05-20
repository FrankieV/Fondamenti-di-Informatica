#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;
const int m = 4;
const int n = 10;
void distribuisciCarte(bool [][n], bool[][n], int &, int &);

int main()
{
    srand(time(0));
    bool G1[m][n];
    bool G2[m][n];
    Inizializza(G1);
    Inizializza(G2);
    int cont_G1 = 0;
    int cont_G2 = 0;
    distribuisciCarte(G1,G2,cont_G1,cont_G2);
}

void distribuisciCarte(bool G1[][10], bool G2[][10], int &contG1, int &contG2)
{
    int conta_Nove = 1;
    while(contG1 < 20 )
    {
        int i = rand() % 5;
        int j = rand() % 11;
        G[i][j] = true;
        contG1++;
    }
}

void Inizializza(bool G[][n])
{
    for(int i = 0; i < m; i++)
    {
        for(int j=0; j < n; j++)
        {
            G[i][j] = false;
        }
    }
}
