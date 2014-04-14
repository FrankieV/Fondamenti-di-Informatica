#include <iostream>

using namespace std;
const int n = 100;

int main()
{
   int A[n];
   int somma = 0;
   int cont = 0;
   bool valoriCompresi = false;
   bool valoriCompresi2 = false;

   for(int i = 0;i<n;i++)
   {
       cin >> A[i];
   }

   for(int i = 0; i<n;i++)
   {
       if(A[i] < -50 || A[i] > 50)
       {
           valoriCompresi = true;
           cout << A[i];
       }
       if(A[i] >= -50 && A[i] <= 50)
       {
           valoriCompresi2 = true;
           cont++;
           somma += A[i];
       }
   }

   if(valoriCompresi == false)
   {
       cout << "VUOTO1";
   }

   if(valoriCompresi2 == false)
   {
       cout << endl;
       cout << "VUOTO2";
   }
   else
   {
       cout << endl;
       cout << (float)somma/cont;
   }
}
