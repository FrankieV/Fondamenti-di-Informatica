#include <iostream>
#include <cstring>

using namespace std;
const int m = 5;
const int n = 5;

void InsertMatrice(char[][n]);
void CercaParola(char[][n]);
bool Nord(char[][n],int,int);
bool Sud(char[][n],int,int);
bool Est(char[][n],int,int);
bool Ovest(char[][n],int,int);

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
    bool entrato = false;
    cin >> Parola;


    for(int i = 0; i < m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(Parola[0] == A[i][j] && entrato == false)
                {
                if(Nord(A,i,j))
                {
                    cout << "Coordinate: (" << i << " " << j << ") N" << endl;
                    entrato = true;
                }
                if (Sud(A,i,j))
                {
                     cout << "Coordinate: (" << i << " " << j << ") S" << endl;
                     entrato = true;
                }
                if(Est(A,i,j))
                {
                     cout << "Coordinate: (" << i << " "  << j << ") E" << endl;
                     entrato = true;
                }
                if(Ovest(A,i,j))
                {
                    cout << "Coordinate: (" << i << " " << j << ") O" << endl;
                    entrato = true;
                }
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
    int index = 1;
    if(riga != n-1)
    {
        for(int i = riga+1; i<n; i++)
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

bool Est(char A[][n],int riga,int colonna)
{
    int index = 1;
    if(colonna != n-1)
    {
        for(int i = colonna+1; i<n; i++)
        {
            if(Parola[index] == A[riga][i])
            {
                index++;
            }

        }

        if(index == strlen(Parola))
            return true;
    }

    return false;
}

bool Ovest(char A[][n],int riga,int colonna)
{
    int index = 1;
    if(colonna != 0)
    {
        for(int i = colonna-1; i>=0; i--)
        {
            if(Parola[index] == A[riga][i])
            {
                index++;
            }

        }

        if(index == strlen(Parola))
            return true;
    }

    return false;
}

