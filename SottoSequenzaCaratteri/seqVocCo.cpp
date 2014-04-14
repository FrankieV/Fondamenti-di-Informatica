#include <iostream>

using namespace std;
bool TrovaConsonanti(char);
bool TrovaVocali(char);
int main()
{
    char prec;
    char succ;
    int num_sottosequenze = 1;
    cin >> prec;
    if(prec != '.')
    {
        cin >> succ;

        while(succ != '.')
        {

            if(TrovaVocali(prec) && TrovaVocali(succ))
            {
                num_sottosequenze++;
            }
            if(TrovaConsonanti(prec) && TrovaConsonanti(succ))
            {
                num_sottosequenze++;
            }

            prec = succ;
            cin >> succ;
        }

            cout << num_sottosequenze;
    }
    else
    {
        cout << 0;
    }



    return 0;
}

bool TrovaVocali(char x)
{
    if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
        return true;
    return false;

}

bool TrovaConsonanti(char y)
{
    if(y != 'a' && y != 'e' && y != 'i' && y != 'o' && y != 'u')
        return true;
    return false;
}
