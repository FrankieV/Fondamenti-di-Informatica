#include <iostream>

using namespace std;

int main()
{

int A[5] = {4,2,24,33,2};
int *p = A;
int somma = 0;

while(p == A)
{
    somma+= *p;
    p++;
}

}
