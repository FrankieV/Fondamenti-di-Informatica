#include <iostream>
#include <cstring>
using namespace std;

void Tokenizzatore( char Elenco[], char Parola[])
{
    int cont = 0;
    int cont_parola = 0;
    while( Elenco[cont] != ' ' && Elenco[cont] != '\0')
        {
            if( Elenco[cont] != '*')
                {
                    Parola[cont_parola] = Elenco[cont];
                    Elenco[cont] = '*';
                    cont_parola++;
                }
            cont++;
        }
    if( Elenco[cont] != '\0')
        Elenco[cont] = '*';
    Parola[cont_parola] = '\0';
}

bool Parole_Finite( char Elenco[])
{
    int Dim_Elenco = strlen( Elenco);
    for( int i = 0; i < Dim_Elenco; i++)
        {
            if( Elenco[i] != '*')
                return false;
        }
    return true;
}

int Mail_Sospette( char **Elenco_Mail, char Elenco[], int Dim_Array)
{
    char Parola[100];
    int Dim_Elenco = strlen( Elenco);
    char Copia_Elenco[Dim_Elenco+1];
    strcpy( Copia_Elenco, Elenco);
    Tokenizzatore( Copia_Elenco, Parola);
    int cont_parola = 0;
    int Dim_Parola;
    Dim_Parola = strlen( Parola);
    int cont_lettere = 0;
    int cont_mail_sospette = 0;
    bool mail_sospetta = false;
    for( int i = 0; i < Dim_Array; i++)
        {
            for( int cont = 0; Elenco_Mail[i][cont] != '\0'; cont++)
                {
                    if( Parola[cont_parola] == Elenco_Mail[i][cont])
                        {
                            cont_lettere++;
                            if( cont_lettere == Dim_Parola && mail_sospetta != true)
                                {
                                    mail_sospetta = true;
                                    cont_mail_sospette++;
                                }
                            else
                                cont_parola++;
                        }
                    else
                        {
                            cont_parola -= cont_lettere;
                            cont_lettere = 0;
                        }
                    if( Parole_Finite( Copia_Elenco) == false && Elenco_Mail[i][cont+1] == '\0')
                        {
                            Tokenizzatore(Copia_Elenco, Parola);
                            Dim_Parola = strlen( Parola);
                            cont_lettere = 0;
                            cont = -1;
                            cont_parola = 0;
                        }
                }
            strcpy( Copia_Elenco, Elenco);
            Tokenizzatore( Copia_Elenco, Parola);
            Dim_Parola = strlen( Parola);
            cont_lettere = 0;
            cont_parola = 0;
            mail_sospetta = false;
        }
    return cont_mail_sospette;
}

int main()
{
int dim;
    cout << "Inserisci il numero delle mail sospette..." << endl << endl;
    cin >> dim;
    char Parola[100];
    const int dim_mail = 5000;
    const int dim_array = dim;
    char Elenco_Parole_Sospette[dim_mail];
    cout << endl << "Inserisci l'elenco delle parole sospette " << endl;
    cout <<  endl;
    cin.getline( Elenco_Parole_Sospette, dim_mail);
    cin.getline( Elenco_Parole_Sospette, dim_mail);
    char **Elenco_mail = new char *[dim_array];
    for( int i = 0; i < dim_array; i++)
        Elenco_mail[i] = new char [dim_mail];
    for( int i = 0; i < dim_array; i++)
        {
            cout << endl << endl << "Inserisci il testo della mail numero " << i+1 << endl << endl;
            cin.getline( Elenco_mail[i], dim_mail);
        }
    if( Mail_Sospette( Elenco_mail, Elenco_Parole_Sospette, dim_array) != 0)
        cout << endl << endl << "Ci sono " << Mail_Sospette( Elenco_mail, Elenco_Parole_Sospette, dim_array) << " mail sospette !" << endl << endl;
    else
        cout << "Tranquilla non ci sono mail sospette " << endl << endl ;
    return 0;
}
