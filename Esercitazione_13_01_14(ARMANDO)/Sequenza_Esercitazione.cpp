#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() 
{
	srand(time(0));
	int x = rand() % 10;
	int cont = 0;
	int prec, succ;
	int somma = 0;
	cin >> succ;
	while( succ != -1)
		{
			prec = succ;
			cin >> succ;
			if( prec + succ == x)
				cont++;
		}
	cout << cont;	
	cout<<endl<<x;
	return 0;
}
