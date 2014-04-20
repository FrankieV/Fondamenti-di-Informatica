#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(0));
    int x = rand() % 11; //E' stato limitato l'intervallo di estrazione dei numeri casuali (la traccia non lo specifica)
    cout << "Il numero estratto e' " << x << endl;
    int prec, succ;
    int z = 0;
    cin >> prec;
    if(prec != -1)
    {
        cin >> succ;
        while(succ != -1)
        {
            if(prec+succ == x)
            {
                z++;
            }
            prec = succ;
            cin >> succ;
        }
    }
    cout << z;
    return 0;
}
