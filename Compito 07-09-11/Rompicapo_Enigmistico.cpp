#include <iostream>
#include <cstring>
using namespace std;

bool match( char Completamento[], char Indizi[])
{
    int cont = 0;
    if( strlen( Completamento) == strlen( Indizi))
        {
            while( Completamento[cont] != '\0')
                {
                    if( Completamento[cont] == Indizi[cont])
                        return true;
                    cont++;
                }
        }
    return false;
}

void Tokenizzatore( char Parola[], char Elenco[])
{
    int cont = 0;
    int cont_parola = 0;
    while(( Elenco[cont] != ' ') && ( Elenco[cont] != '\0'))
        {
            if( Elenco[cont] != '*')
                {
                    Parola[cont_parola] = Elenco[cont];
                    Elenco[cont] = '*';
                    cont_parola++;
                }
            cont++;
        }
    Elenco[cont] = '*';
    Parola[cont_parola] = '\0';
}

bool Parole_Finite( char Parole[])
{
    const int dim_Parole = strlen( Parole) - 1;
    int cont_Parole = 0;
    for( int i = 0; i < dim_Parole; i++)
        {
            if( Parole[i] != '*')
                return false;
        }
    return true;
}

void Lista_Parole_Completate( char stringhe_di_completamento[], char Indizi[], char Parole[], char Parole_Completate[])
{
    const int dim_Parola = strlen( Parole);
    char Indizio[dim_Parola];
    char Parola[dim_Parola];
    char Completamento[dim_Parola];
    char CopiaParola[dim_Parola];
    char CopiaIndizio[dim_Parola];
    Tokenizzatore( Parola, Parole);
    Tokenizzatore( Indizio, Indizi);
    strcpy( CopiaParola, Parola);
    strcpy( CopiaIndizio, Indizio);
    int cont_parola = 0;
    int cont_completamento = 0;
    int cont = 0;
    bool ultimo_ciclo = false;
    bool fine = false;
    while( fine != true)
        {
            cout << endl << endl;
            cout << "Parola nascosta " << CopiaParola << " indizio : " << CopiaIndizio << endl << endl;
            cout << "Stringhe di completamento seguenti " << endl << endl << stringhe_di_completamento << endl << endl;
            cout << "Scrivi quella che ti sembra piu' consona..." << endl <<endl;
            cin.getline( Completamento, dim_Parola);
            if(match( Completamento, Indizio))
                {
                    while( Parola[cont_parola] != '\0')
                        {
                            if( Parola[cont_parola] == '_')
                                {
                                    Parola[cont_parola] = Completamento[cont_completamento];
                                    cont_completamento++;
                                }
                            Parole_Completate[cont] = Parola[cont_parola];
                            cont_parola++;
                            cont++;
                        }
                    Parole_Completate[cont] = ' ';
                    cont++;
                    cont_parola = 0;
                    cont_completamento = 0;
                    Tokenizzatore( Parola, Parole);
                    Tokenizzatore( Indizio, Indizi);
                    strcpy( CopiaParola, Parola);
                    strcpy( CopiaIndizio, Indizio);
                    if( ultimo_ciclo == true)
                        fine = true;
                    if( ( Parole_Finite( Parole)) == true)
                        ultimo_ciclo = true;
                    cout << Parole;
                    cout << endl << endl;
                    cout << "Esatto...continuiamo..." << endl << endl;
                }
        }
    Parole_Completate[cont] = '\0';
}

int main()
{
    const int dim_array = 100;
    char Parola[dim_array];
    char Indizi[dim_array];
    char Stringhe_Di_Completamento[dim_array];
    char Parole_Completate[dim_array];
    cin.getline( Parola, dim_array);
    cin.getline( Indizi, dim_array);
    cin.getline( Stringhe_Di_Completamento, dim_array);
    Lista_Parole_Completate( Stringhe_Di_Completamento, Indizi, Parola, Parole_Completate);
    cout << endl << endl;
    cout << "L'elenco delle parole completate e' : " << endl;
    for( int i = 0; i < Parole_Completate[i] != '\0'; i++)
    {
        cout << Parole_Completate[i];
    }
    cout << endl << endl;
    return 0;
}
