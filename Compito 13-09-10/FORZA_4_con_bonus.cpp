#include <iostream>
using namespace std;


void Init_Matrice( int **Matrice, int N, int M)
{
    for( int i = 0; i < N; i++)
        {
            for( int j = 0; j < M; j++)
                Matrice[i][j] = 0;
        }
}

int Disponi_Pedine( int **Matrice, int N, int M, int pedina)
{
    int cont = 0;
    while(( Matrice[cont][M] == 0) && (cont < N-1))
        cont++;
    if( Matrice[cont][M] != 0)
        cont--;
    Matrice[cont][M] = pedina;
    return cont;
}

bool Vincitore_Verticale( int **Matrice, int N, int M, int pedina)
{
    int cont_pedina = 0;
    for( int i = 0; i < N; i++)
        {
            if( Matrice[i][M] == pedina)
                cont_pedina++;
            else
                cont_pedina = 0;
            if( cont_pedina == 4)
                return true;
        }
    return false;
}

bool Vincitore_Orizzontale( int **Matrice, int N, int M, int pedina)
{
    int cont_pedina = 0;
    for( int j = 0; j < M; j++)
        {
            if( Matrice[N][j] == pedina)
                cont_pedina++;
            else
                cont_pedina = 0;
            if( cont_pedina == 4)
                return true;
        }
    return false;
}

bool Vincitore_Diagonale( int **Matrice, int N, int M, int riga_pedina_giocatore, int mossa_giocatore, int pedina)
{
    int cont = 0;
    int cont_pedine = 0;
    if(( riga_pedina_giocatore > 2 && riga_pedina_giocatore < N - 3) && mossa_giocatore > 2)
        {
            while( cont < 4)
                {
                    if( Matrice[riga_pedina_giocatore+cont][mossa_giocatore-cont] == pedina)
                        cont_pedine++;
                    cont++;
                }
            if( cont_pedine == 4)
                return true;
            cont = 0;
            cont_pedine = 0;
        }
    if( mossa_giocatore < M - 4 && riga_pedina_giocatore < N - 4)
        {
            while( cont < 4)
                {
                    if( Matrice[riga_pedina_giocatore+cont][mossa_giocatore+cont] == pedina)
                        cont_pedine++;
                    cont++;
                }
            if( cont_pedine == 4)
                return true;
            cont = 0;
            cont_pedine = 0;
        }
    if( mossa_giocatore < M - 4 && riga_pedina_giocatore > 2)
        {
            while( cont < 4)
                {
                    if( Matrice[riga_pedina_giocatore-cont][mossa_giocatore+cont] == pedina)
                        cont_pedine++;
                    cont++;
                }
            if( cont_pedine == 4)
                return true;
            cont = 0;
            cont_pedine = 0;
        }
    if( riga_pedina_giocatore < N - 4 && mossa_giocatore > 2)
        {
            while( cont < 4)
                {
                    if( Matrice[riga_pedina_giocatore+cont][mossa_giocatore-cont] == pedina)
                        cont_pedine++;
                    cont++;
                }
            if( cont_pedine == 4)
                return true;
            cont = 0;
            cont_pedine = 0;
        }
    return false;
}

void Print_Matrice( int **Matrice, int N, int M)
{
    for( int i = 0; i < M; i++)
        cout << i << "  ";
    cout << endl << endl;
    for( int i = 0; i < N; i++)
        {
            for( int j = 0; j < M; j++)
                cout << Matrice[i][j] << "  ";
            cout << endl;
        }
}

bool nessuna_posizione_rimasta( int **Matrice, int N, int M)
{
    for( int i = 0; i < N; i++)
        {
            for( int j = 0; j < M; j++)
                {
                    if( Matrice[i][j] == 0)
                        return false;
                }
        }
    return true;
}

bool colonna_completata( int **Matrice, int N, int M)
{
    for( int i = 0; i < N; i++)
        {
            if( Matrice[i][M] == 0)
                return false;
        }
    return true;
}

