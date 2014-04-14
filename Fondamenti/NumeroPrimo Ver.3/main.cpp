#include <iostream>

using namespace std;
int main() {
int a,i;
cout << "Ehi dimmi un numero!\n"; cin >> a;
for(i=2; i<=a; i++) {
if (i==a) {
cout << "\nGrande! Un numero primo!";
break;
}
if (a%i==0) {
cout << "\nMi sa che non è un numero primo!";
break;
}
}
}
