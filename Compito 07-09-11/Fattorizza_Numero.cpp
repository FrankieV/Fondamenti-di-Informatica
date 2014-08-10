#include <iostream>
using namespace std;

void Fattorizza_Numero( int numero, int Sequenza[], int dim_Sequenza, int divisore, int occorrenze)
{
    if( divisore < dim_Sequenza)
        {
            if( divisore == 0 || divisore == 1)
                {
                    Sequenza[divisore] = 0;
                    return Fattorizza_Numero( numero, Sequenza, dim_Sequenza, divisore += 1, occorrenze);
                }
            if( numero == 1)
                {
                    divisore += 1;
                    Sequenza[divisore] = 0;
                    return Fattorizza_Numero( numero, Sequenza, dim_Sequenza, divisore, occorrenze);
                }
            if( numero % divisore == 0)
                {
                    numero = numero / divisore;
                    occorrenze += 1;
                    Sequenza[divisore] = occorrenze;
                    return Fattorizza_Numero( numero, Sequenza, dim_Sequenza, divisore, occorrenze);
                }
            else
            {
                if( occorrenze == 0)
                    Sequenza[divisore] = 0;
                occorrenze = 0;
                return Fattorizza_Numero( numero, Sequenza, dim_Sequenza, divisore += 1, occorrenze);
            }
        }
}

void Stampa_Array( int Sequenza[], int dim_Sequenza)
{
    for( int i = 0; i < dim_Sequenza; i++)
        cout << Sequenza[i] << " ";
    cout << endl;
}
int main()
{
 const int Dim_Sequenza = 100;
 int Sequenza[Dim_Sequenza];
 int numero;
 int divisore = 0;
 int occorrenze = 0;
 cin >> numero;
 Fattorizza_Numero( numero, Sequenza, Dim_Sequenza, divisore, occorrenze);
 Stampa_Array( Sequenza, Dim_Sequenza);
 return 0;
}
