#include <iostream>

using namespace std;

int main()
{
    int num = 0;
    int prec = 0, succ = 0, corr = 0;

    cin >> prec;
    cin >> corr;
    cin >> succ;

    while(prec != 9 || corr != 9 || succ != 9)
    {

        if (prec == corr && corr == succ && prec == succ)
        {
            num++;
        }

        cin >> prec;
        cin >> corr;
        cin >> succ;

    }

    cout << num;

}
