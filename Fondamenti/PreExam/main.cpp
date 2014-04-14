#include <iostream>
using namespace std;

int main()
{
    int prec;
    int corr;
    int pos = 1;
    cin >> prec;
    cin>> corr;
    while(prec != 0 && corr != 0)
    {
        if(prec == pos || corr == pos)
        {
            cout << "TROVATO";
        }

        cin >> prec;
        cin >> corr;
        pos+2;
    }
}
