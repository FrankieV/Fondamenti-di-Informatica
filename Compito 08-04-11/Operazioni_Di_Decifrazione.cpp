#include <iostream>
#include <cstring>
using namespace std;

void Init_Frase( char Alfabeto[], char Frase[], int Dim_Frase)
{
    int numero;
    int cont = 0;
    cin >> numero;
    while(numero >= 0 && numero <= 26)
        {
            Frase[cont] = Alfabeto[numero];
            cont++;
            cin >> numero;
        }
    Frase[cont] = '\0';
}


bool Inserisci_e_Cerca_Parola( char Frase[])
{
    const int Dim_Frase = strlen( Frase);
    char Parola[Dim_Frase];
    cin.getline( Parola, Dim_Frase);
    cin.getline( Parola, Dim_Frase);
    const int Dim_Parola = strlen( Parola);
    int cont = 0;
    int cont_lettera = 0;
    for( int i = 0; i <= Dim_Frase; i++)
        {
            if( cont_lettera == Dim_Parola)
                return true;
            if( Parola[cont] == Frase[i])
                {
                    cont_lettera++;
                    cont++;
                }
            else
                {
                    cont_lettera = 0;
                    cont = 0;
                }
        }
    return false;
}

int main()
{
    const int Dim_Alfabeto = 28;
    char Alfabeto[Dim_Alfabeto] ={' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};
    const int Dim_Frase = 500;
    char Frase[Dim_Frase];
    Init_Frase( Alfabeto, Frase, Dim_Frase);
    if( Inserisci_e_Cerca_Parola( Frase))
        cout << "OK" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
