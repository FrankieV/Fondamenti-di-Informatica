#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a;
    int b;
    int c;

    cout << "Inserisci a: \n";
    cin >> a;

    cout << "Inserisci b: \n";
    cin >> b;

    cout << "Inserisci c: \n";
    cin >> c;

    int delta = b*b - 4 * a * c;

    cout << "Il delta e' uguale a:" << delta;

    double radice = sqrt(delta);

    double x1 = (-b + radice) / (2 * a);

    cout << "L' x1 vale:" << x1 << endl;

    double x2 = (-b - radice) / (2 * a);

    cout << "L' x2 vale:" << x2 << endl;

}
