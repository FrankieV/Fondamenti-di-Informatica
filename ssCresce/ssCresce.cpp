#include <iostream>
using namespace std;

const int dim = 99;

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
    int start_index = 0;
    int end_index = 0;
    int cont_Max = 1;
    while(succ < dim)
    {
        if(A[corr] <= A[succ])
        {
            cont++;
        }
        else
        {
            cont = 1;
        }

        if(cont > cont_Max)
        {
            start_index = succ-cont_Max;
            end_index = succ;
            cont_Max = cont;
        }

        corr = succ;
        succ++;
    }

  for(int i= start_index; i<= end_index; i++)
  {
      cout << A[i];
  }

  cout << endl << cont_Max;
}

