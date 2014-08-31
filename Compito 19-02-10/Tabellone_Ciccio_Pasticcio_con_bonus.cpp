#include <iostream>
using namespace std;

void Init_Tabellone( char **Tabellone, int Dim_Tabellone)
{
    char Simbolo;
    for( int i = 0; i < Dim_Tabellone; i++)
        {
            for( int j = 0; j < Dim_Tabellone; j++)
                {
                    if( i == 0 && j == 0)
                        Tabellone[i][j] = ' ';
                    else
                        {
                            if( j == 0)
                                Tabellone[i][j] = i + '0';
                            else
                                {
                                    if( i == 0)
                                        Tabellone[i][j] = j +'0';
                                    else
                                        {
                                            if ( i== j)
                                                Tabellone[i][j] = '_';
                                            else
                                                Tabellone[i][j] = '0';
                                        }
                                }
                        }
                }
        }
    for( int i = 0; i < Dim_Tabellone; i++)
        {
            for( int j = 0; j < Dim_Tabellone; j++)
                {
                    if( i != 0 && j != 0 && i != j)
                        {
                            cin >> Simbolo;
                            Tabellone[i][j] = Simbolo;
                        }

                }
        }
}

void Vittorie_In_Casa( char **Tabellone, int Dim_Tabellone)
{
    int cont_vittorie_in_casa = 0;
    int max_vittorie_in_casa = 0;
    char vittoria = '1';
    int squadra_piu_forte_in_casa;
    for( int i = 1; i < Dim_Tabellone; i++)
        {
            for( int j = 1; j < Dim_Tabellone; j++)
                {
                    if( Tabellone[i][j] == vittoria)
                        cont_vittorie_in_casa++;
                }
            if( cont_vittorie_in_casa > max_vittorie_in_casa)
                {
                    max_vittorie_in_casa = cont_vittorie_in_casa;
                    squadra_piu_forte_in_casa = i;
                }
            cont_vittorie_in_casa = 0;
        }
    cout << "La squadra che ha vinto piu volte in casa e' S" << squadra_piu_forte_in_casa << " con " << max_vittorie_in_casa << " vittorie. " << endl << endl;
}

int Campione_Del_Torneo( char **Tabellone, int Dim_Tabellone)
{
    char Vittoria_In_Casa = '1';
    char Vittoria_Fuori_Casa = '2';
    char Pareggio = '0';
    int Cont_Punti_Squadra = 0;
    int Max_Punti = 0;
    int Squadra_Vincitrice;
    for( int i = 1; i < Dim_Tabellone; i++)
        {
            for( int j = 1; j < Dim_Tabellone; j++)
                {
                    if( Tabellone[i][j] == Vittoria_In_Casa)
                        Cont_Punti_Squadra += 3;
                    if( Tabellone[i][j] == Pareggio || Tabellone[j][i] == Pareggio)
                        Cont_Punti_Squadra += 1;
                    if( Tabellone[j][i] == Vittoria_Fuori_Casa)
                        Cont_Punti_Squadra += 3;
                }
            if( Cont_Punti_Squadra > Max_Punti)
                {
                    Max_Punti = Cont_Punti_Squadra;
                    Squadra_Vincitrice = i;
                }
            Cont_Punti_Squadra = 0;
        }
    cout << "La squadra campione e' S" << Squadra_Vincitrice << " con " << Max_Punti << " punti" << endl << endl;
    return Max_Punti;
}

