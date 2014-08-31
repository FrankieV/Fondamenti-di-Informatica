#include <iostream>
#include <cstring>
using namespace std;

void Init_Mare( char **Mare, int N, int M)
{
    for( int i = 0; i < N; i++)
        {
            for( int j = 0; j < M; j++)
                Mare[i][j] = ' ';
        }
}

void Inserisic_Tipo_Nave( int &num_sommergibili, int &num_vedette, int &num_incrociatori, int &num_portaerei, int &Lunghezza_Imbarcazione)
{
    char Imbarcazione[100];
    bool imbarcazione_scelta = false;
    char Sommergibile[13]= {'s','o','m','m','e','r','g','i','b','i','l','e', '\0'};
    char Vedetta[8] = { 'v','e','d','e','t','t','a','\0'};
    char Incrociatore[13] = {'i', 'n', 'c', 'r', 'o', 'c', 'i', 'a', 't', 'o', 'r', 'e', '\0'};
    char Portaerei[10] = {'p', 'o', 'r', 't', 'a', 'e', 'r', 'e', 'i', '\0'};
    cout << "Numero barche a disposizione: " << endl;
    cout << "-" << num_sommergibili << " sommergibile" << endl;
    cout << "-" << num_vedette << " vedetta" << endl;
    cout << "-" << num_incrociatori << " incrociatore" << endl;
    cout << "-" << num_portaerei << " portaerei" << endl;
    cout << "Cosa vuoi disporre? " << endl;
    cin.getline( Imbarcazione, 100);
    cin.getline( Imbarcazione, 100);
    while( imbarcazione_scelta == false)
        {
            if( strcmp( Imbarcazione, Sommergibile) == 0 && num_sommergibili != 0)
                {
                    num_sommergibili--;
                    Lunghezza_Imbarcazione = 1;
                    imbarcazione_scelta = true;
                }
            else
                {
                    if( strcmp( Imbarcazione, Vedetta) == 0 && num_vedette != 0)
                        {
                            num_vedette--;
                            Lunghezza_Imbarcazione = 2;
                            imbarcazione_scelta = true;
                        }
                    else
                        {
                            if( strcmp( Imbarcazione, Incrociatore) == 0 && num_incrociatori != 0)
                                {
                                    num_incrociatori--;
                                    Lunghezza_Imbarcazione = 3;
                                    imbarcazione_scelta = true;
                                }
                            else
                                {
                                    if( strcmp( Imbarcazione, Portaerei) == 0 && num_portaerei != 0)
                                        {
                                            num_portaerei--;
                                            Lunghezza_Imbarcazione = 4;
                                            imbarcazione_scelta = true;
                                        }
                                    else
                                        {
                                            cout << "Imbarcazione scelta al completo, scegli un altro tipo di imbarcazione " << endl;
                                            cin.getline( Imbarcazione, 100);
                                        }
                                }
                        }
                }

        }
}

bool Controlla_Coordinate_Correnti( char **Mare, int N, int M, int x, int y)
{
    if( x > 0 )
        {
            if( Mare[x-1][y] == '*')
                return false;
        }
    if( y > 0)
        {
            if( Mare[x][y-1] == '*')
                return false;
        }
    if( x < N - 1 && y > 0)
        {
            if( Mare[x+1][y-1] == '*')
                return false;
        }
    if( x > 0 && y > 0)
        {
            if( Mare[x-1][y-1] == '*')
                return false;
        }
    if( x > 0 && y < M - 1)
        {
            if( Mare[x-1][y+1] == '*')
                return false;
        }
    if( x < N - 1 && y < M - 1)
        {
            if( Mare[x+1][y+1] == '*')
                return false;
        }
    if( y < M - 1)
        {
            if( Mare[x][y+1] == '*')
                return false;
        }
    if( x < N - 1)
    {
        if( Mare[x+1][y] == '*')
            return false;
    }
    return true;
}
bool Bussola( char **Mare, int N, int M, int Lunghezza_Imbarcazione, int x, int y)
{
    bool nord = true;
    bool sud = true;
    bool ovest = true;
    bool est = true;
    if( Lunghezza_Imbarcazione > 1 && x == 0)
        nord = false;
    if( Lunghezza_Imbarcazione > 1 && x == N - 1)
        sud = false;
    if( Lunghezza_Imbarcazione > 1 && y == 0)
        ovest = false;
    if( Lunghezza_Imbarcazione > 1 && y == M - 1)
        est = false;
    for( int i = 0; i < Lunghezza_Imbarcazione; i++)
        {
            if( x < N - Lunghezza_Imbarcazione)
                {
                    if( Mare[x+i][y] == '*')
                        sud = false;
                    if( Controlla_Coordinate_Correnti( Mare, N, M, x+i, y) == false)
                        sud = false;
                }
            else
                sud = false;
            if( x >= Lunghezza_Imbarcazione - 1)
                {
                    if( Mare[x-i][y] == '*')
                        nord = false;
                    if( Controlla_Coordinate_Correnti( Mare, N, M, x-i, y) == false)
                        nord = false;
                }
            else
                nord = false;
            if( y < M - Lunghezza_Imbarcazione)
                {
                    if( Mare[x][y+i] == '*')
                        est = false;
                    if( Controlla_Coordinate_Correnti( Mare, N, M, x, y+i) == false)
                        est = false;
                }
            else
                est = false;
            if( y >= Lunghezza_Imbarcazione - 1 )
                {
                    if ( Mare[x][y-i] == '*')
                        ovest = false;
                    if( Controlla_Coordinate_Correnti( Mare, N, M, x, y-i) == false)
                        ovest = false;
                }
            else
                ovest = false;
        }
    if( Lunghezza_Imbarcazione > 1) //&& (nord == true || sud == true || est == true || ovest == true))
        {
            cout << "Con queste coordinate ti puoi muovere verso: " << endl;
            if( nord == true)
                cout << "- Nord " << endl;
            if( sud == true)
                cout << "- Sud " << endl;
            if( est == true)
                cout << "- Est " << endl;
            if( ovest == true)
                cout << "- Ovest " << endl;
            return true;
        }
    else
        return false;
}

