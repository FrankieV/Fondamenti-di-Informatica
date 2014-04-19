#include <iostream>

using namespace std;
const int n = 8;
bool MetaUguali(int[],int,int);

int main()
{
    int A[n];
    int index = 0;
    int cont = n/2;
    for(int i = 0; i<n; i++)
    {
        cin >> A[i];
    }


    if(MetaUguali(A,index,cont))
        cout << "Meta' uguali";
    else
        cout << "Meta' NON uguali";

    return 0;

}

bool MetaUguali(int A[],int index, int cont)
{
    while(cont < n)
    {
        if(A[index] != A[cont])
            return false;
        else
            return MetaUguali(A,index+=1,cont+=1);
    }

    return true;
}
