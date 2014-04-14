#include <iostream>

using namespace std;

int main()
{
   int prec = 0;
   int succ = 0;
   bool property = false;
   cin >> prec;
   if(prec != 0)
   {
    cin >> succ;
   }
   while(succ != 0)
   {
       if(prec % 2 == 0 && succ % 2 == 0 ||  (prec + succ) % prec == 0 || (prec+succ) % succ == 0 )
       {
           property = true;
           break;
       }
       else
       {
            property = false;
       }

       prec = succ;
       cin >> succ;
   }

   if(property)
   {
       cout << "SI";
   }
   else
   {
       cout << "NO";
   }

   return 0;

}
