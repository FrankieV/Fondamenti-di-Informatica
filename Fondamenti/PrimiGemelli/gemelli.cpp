#include <iostream>
using namespace std;

bool Primo(int);
bool Gemelli(int,int);
int main()
{
    int n1,n2;
    cin >> n1 >> n2;
    if(n1 < 0)
    {
        n1 = -n1;
    }
    if(n2 < 0)
    {
        n2 = -n2;
    }
    Primo(n1);
    Primo(n2);
    if(Primo(n1) == false || Primo(n2) == false)
        cout << "non entrambi primi";
    else
    {
        if(Gemelli(n1,n2))
            cout << "gemelli";
        else
            cout << "non gemelli";
    }
}

bool Primo(int x)
{
    int divisore = 2;
    while(x%divisore != 0)
    {
        divisore++;
    }
    if(divisore == x)
        return true;
    return false;
}

bool Gemelli(int a, int b)
{
    if(a-b == 2 || b-a == 2)
        return true;
    return false;
}

