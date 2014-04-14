#include <iostream>

using namespace std;
const int n = 100;
int Leggi(char []);
void ControllaParentesi(char[],int);

int num_chiuse = 0;
int  num_aperte = 0;
bool superflua = false;

int main()
{
    char A[n];
    bool parentesi_bilanciate = true;
    int dim = Leggi(A);
    ControllaParentesi(A,dim);

    for(int i = 0; i<dim; i++)
    {
        if(A[i] == ')')
        {
            parentesi_bilanciate = false;
        }
    }

    if(num_aperte == num_chiuse && parentesi_bilanciate)
    {
        cout << " ok.. l'espressione e' ben parentesizzata... " << endl;
    }
    else
    {
        cout << " attento! parentesi non bilanciate! " << endl;
    }

    if(superflua)
    {
        cout << " attento! esistono coppie di parentesi superflue! " << endl;
    }
    else
    {
        cout << " ok.. l'espressione non contiene coppie di parentesi superflue " << endl;
    }

    return 0;

}

int Leggi(char V[])
{
    char succ;
    int cont = 0;
    cin >> succ;
    while(succ != '.')
    {
        V[cont] = succ;
        cont++;
        cin >> succ;
    }

    return cont;
}

void ControllaParentesi(char V[], int dim)
{
    int i = 0;
    while(i<dim)
    {
        if(V[i] == '(')
        {
            num_aperte++;
            for(int a=i+1; a<dim; a++)
            {
                if(V[a] == ')')
                {
                    if(V[a-1] == '(')
                    {
                        superflua = true;
                    }
                    num_chiuse++;
                    V[a] = -1;
                    break;
                }
            }
        }

        i++;
    }
}
