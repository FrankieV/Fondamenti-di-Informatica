#include <iostream>
using namespace std;

const int dim = 100;

void Print(int[], int, int);
void ControllaSsequenza(int[], int);
int Leggi(int[]);

int main()
{
	int A[dim];
	int dimA = Leggi(A);
        ControllaSsequenza(A, dimA);
	return 0;
}

int Leggi(int A[])
{
	int seq;
	for (int i=0;i<dim-1;i++)
        {
         A[i]=-1;
        }
        int dimA=0;
        int i= 0;
        cin >> seq;
	while (seq >= 0)
	{
		A[i] = seq;
		cin >> seq;
                i++;
	}
        while (A[dimA]>=0)
         {
           dimA++;
         }
        return dimA;
}

void ControllaSsequenza(int A[], int dimA)
{
        int temp[dim];
	for (int i = 0; i<dimA; i++)
	{
		temp[i] = -1;
	}
	int cont = 1;
	int contMax = 0;
	for (int i = 0; i<dimA; i++)
	{
              if (A[i] <= A[i + 1])
		{
                  cont++;
		}

	      else 
		{
		      if (cont>contMax)
			{
				contMax = cont;
				int index = 0;
                                for (int e = (i + 1) - contMax; e<i + 1; e++)
				{
					temp[index] = A[e];
					index++;
				}

			}
                       cont=1;
		}
	}
	Print(temp, dimA, contMax);
}

void Print(int tmp[], int dimA, int cMax)
{
	for (int i = 0; i<dimA; i++)
	{
		if (tmp[i] != -1)
                    cout << tmp[i];
	}
	cout << endl;
	cout << cMax;
}
