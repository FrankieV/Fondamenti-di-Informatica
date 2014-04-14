#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    char corrente, successivo;

    cin >> corrente;
    cin >> successivo;

    while(successivo != 'k' || corrente != 'o')
    {
        num++;
        corrente = successivo;
        cin >> successivo;
    }

    cout << num;
    return 0;
}
