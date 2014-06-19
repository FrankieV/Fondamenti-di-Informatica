#include <iostream>

using namespace std;
const int righe = 6;
const int colonne = 7;
void LeggiMatrice(int[][colonne]);
void BandaOrizzontale(int[][colonne]);


int main()
{
    int M[righe][colonne];
    LeggiMatrice(M);
    BandaOrizzontale(M);

}

void LeggiMatrice(int M[][colonne])
{
    for(int i=0; i<righe; i++)
    {
        for(int j=0; j<colonne; j++)
        {
            cin >> M[i][j];
        }
    }
}

void BandaOrizzontale(int M[][colonne])
{
    int A[righe];
    bool diversi = false;
    int pos_I = 1;
    int cont = 0;
    int dim_Bande = 1;
    int dimensioni_bande[righe] = {0};

    for(int j = 0; j < colonne; j++)
    {
        A[j] = M[0][j];
    }

    while(pos_I < righe)
    {
        for(int j=0; j<colonne; j++)
        {
            if(M[pos_I][j] != A[j])
            {
                diversi = true;
            }
        }

        if(diversi)
        {
            for(int j = 0; j < colonne; j++)
            {
                A[j] = M[pos_I][j];
            }

            diversi = false;
            dimensioni_bande[cont] = dim_Bande;
            cont++;
            dim_Bande = 0;
        }

        pos_I++;
        dim_Bande++;

    }

    dimensioni_bande[cont] = dim_Bande;

    for(int j = 0; j < righe; j++)
    {
        cout << dimensioni_bande[j];
    }
}
