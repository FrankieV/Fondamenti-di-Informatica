#include <iostream>
#include <cstring>

using namespace std;
const int m = 4;
const int n = 4;

void InsertMatrice(char[][n]);
void CercaParola(char[][n]);
bool Nord(char[][n],int,int);
bool Sud(char[][n],int,int);

char Parola[5];

int main()
{
    char A[m][n];
    InsertMatrice(A);
    CercaParola(A);
}

void InsertMatrice(char A[][n])
{
    int cont = 0;
    while(cont < n)
    {
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                cin >> A[i][j];
            }

            cont++;
        }

    }
}

void CercaParola(char A[][n])
{

    cin >> Parola;


    for(int i = 0; i < m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(Parola[0] == A[i][j])
            {
                if(Nord(A,i,j))
                {
                    cout << "Coordinate: (" << i << " " << j << ") N";
                }
                else if (Sud(A,i,j))
                {
                    //
                }
//               Est(A,i,j);
//               Ovest(A,i,j);
            }
        }
    }

}

bool Nord(char A[][n],int riga,int colonna)
{
    int index = 1;
    if(riga != 0)
    {
        for(int i = riga-1; i>=0; i--)
        {
            if(Parola[index] == A[i][colonna])
            {
                index++;
            }

        }

        if(index == strlen(Parola))
            return true;
    }

    return false;
}

bool Sud(char A[][n],int riga,int colonna)
{
    //
}


