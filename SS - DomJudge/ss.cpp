#include <iostream>

using namespace std;

int main()
{
   char prec;
   char succ;
   bool property = false;
   cin >> succ;
   while(succ != '*')
   {
       if((succ >= 'A' && succ <= 'Z') && (prec >= 'A' && prec <= 'Z') || (succ >= 'a' && succ <= 'z') && (prec >= 'a' && prec <= 'z') && succ == prec)
       {
           property = true;
           break;
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