void Posiziona_Verso_Nord( char **Mare, int Lunghezza_Imbarcazione, int x, int y)
{
    for( int i = 0; i < Lunghezza_Imbarcazione; i++)
        Mare[x-i][y] = '*';
}

void Posiziona_Verso_Sud( char **Mare, int Lunghezza_Imbarcazione, int x, int y)
{
    for( int i = 0; i < Lunghezza_Imbarcazione; i++)
        Mare[x+i][y] = '*';
}

void Posiziona_Verso_Est( char **Mare, int Lunghezza_Imbarcazione, int x, int y)
{
    for( int i = 0; i < Lunghezza_Imbarcazione; i++)
        Mare[x][y+i] = '*';
}

void Posiziona_Verso_Ovest( char **Mare, int Lunghezza_Imbarcazione, int x, int y)
{
    for( int i = 0; i < Lunghezza_Imbarcazione; i++)
        Mare[x][y-i] = '*';
}

void Print_Mare( char **Mare, int N, int M)
{
    cout << "  ";
    for( int i = 0; i < M; i++)
        cout << "  " <<  i << " ";
    cout << endl;
    for( int i  = 0; i < N; i++)
        {
            cout << i << " |";
            for( int j = 0; j < M; j++)
                cout << " " << Mare[i][j] << " |";
            cout << endl;
        }
}

void Distribuisci_Navi( char **Mare, int N, int M)
{
    char Nord[5] = { 'n', 'o', 'r', 'd', '\0'};
    char Sud[4] = { 's', 'u', 'd', '\0'};
    char Est[4] = { 'e', 's', 't', '\0'};
    char Ovest[6] = { 'o', 'v', 'e','s', 't', '\0'};
    char Posizione[6];
    int num_sommergibili = 4;
    int num_vedette = 3;
    int num_incrociatori = 2;
    int num_portaerei = 1;
    int Lunghezza_Imbarcazione;
    int x, y;
    while( num_sommergibili + num_vedette + num_incrociatori + num_portaerei != 0)
        {
            Inserisic_Tipo_Nave( num_sommergibili, num_vedette, num_incrociatori, num_portaerei, Lunghezza_Imbarcazione);
            cout << "Ok!!... =)... hai scelto un' imbarcazione di lunghezza " << Lunghezza_Imbarcazione << " dove vuoi posizionarla?" <<endl;
            cout << "Inserisci le coordinate ( x,y) " << endl;
            cin >> x >> y;
            if( Mare[x][y] == '*' )
                {
                    while( Mare[x][y] != ' ')
                        {
                            cout << "Posizione occupata da un'altra imbarcazione, reinserire le coordinate (x, y) " << endl;
                            cin >> x >> y;
                        }
                }
            if( Controlla_Coordinate_Correnti( Mare, N, M, x, y) == false)
                {
                    while( Controlla_Coordinate_Correnti( Mare, N, M, x, y) != true)
                        {
                            cout << "Attenzione le barche cosi toccano, reinserire le coordinate (x, y) " << endl;
                            cin >> x >> y;
                        }
                }
            if( Bussola( Mare, N, M, Lunghezza_Imbarcazione, x, y) == false)
                {
                    while( Bussola( Mare, N, M, Lunghezza_Imbarcazione, x, y) == true)
                        {
                            cout << "Attenzione le barche cosi toccano, reinserire le coordinate (x, y) " << endl;
                            cin >> x >> y;
                        }
                }
            if( Lunghezza_Imbarcazione > 1 )
            {
                cout << "Verso quale direzione la vuoi posizionare? " << endl;
                cin.getline( Posizione, 6);
                cin.getline( Posizione, 6);
            }
            if( Lunghezza_Imbarcazione == 1 )
                Mare[x][y] = '*';
            if( strcmp( Posizione, Nord) == 0)
                Posiziona_Verso_Nord( Mare, Lunghezza_Imbarcazione, x, y);
            if( strcmp( Posizione, Sud) == 0)
                Posiziona_Verso_Sud( Mare, Lunghezza_Imbarcazione, x, y);
            if( strcmp( Posizione, Est) == 0)
                Posiziona_Verso_Est( Mare, Lunghezza_Imbarcazione, x, y);
            if( strcmp( Posizione, Ovest) == 0)
                Posiziona_Verso_Ovest( Mare, Lunghezza_Imbarcazione, x, y);
            Print_Mare( Mare, N, M);
        }
}
bool Vincitore( char **Mare, int N, int M)
{
    for( int i = 0; i < N; i++)
        {
            for( int j = 0; j < M; j++)
                {
                    if( Mare[i][j] == '*')
                        return false;
                }
        }
    return true;
}

