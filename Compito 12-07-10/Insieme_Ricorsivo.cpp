#include <iostream>
using namespace std;

bool Insieme_Ricorsivo( int numero)
{
    if( numero == 0)
        return false;
    if( numero == 1)
        return true;
    if( numero < 1)
        return false;
    if( numero > 1)
        {
            numero = (( 3 * numero) - 2) / 6;
            return Insieme_Ricorsivo( numero);
        }
}

int main()
{
    int numero;
    cout << "Inserisci il numero..." << endl;
    cin >> numero;
    if( Insieme_Ricorsivo( numero) == true)
        cout << "Il numero fa parte dell' insieme ricorsivo" << endl;
    else
        cout << "Il numero non fa parte dell'nsieme ricorsivo" << endl;
    return 0;
}
