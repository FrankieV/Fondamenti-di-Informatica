#include <iostream>
#include <cstring>

using namespace std;
const int dim = 100;
int init_Sequenza(int[]);
void Converti_Interi(int[],char[],int);
bool Is_Contained(char[],char[]);

int main()
{
    int Seq[dim];
    int dimA = init_Sequenza(Seq);
    char Parola[dimA+1];
    char in_Parola[dimA+1];
    Converti_Interi(Seq,Parola,dimA);
    cout << Parola << endl;
    cin >> in_Parola;
    if(Is_Contained(Parola,in_Parola))
    {
        cout << "OK";
    }
    else
    {
        cout << "NO";
    }



    return 0;
}

int init_Sequenza(int seq[])
{
    int num;
    int pos = 0;
    cin >> num;
    while(pos < dim && num != -1)
    {
        if(num >= 0 && num <= 26 )
        {
            seq[pos] = num;
            pos++;
        }

        cin >> num;
    }

    return pos;
}

void Converti_Interi(int seq[],char Parola[],int dimA)
{
    for(int i = 0; i<dimA; i++)
    {
        if(seq[i] == 0)
        {
            Parola[i] = ' ';
        }
        else
        {
            if(seq[i] != 1)
            {
                int a = seq[i] - 1;
                Parola[i] = 97 + a;
            }
            else
            {
                Parola[i] = 'a';
            }
        }
    }

    Parola[dimA] = '\0';
}

bool Is_Contained(char Parola[],char in_Parola[])
{
    char *token = strtok(Parola, " ");
    while(token != NULL)
    {
        if(strcmp(token,in_Parola) == 0)
        {
            return true;
        }
        else
        {
            token =strtok(NULL, " ");
        }
    }

    return false;
}
