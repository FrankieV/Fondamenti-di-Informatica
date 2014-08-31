#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

bool Anagramma( char Prima_Parola[], char Seconda_Parola[])
{
    const int Dim_Parola = strlen( Prima_Parola);
    char Copia_Seconda_Parola[Dim_Parola];
    strcpy( Copia_Seconda_Parola, Seconda_Parola);
    bool Lettera_Trovata = false;
    for( int i = 0; i < Dim_Parola+1; i++)
        {
            for( int j = 0; j < Dim_Parola+1; j++)
                {
                    if(( Prima_Parola[i] == Copia_Seconda_Parola[j]) && ( Lettera_Trovata == false))
                        {
                            Copia_Seconda_Parola[j] = '*';
                            Lettera_Trovata = true;
                        }
                }
            Lettera_Trovata = false;
        }
    for( int i = 0; i < Dim_Parola+1; i++)
        {
            if( Copia_Seconda_Parola[i] != '*')
                return false;
        }
    return true;
}

void Costruisci_Anagramma( char Prima_Parola[], char Seconda_Parola[])
{
    const int Dim_Parola = strlen( Prima_Parola);
    char Copia_Prima_Parola[ Dim_Parola];
    strcpy( Copia_Prima_Parola, Prima_Parola);
    srand( time(0));
    int index;
    int cont = 0;
    int cont_seconda_parola = 0;
    while( cont < Dim_Parola)
        {
            index = rand() % Dim_Parola;
            if( Copia_Prima_Parola[index] != '*')
                {
                    Seconda_Parola[cont_seconda_parola] = Copia_Prima_Parola[index];
                    Copia_Prima_Parola[index] = '*';
                    cont_seconda_parola++;
                }
            else
                cont--;
            cont++;
        }
}

bool Inversa( char Prima_Parola[], char Seconda_Parola[])
{
    const int Dim_Parola = strlen( Prima_Parola);
    int Cont = Dim_Parola - 1;
    for( int i = 0; i < Dim_Parola + 1; i++)
        {
            if( Prima_Parola[i] != Seconda_Parola[Cont])
                return false;
            Cont--;
        }
    return true;
}

int main()
{
    const int dim = 100;
    char Prima_Parola[dim];
    char Seconda_Parola[dim];
    cin.getline( Prima_Parola, dim);
    cin.getline( Seconda_Parola, dim);
    if( Inversa( Prima_Parola, Seconda_Parola) == true)
        cout << "Inversa " << endl;
    else
        {
            if( Anagramma( Prima_Parola, Seconda_Parola) == true)
                cout << "Anagramma " << endl;
            else
                {
                    Costruisci_Anagramma( Prima_Parola, Seconda_Parola);
                        cout << Seconda_Parola;
                }
        }
    return 0;
}