void Squadra_Con_Meno_Punti( char **Tabellone, int Dim_Tabellone, int max_punti)
{
    char Vittoria_In_Casa = '1';
    char Vittoria_Fuori_Casa = '2';
    char Pareggio = '0';
    int Cont_Punti_Squadra = 0;
    int min_punti = max_punti;
    int Squadra_Perdente;
    for( int i = 1; i < Dim_Tabellone; i++)
        {
            for( int j = 1; j < Dim_Tabellone; j++)
                {
                    if( Tabellone[i][j] == Vittoria_In_Casa)
                        Cont_Punti_Squadra += 3;
                    if( Tabellone[i][j] == Pareggio || Tabellone[j][i] == Pareggio)
                        Cont_Punti_Squadra += 1;
                    if( Tabellone[j][i] == Vittoria_Fuori_Casa)
                        Cont_Punti_Squadra += 3;
                }
            if( Cont_Punti_Squadra < min_punti)
                {
                    min_punti = Cont_Punti_Squadra;
                    Squadra_Perdente = i;
                }
            Cont_Punti_Squadra = 0;
        }
    cout << "La squadra perdente e' S" << Squadra_Perdente << " con " << min_punti << " punti" << endl << endl;
}

void Print_Tabellone( char **Tabellone, int Dim_Tabellone)
{
    for( int i = 0; i < Dim_Tabellone; i++)
        {
            for( int j = 0; j < Dim_Tabellone; j++)
                {
                    if( i != j && i == 0)
                        cout << "S" << j << " ";
                    else
                        {
                            if( j!= i && j == 0)
                                cout << "S" << i << " ";
                            else
                                cout << " " << Tabellone[i][j] << " ";
                        }
                }
            cout << endl;
        }
}

bool Squadra_che_ha_perso_tutte_le_partite_del_torneo( char** Tabellone, int Dim_Tabellone)
{
    char Vittoria_in_casa = '1';
    char Vittoria_fuori_casa = '2';
    char Pareggio = '0';
    int cont = 0;
    for( int i = 1; i < Dim_Tabellone; i++)
        {
            for( int j = 1; j < Dim_Tabellone; j++)
                {
                    if( Tabellone[i][j] == Vittoria_in_casa)
                        cont++;
                    if( Tabellone[j][i] == Vittoria_fuori_casa)
                        cont++;
                    if( Tabellone[j][i] == Pareggio || Tabellone[i][j] == Pareggio)
                        cont++;
                }
            if( cont == 0)
                {
                    cout << "C' e una squadra che non ha vinto neanche una partita del torneo la squadra e' S" << i << endl << endl;
                    return true;
                }
            cont = 0;
        }
    return false;
}
void Squadra_con_il_maggior_numero_di_vittorie( char **Tabellone, int Dim_Tabellone)
{
    char Vittoria_in_casa = '1';
    char Vittoria_fuori_casa = '2';
    int cont = 0;
    int max_vittorie = 0;
    int Squadra_vincente = 0;
    for( int i = 1; i < Dim_Tabellone; i++)
        {
            for( int j = 1; j < Dim_Tabellone; j++)
                {
                    if( Tabellone[i][j] == Vittoria_in_casa)
                        cont++;
                    if( Tabellone[j][i] == Vittoria_fuori_casa)
                        cont++;
                }
            if( cont > max_vittorie)
                {
                    max_vittorie = cont;
                    Squadra_vincente = i;
                }
            cont = 0;
        }
    cout << "La squadra con il maggior numero di vittorie e' S" << Squadra_vincente << " con " << max_vittorie << " partite vinte." << endl << endl;
}
int main()
{
    int Num_Squadre;
    cin >> Num_Squadre;
    int max_punti;
    const int Dim_Tabellone = Num_Squadre + 1;
    char **Tabellone = new char *[Dim_Tabellone];
    for( int i = 0; i < Dim_Tabellone; i++)
        Tabellone[i] = new char [Dim_Tabellone];
    Init_Tabellone( Tabellone, Dim_Tabellone);
    cout << endl << endl;
    Print_Tabellone( Tabellone, Dim_Tabellone);
    cout << endl << endl;
    Vittorie_In_Casa( Tabellone, Dim_Tabellone);
    max_punti = Campione_Del_Torneo( Tabellone, Dim_Tabellone);
    Squadra_Con_Meno_Punti( Tabellone, Dim_Tabellone, max_punti);
    Squadra_che_ha_perso_tutte_le_partite_del_torneo( Tabellone, Dim_Tabellone);
    Squadra_con_il_maggior_numero_di_vittorie( Tabellone, Dim_Tabellone);
    return 0;
}
