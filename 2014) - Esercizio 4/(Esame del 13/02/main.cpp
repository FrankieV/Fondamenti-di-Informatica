#include <iostream>

using namespace std;
bool Accoppiate(int ** A, int ** B, int m, int n, int k, int posA_I,int posB_I,int posA_J,int posB_J,bool uguali, int somma);

int main()
{
    int m,n,k;
    int posA_I = 0;
    int posB_I = 0;
    int posA_J = 0;
    int posB_J = 0;
    bool uguali = true;
    int somma = 0;
    cin >> m >> n >> k;

    int ** A = new int *[m];
    for(int i = 0; i < n; i++)
    {
        A[i] = new int[n];
    }

    int **B = new int *[n];
    for(int i = 0; i < k; i++)
    {
        B[i] = new int[k];
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
        {
            cin >> B[i][j];
        }
    }

    if(Accoppiate(A,B,m,n,k,posA_I,posB_I,posA_J,posB_J,uguali,somma))
    {
        cout << "Matrici accoppiate";
    }
    else
    {
        cout << "Matrici non accoppiate";
    }

}

bool Accoppiate(int ** A, int ** B, int m, int n, int k, int posA_I,int posB_I,int posA_J,int posB_J,bool uguali, int somma)
{
    while(posA_I < m)
    {
        while(posB_J < k)
        {
            while(posB_I < n)
            {
                if(A[posA_I][posA_J] != B[posB_I][posB_J])
                {
                    uguali = false;
                }

                posB_I += 1;
                posA_J += 1;
            }

            if(uguali)
            {
                int index = 0;
                while(index < n)
                {
                    B[index][posB_J] = 0;
                    index++;
                }
            }

            return Accoppiate(A,B,m,n,k,posA_I,posB_I=0,posA_J=0,posB_J+=1,uguali=true,somma);
        }
        return Accoppiate(A,B,m,n,k,posA_I+=1,posB_I=0,posA_J=0,posB_J=0,uguali=true,somma);
    }


    while(posB_J < k)
    {
        while(posB_I < n)
        {
            somma += B[posB_I][posB_J];
            posB_I++;
        }
        return Accoppiate(A,B,m,n,k,posA_I,posB_I=0,posA_J,posB_J+=1,uguali,somma);
    }

    if(somma != 0)
    {
        cout << "Fattore di disturbo " << somma << endl;
        return false;
    }
    else
    {
        cout << "Fattore di disturbo " << somma << endl;
        return true;
    }

}