bool Affondato( char **Mare_Giocatore, int N, int M, int x, int y)
{
    int parti_intatte = 0;
    int cont = 0;
    while(( Mare_Giocatore[x+cont][y] != ' ') && (x + cont != N - 1))
        {
            if( Mare_Giocatore[x+cont][y] != '-')
                parti_intatte++;
            cont++;
        }
    if( parti_intatte != 0)
        return false;
    cont = 0;
    parti_intatte = 0;
    while(( Mare_Giocatore[x-cont][y] != ' ') && (x - cont != 0))
        {
            if( Mare_Giocatore[x-cont][y] != '-')
                parti_intatte++;
            cont++;
        }
    if( parti_intatte != 0)
        return false;
    cont = 0;
    parti_intatte = 0;
    while(( Mare_Giocatore[x][y+cont] != ' ') && (y + cont != N-1))
        {
            if( Mare_Giocatore[x][y+cont] != '-')
                parti_intatte++;
            cont++;
        }
    if( parti_intatte != 0)
        return false;
    cont = 0;
    parti_intatte = 0;
    while(( Mare_Giocatore[x][y-cont] != ' ') && (y - cont != 0))
        {
            if( Mare_Giocatore[x][y-cont] != '-')
                parti_intatte++;
            cont++;
        }
    if( parti_intatte != 0)
        return false;
    cont = 0;
    parti_intatte = 0;
    return true;
}

bool Vincitore_Battaglia_Navale( char **Mare_Giocatore, int N, int M)
{
    for( int i = 0; i < N; i++)
        {
            for( int j = 0; j < M; j++)
                {
                    if( Mare_Giocatore[i][j] == '*')
                        return false;
                }
        }
    return true;
}

