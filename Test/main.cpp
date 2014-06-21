#include <iostream>
#include <cstring>

using namespace std;
const int dim = 10;

int main()
{
    int * A[10];
    for(int i =0; i<10; i++)
        A[i]=new int [15];


delete [] A;

cout << sizeof(A);


}
