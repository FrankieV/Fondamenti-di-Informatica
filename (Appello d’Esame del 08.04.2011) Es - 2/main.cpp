#include <iostream>

using namespace std;
const int dim = 30;
bool verifica_Terne(int[], int, int , int );
int init_Array(int[]);

int main()
{
    int A[dim];
    int dimA = init_Array(A);
    int pos = 0;
    int pos2 = 3;
    if(verifica_Terne(A,dimA,pos,pos2))
    {
        cout << "OK";
    }
    else
    {
        cout << "NO";
    }
}

int init_Array(int A[])
{
    int pos = 0;
    int seq;
    cin >> seq;
    while(seq != -1 && pos < dim)
    {
        A[pos] = seq;
        pos++;
        cin >> seq;
    }

    return pos;
}

bool verifica_Terne(int A[], int dimA, int pos, int pos2)
{
    while(pos2 < dimA - 2)
    {
        if(A[pos] == A[pos+2] && A[pos] > A[pos+1] && A[pos2] > A[pos2+1] && A[pos2] == A[pos2+2])
        {
            if(A[pos] < A[pos2] && A[pos+1] < A[pos2+1] && A[pos+2] < A[pos2+2])
            {
                return verifica_Terne(A,dimA, pos += 3, pos2+= 3);
            }
            else
            {

                return false;
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}