void Battaglia_Navale( char **Mare_Giocatore_A, char **Mare_Giocatore_B, char **Mare_Nascosto_Giocatore_A, char **Mare_Nascosto_Giocatore_B, int N, int M)
{
    int x, y;
    bool Colpo_Vincente = true;
    bool Vince_Il_Primo_Giocatore = false;
    bool Vince_Il_Secondo_Giocatore = false;
    bool Vincitore = false;
    cout << endl << endl << endl << endl << endl << endl ;
    cout << "INIZIA LA BATTAGLIA! " << endl << endl;
    while( Vincitore != true)
        {
             cout << "Primo giocatore: " << endl << endl;
             Print_Mare( Mare_Giocatore_A, N, M);
             cout << endl << endl;
             Print_Mare( Mare_Nascosto_Giocatore_B, N, M);
             cout << endl << endl;
             while( Colpo_Vincente == true)
                {
                    if( Vincitore == false)
                        {
                            cout << "Dove vuoi colpire ? (x ,y)" << endl;
                            cin >> x >> y;
                        }
                    if( Mare_Giocatore_B[x][y] == '*')
                        {
                            cout << "Colpito.";
                            Mare_Giocatore_B[x][y] = '-';
                            Mare_Nascosto_Giocatore_B[x][y] = 'x';
                            if( Affondato( Mare_Giocatore_B, N, M, x, y) == true)
                                cout <<".. e affondato! ";
                            cout << endl;
                            Print_Mare( Mare_Nascosto_Giocatore_B, N, M);
                            cout << endl;
                            if(Vincitore_Battaglia_Navale( Mare_Giocatore_B, N, M) == true)
                                Vince_Il_Primo_Giocatore = true;
                        }
                    else
                        {
                            if( Vince_Il_Primo_Giocatore == false)
                                {
                                    cout << "Hai fatto un buco nell' acqua " << endl;
                                    Mare_Nascosto_Giocatore_B[x][y] = 'o';
                                }
                            Colpo_Vincente = false;
                        }
                }
             if( Vince_Il_Primo_Giocatore == true)
                    Vincitore = true;
             else
                {
                    Colpo_Vincente = true;
                    cout << endl << endl << endl << endl << endl;
                    cout << "Secondo giocatore: " << endl << endl;
                    Print_Mare( Mare_Giocatore_B, N, M);
                    cout << endl << endl;
                    Print_Mare( Mare_Nascosto_Giocatore_A, N, M);
                    cout << endl << endl;
                    while( Colpo_Vincente == true)
                        {
                            if( Vincitore == false)
                                {
                                    cout << "Dove vuoi colpire ? (x ,y)" << endl;
                                    cin >> x >> y;
                                }
                            if( Mare_Giocatore_A[x][y] == '*')
                                {
                                    cout << "Colpito !";
                                    Mare_Giocatore_A[x][y] = '-';
                                    Mare_Nascosto_Giocatore_A[x][y] = 'x';
                                    if( Affondato( Mare_Giocatore_A, N, M, x, y) == true)
                                        cout <<" e affondato! ";
                                    cout << endl;
                                    Print_Mare( Mare_Nascosto_Giocatore_A, N, M);
                                    cout << endl;
                                    if( Vincitore_Battaglia_Navale( Mare_Giocatore_A, N, M) == true)
                                        Vince_Il_Secondo_Giocatore = true;
                                }
                            else
                                {
                                    if( Vince_Il_Secondo_Giocatore == false)
                                        {
                                            Mare_Nascosto_Giocatore_A[x][y] = 'o';
                                            cout << "Hai fatto un buco nell' acqua " << endl;
                                        }
                                    Colpo_Vincente = false;
                                }
                        }
                }
            Colpo_Vincente = true;
            if( Vince_Il_Primo_Giocatore == true || Vince_Il_Secondo_Giocatore == true)
                Vincitore = true;
        }
    if( Vince_Il_Primo_Giocatore == true)
        cout << "Vince il primo giocatore!" << endl;
    if( Vince_Il_Secondo_Giocatore == true)
        cout << "Vince il secondo giocatore!" << endl;
}
int main()
{
    int n, m;
    cin >> m >> n;
    const int M = m;
    const int N = n;
    char **Mare_Giocatore_A = new char *[N];
    for( int i = 0; i < N; i++)
        Mare_Giocatore_A[i] = new char [M];
    char **Mare_Giocatore_B = new char *[N];
    for( int i = 0; i < N; i++)
        Mare_Giocatore_B[i] = new char [M];
    char **Mare_Nascosto_Giocatore_A = new char *[N];
    for( int i = 0; i < N; i++)
        Mare_Nascosto_Giocatore_A[i] = new char [M];
    char **Mare_Nascosto_Giocatore_B = new char *[N];
    for( int i = 0; i < N; i++)
        Mare_Nascosto_Giocatore_B[i] = new char [M];
    Init_Mare( Mare_Nascosto_Giocatore_A, N, M);
    Init_Mare( Mare_Nascosto_Giocatore_B, N, M);
    cout << "Primo giocatore: disponi le tue navi" << endl << endl;
    Init_Mare( Mare_Giocatore_A, N, M);
    Print_Mare( Mare_Giocatore_A, N, M);
    Distribuisci_Navi( Mare_Giocatore_A, N, M);
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "Secondo giocatore: disponi le tue navi" << endl << endl;
    Init_Mare( Mare_Giocatore_B, N, M);
    Print_Mare( Mare_Giocatore_B, N, M);
    Distribuisci_Navi( Mare_Giocatore_B, N, M);
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    Battaglia_Navale( Mare_Giocatore_A, Mare_Giocatore_B, Mare_Nascosto_Giocatore_A, Mare_Nascosto_Giocatore_B, N, M);
    return 0;
}
