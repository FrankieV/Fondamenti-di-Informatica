#include <iostream>
using namespace std;
bool Ricorsiva_Pari_Dispari( int Sequenza[], int Dim_Sequenza, int index, bool pari)
{
    if( index < Dim_Sequenza)
        {
            if(pari == true)
                {
                    if( index % 2 == 0)
                        {
                            if(( Sequenza[index] + Sequenza[index + 1]) % 2 == 0)
                                return Ricorsiva_Pari_Dispari( Sequenza, Dim_Sequenza, index += 1, pari);
                            else
                                return false;
                        }
                    if( index % 2 != 0)
                        {
                            if(( Sequenza[index] + Sequenza[index + 1]) % 2 != 0)
                                return Ricorsiva_Pari_Dispari( Sequenza, Dim_Sequenza, index += 1, pari);
                            else
                                return false;
                        }
                }
            else
                {
                    if( index % 2 == 0)
                        {
                            if(( Sequenza[index] + Sequenza[index + 1]) % 2 != 0)
                                return Ricorsiva_Pari_Dispari( Sequenza, Dim_Sequenza, index += 1, pari);
                            else
                                return false;
                        }
                    if( index % 2 != 0)
                        {
                            if(( Sequenza[index] + Sequenza[index + 1]) % 2 == 0)
                                return Ricorsiva_Pari_Dispari( Sequenza, Dim_Sequenza, index += 1, pari);
                            else
                                return false;
                        }
                }
        }
    return true;
}

int main()
{
    int dim;
    cin >> dim;
    const int Dim_Sequenza = dim;
    int Sequenza[Dim_Sequenza];
    int numero;
    int index = 0;
    bool pari = true;
    for( int i = 0; i < Dim_Sequenza; i++)
        {
            cin >> numero;
            Sequenza[i] = numero;
        }
    if( Ricorsiva_Pari_Dispari( Sequenza, Dim_Sequenza, index, pari) == true)
        cout << "OK" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
