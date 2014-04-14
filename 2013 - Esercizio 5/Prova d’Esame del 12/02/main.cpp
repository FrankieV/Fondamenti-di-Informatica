#include <iostream>

using namespace std;
const int m = 4;
const int n = 5;
void LeggiMatrice(int[][n]);
void SommaMatrice(int [][n],int[][n]);

int main()
{
    int M[m][n];
    int S[m][n];
    LeggiMatrice(M);
    SommaMatrice(M,S);

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << S[i][j];
        }
        cout << endl;
    }
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

void SommaMatrice(int M[][n],int S[][n])
{
    int riga = 0;
    int colonna = 0;
    int somma = 0;
    while(riga < m)
    {
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i != riga && j != colonna)
                {
                    somma += M[i][j];
                }
            }
        }
        S[riga][colonna] = somma;
        somma = 0;
        colonna++;
      if(colonna == n)
      {
          colonna = 0;
          riga++;
      }

    }
}