int main ()
{
    int n, m;
    cin >> m >> n;
    const int M = m;
    const int N = n;
    bool pareggio = false;
    bool vince_il_primo_giocatore = false;
    bool vince_il_secondo_giocatore = false;
    bool nessuna_posizione = false;
    const int pedina_primo_giocatore = 1;
    const int pedina_secondo_giocatore = 2;
    int mossa_primo_giocatore;
    int mossa_secondo_giocatore;
    int riga_pedina_primo_giocatore;
    int riga_pedina_secondo_giocatore;
    int **Matrice = new int *[N];
    for( int i = 0; i < N; i++)
        Matrice[i] = new int [M];
    Init_Matrice( Matrice, N, M);
    Print_Matrice( Matrice, N, M);
    while(( pareggio != true) && ( vince_il_primo_giocatore != true) && ( vince_il_secondo_giocatore != true))
          {
                cout << endl << endl << "Primo giocatore : in quale colonna inserisci la pedina? " << endl << endl;
                cin >> mossa_primo_giocatore;
                if( colonna_completata( Matrice, N, mossa_primo_giocatore) == true)
                    {
                        while( colonna_completata( Matrice, N, mossa_primo_giocatore) == true)
                            {
                                cout << "Primo giocatore: colonna al completo, si prega di inserire la pedina in un'altra colonna. " << endl << endl;
                                cin >> mossa_primo_giocatore;
                            }
                    }
                riga_pedina_primo_giocatore = Disponi_Pedine( Matrice, N, mossa_primo_giocatore, pedina_primo_giocatore);
                if( Vincitore_Orizzontale( Matrice, riga_pedina_primo_giocatore, M, pedina_primo_giocatore) == true)
                        vince_il_primo_giocatore = true;
                if( Vincitore_Verticale( Matrice, N, mossa_primo_giocatore, pedina_primo_giocatore) == true)
                        vince_il_primo_giocatore = true;
                if( Vincitore_Diagonale( Matrice, N, M, riga_pedina_primo_giocatore, mossa_primo_giocatore, pedina_primo_giocatore) == true)
                        vince_il_primo_giocatore = true;
                cout << endl << endl <<  "Secondo giocatore : in quale riga inserisci la pedina? " << endl << endl;
                cin >> mossa_secondo_giocatore;
                if( colonna_completata( Matrice, N, mossa_secondo_giocatore) == true)
                    {
                        while( colonna_completata( Matrice, N, mossa_secondo_giocatore) == false)
                            {
                                cout << "Secondo giocatore: colonna al completo, si prega di inserire la pedina in un'altra colonna. " << endl << endl;
                                cin >> mossa_primo_giocatore;
                            }
                    }
                riga_pedina_secondo_giocatore = Disponi_Pedine( Matrice, N, mossa_secondo_giocatore, pedina_secondo_giocatore);
                if( Vincitore_Orizzontale( Matrice, riga_pedina_secondo_giocatore, M, pedina_secondo_giocatore) == true)
                        vince_il_secondo_giocatore = true;
                if( Vincitore_Verticale( Matrice, N, mossa_secondo_giocatore, pedina_secondo_giocatore) == true)
                        vince_il_secondo_giocatore = true;
                if( Vincitore_Diagonale( Matrice, N, M, riga_pedina_secondo_giocatore, mossa_secondo_giocatore, pedina_secondo_giocatore) == true)
                        vince_il_secondo_giocatore = true;
                nessuna_posizione = nessuna_posizione_rimasta( Matrice, N, M);
                if( (nessuna_posizione == true) && ( vince_il_primo_giocatore == false) && ( vince_il_secondo_giocatore == false))
                    pareggio = true;
                Print_Matrice( Matrice, N, M);
          }
    if( vince_il_primo_giocatore == true)
        cout << endl << endl << "Vince il primo giocatore " << endl << endl;
    else
        {
            if( vince_il_secondo_giocatore == true)
                cout << endl << endl << "Vince il secondo giocatore " << endl << endl;
            else
                {
                    if( pareggio == true)
                        cout << endl << endl << "PAREGGIO!" << endl << endl;
                }
        }
    return 0;
}
