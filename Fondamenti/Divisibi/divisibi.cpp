#include <iostream>

using namespace std;
const int dim = 10;
bool Divisibile(int[],int);

int main()
{
    int V[dim];
    int seq;
    int X;
    for(int i=0;i<dim;i++)
    {
        cin >> seq;
        V[i] = seq;
    }

    cin >> X;
   if(Divisibile(V,X))
   {
       cout << "OK";
   }
   else
   {
       cout << "NO";
   }


}

bool Divisibile(int V[],int X)
{
    for(int i=0;i<dim;i++)
    {
        if(V[i] % X == 0)
        {
            return false;
        }
    }
    return true;
}
