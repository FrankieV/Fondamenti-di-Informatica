#include <iostream>

using namespace std;
const int n = 20;
char PrimoCarattere;
int Leggi(char[]);
bool VerificaDisgiunte(char[],char[],int,int);

int main()
{
    char A[n];
    char B[n];
    int dimA = Leggi(A);
    int dimB = Leggi(B);
    if(VerificaDisgiunte(A,B,dimA,dimB))
    {
        cout << "DISGIUNTE";
    }
    else
    {
        cout << PrimoCarattere;
    }

    return 0;

}

int Leggi(char V[])
{
    char seq;
    int pos = 0;
    cin >> seq;
    while(seq != '.' && pos < n)
    {
        V[pos] = seq;
        pos++;
        cin >> seq;
    }

    return pos;
}

bool VerificaDisgiunte(char A[],char B[],int dimA,int dimB)
{
    for(int i=0; i<dimA; i++)
    {
        for(int j=0; j<dimB; j++)
        {
            if(A[i] == B[j])
            {
                PrimoCarattere = A[i];
                return false;
            }
        }
    }
    return true;
}
