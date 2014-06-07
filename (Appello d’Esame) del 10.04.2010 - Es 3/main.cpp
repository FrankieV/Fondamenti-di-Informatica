#include <iostream>

using namespace std;
const int dim = 4;
void stampa_Griglia(int[][dim]);
int Controlla_Colonna(int[][dim],int,int,int);
int Controlla_Riga(int[][dim],int,int,int);
void insert_Number(int[][dim]);
void init_Griglia(int[][dim]);

int main()
{
    int Griglia[dim][dim];
    init_Griglia(Griglia);
    insert_Number(Griglia);
}

void init_Griglia(int M[][dim])
{
    for(int i = 0; i < dim; i++)
    {
        for(int j = 0; j < dim; j++)
        {
            M[i][j] = 0;
        }
    }
}

void insert_Number(int M[][dim])
{
    int num_inseriti = 0;
    while(dim*dim-num_inseriti > 0)
    {
        stampa_Griglia(M);
        cout << endl;
        int seq, i, j = 0;
        int riga, colonna = -1;
        cout << "Ti restano da riempire " << dim*dim-num_inseriti << " celle" << endl;
        cout << "Inserisci, rispettivamente, la riga e la colonna che vuoi riempire" << endl;
        cin >> i >> j;
        if(i < dim && j < dim)
        {
            cout << "Immetti il numero che vuoi inserire nella riga " << i << " colonna " << j << endl;
            cin >> seq;
            if(seq != 0 && seq <= 9)
            {
                riga = Controlla_Riga(M,seq,i,j);
                colonna = Controlla_Colonna(M,seq,i,j);
                if(riga == -1 && colonna == -1)
                {
                    if(M[i][j] == 0)
                    {
                        M[i][j] = seq;
                        num_inseriti++;
                    }
                }

                if(riga != -1)
                {
                    cout << "Attenzione, numero ripetuto nella riga " << riga << endl;
                }

                if(colonna != -1)
                {
                    cout << "Attenzione, numero ripetuto nella colonna " << colonna << endl;
                }
            }
        }

        riga = -1;
        colonna = -1;
    }

    stampa_Griglia(M);
}

int Controlla_Riga(int M[][dim], int seq, int posI, int posJ)
{
    for(int j=0; j < dim; j++)
    {
        if(j != posJ)
        {
            if(M[posI][j] == seq)
            {
                return posI;
            }
        }
    }

    return -1;
}

int Controlla_Colonna(int M[][dim], int seq, int posI, int posJ)
{
    for(int i=0; i < dim; i++)
    {
        if(i != posI)
        {
            if(M[i][posJ] == seq)
            {
                return posJ;
            }
        }
    }

    return -1;
}

void stampa_Griglia(int M[][dim])
{
    for(int i = 0; i < dim; i++)
    {
        for(int j = 0; j < dim; j++)
        {
            cout << M[i][j];
        }

        cout << endl;
    }
}
