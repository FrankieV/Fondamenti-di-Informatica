#include <iostream>

using namespace std;
const int dim = 4;
void init_Tabellone(int[][dim]);
void Most_Wins(int[][dim],int[]);
void pt_Trasferta(int[][dim],int[]);
int Squadra_Vincitrice(int []);
int Ultima_Squadra(int[]);

int main()
{
    int Tabellone[dim][dim];
    int Punti_Squadre[dim];
    init_Tabellone(Tabellone);
    Most_Wins(Tabellone,Punti_Squadre);
    pt_Trasferta(Tabellone,Punti_Squadre);
    int winner = Squadra_Vincitrice(Punti_Squadre);
    int loser = Ultima_Squadra(Punti_Squadre);

    cout << "La squadra che ha totalizzato piu' punti e':  s" << winner << " con " << Punti_Squadre[winner] << " punti" << endl;
    cout << "La squadra che ha totalizzato meno punti e':  s" << loser << " con " << Punti_Squadre[loser] << " punti" << endl;

}

void init_Tabellone(int tabellone[][dim])
{
    for(int i = 0; i < dim; i++)
    {
        for(int j = 0; j < dim; j++)
        {
            tabellone[i][j] = -1;
        }
    }

    for(int i = 0; i < dim; i++)
    {
        for(int j = 0; j < dim; j++)
        {
                cin >> tabellone[i][j];
        }
    }
}

void Most_Wins(int tabellone[][dim], int pt_Squadre[])
{
    int cont = 0;
    int riga= 0;
    int cont_Max = 0;
    int pos = 0;
    int cont_pt = 0;
    int most_wins = 0;
    while(riga < dim)
    {
        for(int j = 0; j < dim; j++)
        {
            if(riga != j)
            {
                if(tabellone[riga][j] == 1)
                {
                    cont += tabellone[riga][j];
                    cont_pt += 3;
                }
                else if(tabellone[riga][j] == 0)
                {
                    cont_pt += 1;
                }
            }
        }

        pt_Squadre[pos] = cont_pt;
        if(cont > cont_Max)
        {
            most_wins = riga;
            cont_Max = cont;
        }

        cont = 0;
        riga++;
        cont_pt = 0;
        pos++;

    }

    cout << "Squadra con piu' vittorie in casa " << "s" << most_wins << endl;
}

void pt_Trasferta(int tabellone[][dim], int pt_Squadre[])
{
    int pos = 0;
    int cont_pt = 0;
    int colonna = 0;
    while(colonna < dim)
    {
        for(int i = 0; i < dim; i++)
        {
            if(colonna != i)
            {
                if(tabellone[i][colonna] == 2)
                {
                    cont_pt += 3;
                }
                else if(tabellone[i][colonna] == 0)
                {
                    cont_pt += 1;
                }
            }
        }

        pt_Squadre[pos] += cont_pt;
        pos++;
        colonna++;
        cont_pt = 0;
    }
}

int Squadra_Vincitrice(int pt_Squadre[])
{
    int squadra = 0;
    int cont_Max = pt_Squadre[0];
    for(int i = 0; i < dim; i++)
    {
        if(pt_Squadre[i] > cont_Max)
        {
            cont_Max = pt_Squadre[i];
            squadra = i;
        }
    }
    return squadra;
}

int Ultima_Squadra(int pt_Squadre[])
{
    int squadra = 0;
    int cont_Max = pt_Squadre[0];
    for(int i = 0; i < dim; i++)
    {
        if(pt_Squadre[i] < cont_Max)
        {
            cont_Max = pt_Squadre[i];
            squadra = i;
        }
    }
    return squadra;
}
