#include <iostream>
using namespace std;

const int dim = 9;

void Print(int[], int, int);
void ControllaSsequenza(int[], int);
int Leggi(int[]);

int main()
{
    int A[dim];
    int dimA = Leggi(A);
    if(dimA != 0)
        ControllaSsequenza(A, dimA);
    else
        cout << "Empty";
    return 0;
}

int Leggi(int A[])
{
    int i = 0;
    int seq;
    cin >> seq;
    while (i<dim && seq >= 0)
    {
        A[i] = seq;
        i++;
        cin >> seq;
    }
    return i;
}

void ControllaSsequenza(int A[], int dim)
{
    int corr = 0;
    int succ = 1;
    int cont = 1;
    int cont_Max = 1;
    while(succ < dim)
    {
        if(A[corr] <= A[succ])
        {
            cont++;
        }
        else
        {
            if(cont > cont_Max)
            {
                cont_Max = cont;
            }

            cont = 1;
        }



        corr = succ;
        succ++;
    }

    cout << endl << cont_Max;
}

