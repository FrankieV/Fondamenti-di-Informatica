#include <iostream>
using namespace std;
int main()
{
    int numesami;

   cout << "Inserisci il numero degli esami\n\n";
   cout << "---------> ";
   cin >> numesami;
   cout << "\nLa media sara' calcolata su " << numesami << " esami.";

   double totale_esami[numesami];
   double somma = 0;

   for(int i = 0; i < numesami; i++)
   {
       cout << "\nInserisci il " << i << char(248) << " voto: ";
       cin >> totale_esami[i];
       if(totale_esami[i] <= 30 && totale_esami[i]>= 18)
       {
            somma += totale_esami[i];
       }
       else
       {
            cout << "Spiacente, il voto fornito non e' valido =(";
            break;
       }
   }
    double media = somma / numesami;
    cout << "\nLa media calcolata su "  << numesami << " esami e' " << media;

    return 0;
}
