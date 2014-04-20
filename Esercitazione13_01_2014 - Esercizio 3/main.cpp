#include <iostream>

using namespace std;

void CercaSottoSeq(int[],int);
const int n = 50; // This value can be changed

int main()
{
    int seq;
    int A[n];
    int index = 0;

    cin >> seq;
    while(seq >= 0)
    {
        if(seq % 5 != 0)
        {
            A[index] = seq;
            index++;
        }

        cin >> seq;
    }

    CercaSottoSeq(A,index);
}

void CercaSottoSeq(int A[], int index)
{
    int Posizioni[index];
    int indice = 0;
    for(int i = 0; i<index;i++)
    {
        if(A[i] != 2)
        {
            cout << A[i];
        }
        else
        {
            cout << endl;
            Posizioni[indice] = i;
            indice++;
        }
    }

    cout << endl << "Posizioni relative al numero 2: ";

    for(int i = 0; i<indice; i++)
    {
        cout <<Posizioni[i] + 1;
    }

    cout << endl;
}
