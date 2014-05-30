#include <iostream>
using namespace std;

const int n = 100;
const int dim = 20;
bool penna_alzata = false;
int posJ = 0;
int posI = 0;

void init_Pavimento(int [][dim]);
int init_array(int []);
void Leggi_Comandi(int[], int, int[][dim]);
void visualizzaPavimento(int[][dim]);
void Est(int[][dim]);
void Ovest(int[][dim]);
void Nord(int[][dim]);
void Sud(int[][dim]);

int main()
{
    int M[dim][dim];
    int A[n];
    init_Pavimento(M);
    int dimA = init_array(A);
    Leggi_Comandi(A,dimA, M);
}

void init_Pavimento(int A[][dim])
{
    for(int i = 0; i < dim; i++)
    {
        for(int j = 0; j< dim; j++)
        {
            A[i][j] = 0;
        }
    }
}

int init_array(int A[])
{
    for(int i = 0; i<n; i++)
    {
        A[i] = 9;
    }

    int cont = 0;
    int seq;
    cin >> seq;
    while(seq != 9 && cont < n)
    {
        A[cont] = seq;
        cont++;
        cin >> seq;
    }

    return cont;
}

void Leggi_Comandi(int A[], int dimA, int M[][dim])
{
    for(int i = 0; i < dimA; i++)
    {
        switch(A[i])
        {
        case 1:
            penna_alzata = true;
            break;
        case 2:
            penna_alzata = false;
            break;
        case 3:
            Est(M);
            break;
        case 4:
            Ovest(M);
            break;
        case 5:
            Sud(M);
            break;
        case 6:
            Nord(M);
            break;
        case 7:
            visualizzaPavimento(M);
            break;
        }
    }
}

void Est(int M[][dim])
{
    int passi;
    cout << "passi? ";
    cin >> passi;
    if(posJ != dim)
    {
        if(passi<dim-posJ)
        {
            for(int j = posJ+1; j<= posJ + passi; j++)
            {
                if(penna_alzata == false)
                {
                    M[posI][j] = 1;
                }
            }

            posJ += passi;
        }
        else
        {
            for(int j= posJ +1; j < dim; j++)
            {
                if(penna_alzata == false)
                {
                    M[posI][j] = 1;
                }
            }

            posJ = dim-1;
        }
    }
}

void Ovest(int M[][dim])
{
    int passi;
    cout << "passi? ";
    cin >> passi;
    if(posJ != 0)
    {
        if(posJ - passi >= 0)
        {
            for(int j = posJ-1; j >= posJ - passi; j--)
            {
                if(penna_alzata == false)
                {
                    M[posI][j] = 1;
                }
            }

            posJ -= passi;
        }
        else
        {
            for(int j= posJ -1 ; j >= 0; j--)
            {
                if(penna_alzata == false)
                {
                    M[posI][j] = 1;
                }
            }

            posJ = 0;
        }
    }
}

void Nord(int M[][dim])
{
    int passi;
    cout << "passi? ";
    cin >> passi;
    if(posI != 0)
    {
        if(posI - passi >= 0)
        {
            for(int i = posI-1; i >= posI - passi; i--)
            {
                if(penna_alzata == false)
                {
                    M[i][posJ] = 1;
                }
            }

            posI -= passi;
        }
        else
        {
            for(int i= posI-1; i >= 0; i--)
            {
                if(penna_alzata == false)
                {
                    M[i][posJ] = 1;
                }
            }

            posI = 0;
        }
    }
}

void Sud(int M[][dim])
{
    int passi;
    cout << "passi? ";
    cin >> passi;
    if(posI != dim)
    {
        if(passi<dim-posI)
        {
            for(int i = posI+1; i<= posI + passi; i++)
            {
                if(penna_alzata == false)
                {
                    M[i][posJ] = 1;
                }
            }

            posI += passi;
        }
        else
        {
            for(int i= posI +1; i < dim; i++)
            {
                if(penna_alzata == false)
                {
                    M[i][posJ] = 1;
                }
            }

            posI = dim-1;
        }
    }
}

void visualizzaPavimento(int M[][dim])
{
    for(int i = 0; i < dim; i++)
    {
        for(int j= 0; j<dim; j++)
        {
            if(M[i][j] == 1)
            {
                cout << "*";
            }
            else
                cout << " ";
        }

        cout << endl;
    }
}
