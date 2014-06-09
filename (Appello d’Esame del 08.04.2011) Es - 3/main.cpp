#include <iostream>

using namespace std;


const int n = 5;
const int m = 9;

void init_Matrice(int[][m]);
bool Regioni(int[][m]);
void init_array(int[],int[]);


int main()
{
    int M[n][m];
    init_Matrice(M);
    if(Regioni(M))
    {
        cout << "OK";
    }
    else
    {
        cout << "NO";
    }
}

void init_Matrice(int M[][m])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++ )
        {
            cin >> M[i][j];
        }
    }
}

bool Regioni(int M [][m])
{
    int colonna = 0;
    int regione_sup[n*m];
    int regione_inf[n*m];
    int pos_sup = 0;
    int pos_inf = 0;
    init_array(regione_sup,regione_inf);

    while(colonna < m)
    {
        for(int i = 0; i < n; i++)
        {
            if(M[i][colonna] != 0)
            {
                regione_sup[pos_sup] = M[i][colonna];
                pos_sup++;
            }
            else
                break;
        }

        for(int i = n-1; i >=0; i--)
        {
            if(M[i][colonna] != 0)
               {
                   regione_inf[pos_inf] = M[i][colonna];
                   pos_inf++;
               }
            else
                break;
        }

        colonna++;
    }

    int Max = regione_sup[0];
    int Min = regione_sup[0];
    int index = 0;
    while(regione_sup[index] != 0)
    {
        if(regione_sup[index] > Max )
        {
            Max = regione_sup[index];
        }

        if(regione_sup[index] < Min )
        {
            Min = regione_sup[index];
        }

        index++;
    }

    int diff = Max - Min;
    int pos = 0;
    int media = 0;
    int somma = 0;

    while(regione_inf[pos] != 0)
    {
        somma += regione_inf[pos];
        pos++;
    }

    media = somma / pos;

    cout <<endl << "La media e': " << media << endl;
    cout << "La differenza e': " << diff << endl;

    if(diff == media)
        return true;
    else
        return false;



}

void init_array(int reg_sup[],int reg_inf[])
{
    for(int i = 0; i < m*n; i++)
    {
        reg_sup[i] = 0;
        reg_inf[i] = 0;
    }
}

