#include <iostream>

using namespace std;
const int n = 10;

int main()
{
    int V[n];
    int dim = 0;
   for(int i=0;i<n;i++)
   {
      V[i] = i;
      dim++;
   }

     for(int i=0;i<n;i++)
   {
      cout << V[i];

   }

   cout << endl <<dim;
}
