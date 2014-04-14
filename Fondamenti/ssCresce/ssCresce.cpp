#include <iostream>

using namespace std;
int Leggi(int []);
void ControllaSequenza(int [],int, int[]);

const int n = 100;

int main()
{
    int A[n];
    int dimA = Leggi(A);
    int tmp[dimA];
    int cont = 0;

    for(int i = 0; i<dimA; i++)
    {
        tmp[i] = -1;
    }

    ControllaSequenza(A,dimA,tmp);


    for(int i = 0; i<dimA; i++)
    {
        if(tmp[i] != -1)
        {
            cout << tmp[i];
            cont++;
        }
    }

    if(cont == 0)
        cout << "Empty";
    else
    cout << endl << cont;
}

int Leggi(int V[])
{
    int cont = 0;
    int seq;
    cin >> seq;
    while(cont < n && seq >= 0  )
    {
        V[cont] = seq;
        cont++;
        cin >> seq;
    }
    return cont;

}

void ControllaSequenza(int V[],int dim, int temp[])
{
    int cont = 1;
    int contMax = 0;
    bool primaVolta = true;

    for(int i=0; i<dim; i++)
    {
        if(V[i] <= V[i+1])
        {
            cont++;
            if(primaVolta)
            {
                temp[i] = V[i];
            }

        }
        else
        {
            primaVolta = false;
            if(cont > contMax)
            {
                int counter = 0;
                for(int a = (i+1)-cont; a<i+1; a++)
                {
                    temp[counter] = V[a];
                    counter++;
                }
                contMax = cont;
            }

            cont = 1;
        }
    }
}

