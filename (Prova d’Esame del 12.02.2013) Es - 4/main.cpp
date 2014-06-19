#include <iostream>

using namespace std;
const int dim = 12;
bool Palindroma(int []);

int main()
{
    int D[dim] = { 1, 2, 3, 4, 5, 6, 6, 5, 4, 3, 2, 1};
    if(Palindroma(D))
            cout << "OK";
            else
                cout << "NO";

    }

bool Palindroma(int D[])
{
    int *ptr = D;
    int *ptr_2 = D+(dim-1);
    int index = 0;
    while(index < dim/2)
    {
        if(*ptr != *ptr_2)
            return false;

        *ptr++;
        *ptr_2--;

        index++;
    }

    return true;
}
