#include <iostream>

using namespace std;
const int n = 100;

int main()
{
    char A[n];
    int cont = 0;
    bool vuoto = true;
    int numMiniscole = 0;
    for(int i = 0; i<n; i++)
    {
        cin >> A[i];
    }

    for(int i = n; i>=0; i--)
    {
        if(A[i] >= 'a' && A[i] <= 'z')
        {
            vuoto = false;
            cont++;
            numMiniscole++;
            cout << A[i];
        }
        else if(A[i] >= 'A' && A[i] <= 'Z')
        {
            vuoto = false;
            cont++;
            cout << A[i];
        }
    }
    if(vuoto == false)
    {
        cout << endl;
        cout << (float)numMiniscole/cont*100 << "%";
    }
    else
    {
        cout << "VUOTO";
    }

}
