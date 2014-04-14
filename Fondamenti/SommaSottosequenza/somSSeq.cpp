#include <iostream>
using namespace std;

int main()
{
int prec = 0, succ = 0;
int somma_sottosequenza = 0;
bool double_zero = false;

cin >> succ;

while(double_zero == false)
{
    somma_sottosequenza += succ;
    prec = succ;
    cin >> succ;

    if(succ == 0 && prec != 0)
    {
        cout << somma_sottosequenza << endl;
        somma_sottosequenza = 0;
    }

     if(prec == 0 && succ == 0)
    {
        double_zero = true;
    }
}

return 0;

}


