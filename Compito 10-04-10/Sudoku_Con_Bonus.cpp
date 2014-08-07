#include <iostream>
using namespace std;

void init_matrix( int **Matrice, int dim_Matrice)
{
    for( int i = 0; i < dim_Matrice; i++)
        {
            for( int j = 0; j < dim_Matrice; j++)
                Matrice[i][j] = 0;
        }
}

bool Controlla_Posizioni_Libere( int **Matrice, int dim_Matrice, int &cont)
{
    cont = 0;
    for( int i = 0; i < dim_Matrice; i++)
        {
            for( int j = 0; j < dim_Matrice; j++)
                {
                    if( Matrice[i][j] == 0)
                        cont++;
                }
        }
    if( cont != 0)
        return true;
    else
        return false;
}

void Stampa_Matrice( int **Matrice, int dim_Matrice)
{
    for( int i = 0; i < dim_Matrice; i++)
        {
            for( int j = 0; j < dim_Matrice; j++)
                cout << Matrice[i][j] << " ";
            cout << endl;
        }
}

bool Controlla_Riga( int **Matrice, int dim_Matrice, int numero, int i)
{
    for( int j = 0; j < dim_Matrice; j++)
        {
            if( Matrice[i][j] == numero)
                {
                    cout << "Numero gia' presente nella riga " << i << endl;
                    return false;
                }
        }
    return true;
}

bool Controlla_Colonna( int **Matrice, int dim_Matrice, int numero, int j)
{
    for( int i = 0; i < dim_Matrice; i++)
        {
            if( Matrice[i][j] == numero)
                {
                    cout << "Numero gia' presente nella colonna " << j << endl;
                    return false;
                }
        }
    return true;
}

bool Controlla_Sottomatrice( int **Matrice, int numero, int i_iniziale, int i_finale, int j_iniziale, int j_finale)
{
    for( int i = i_iniziale; i < i_finale; i++)
        {
            for( int j = j_iniziale; j < j_finale; j++)
                if( numero == Matrice[i][j])
                    {
                        cout << "Numero gia' presente nella sottomatrice che va dall'indice riga: " << i_iniziale << endl;
                        cout << "all' indice riga: " << i_finale << endl;
                        cout << "E dall' indice colonna: " << j_iniziale << " all' indice colonna: " << j_finale << endl;
                        return false;
                    }
        }
    return true;
}

void Scansione_Indici( int i, int j, int &i_iniziale, int &i_finale, int &j_iniziale, int &j_finale, int dim_Matrice)
{
    int multiplo_i = 0;
    int multiplo_j = 0;
    int cont = 1;
    if( dim_Matrice % 3 == 0)
        {
            multiplo_i = 3;
            multiplo_j = dim_Matrice / 3;
        }
    else
        {
            if( dim_Matrice % 2 == 0)
            {
                multiplo_i = 2;
                multiplo_j = dim_Matrice / 2;
            }
        }
    if( i < multiplo_i)
        {
            i_iniziale = 0;
            i_finale = multiplo_i;
        }
    else
        {
            while(( multiplo_i * cont) <= i)
                {
                    i_iniziale = multiplo_i * cont;
                    cont++;
                }
            i_finale = multiplo_i * cont;
        }
    cont = 1;
    if( j < multiplo_j)
        {
            j_iniziale = 0;
            j_finale = multiplo_j;
        }
    else
        {
            while((multiplo_j * cont) <= j)
                {
                    j_iniziale = multiplo_j * cont;
                    cont++;
                }
            j_finale = multiplo_j * cont;
        }
}

int main()
{
    int dim;
    cin >> dim;
    const int dim_Matrice = dim;
    int i;
    int j;
    int i_iniziale = 0;
    int i_finale = 0;
    int j_iniziale = 0;
    int j_finale = 0;
    int cont = 0;
    int numero;
    int **Matrice = new int *[dim_Matrice];
    for( int i = 0; i < dim_Matrice; i++)
        Matrice[i] = new int[dim_Matrice];
    init_matrix( Matrice, dim_Matrice);
    while( Controlla_Posizioni_Libere( Matrice, dim_Matrice, cont) == true)
        {
            Stampa_Matrice( Matrice, dim_Matrice);
            cout << "Vi sono " << cont << " celle da riempire.";
            cout << " Quale posizione intendi riempire ? " << endl;
            cin >> i >> j;
            if( Matrice[i][j] == 0)
                {
                    cout << " Con quale numero? " << endl;
                    cin >> numero;
                    if( Controlla_Riga ( Matrice, dim_Matrice, numero, i))
                        {
                            if( Controlla_Colonna( Matrice, dim_Matrice, numero, j))
                                {
                                    Scansione_Indici( i, j, i_iniziale, i_finale, j_iniziale, j_finale, dim_Matrice);
                                    if( Controlla_Sottomatrice( Matrice, numero, i_iniziale, i_finale, j_iniziale, j_finale))
                                        Matrice[i][j] = numero;
                                }

                        }
                }
            else
                cout << "Posizione gia' occupata da :" << Matrice[i][j] << endl;

        }
    Scansione_Indici( i, j, i_iniziale, i_finale, j_iniziale, j_finale, dim_Matrice);
    return 0;
}
