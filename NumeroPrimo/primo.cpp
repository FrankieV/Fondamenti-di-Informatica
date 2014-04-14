#include <iostream>

using namespace std;
int main()
{
    int cont = 2;
    int N;
    bool trovatodivisore;
    trovatodivisore=false;

    cin >> N;

    while(cont < N/2 && trovatodivisore==false)
    {
        if(N%cont==0)
        {
            trovatodivisore=true;
        }
        cont++;
    }
    if(trovatodivisore==true)
        cout << "no";

    else
        cout << "si";

    return 0;
}



