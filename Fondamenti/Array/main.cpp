/* Obbiettivo:
Voglio stampare i numeri in ordine decrescente*/

#include <iostream>
using namespace std;

int main()
{

int a;
int b;
int c;

cout << "Inserisci i tre numeri da confrontare: " << endl;



cin >> a >> b >> c;

if(a != b && b!=c  && c!=a)
{

if(a>b && a>c && b>c)
{
    cout << a << " " << b << " " << c;
}
if(b>a && b>c && a>c)
{
    cout << b << " " << a << " " << c;
}
if(c>a && c>b && a>b)
{
  cout << c << " " << a << " " << b;

}
if(c>a && c>b && b>a)
{
    cout << c << " " << b << " " << a;
}

if(b>a && b>c && c>a)
{
    cout << b << " " << c << " " << a;
}

if(a>b && a>c && c>b)
{
    cout << a << " " << c << " " << b;
}
}
else
{
    cout << "I numeri devono essere diversi tra loro!";
}

}




