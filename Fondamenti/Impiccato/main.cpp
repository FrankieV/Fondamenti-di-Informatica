#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
const int n = 50;
void LeggiParola(char[]);
void CopriParola(char[],char[],int);
void IndovinaParola(char[],char[],int);

int main()
{
    char Parola[n];
    cin.getline(Parola,n);
    int dimParola = strlen(Parola);
    char ParolaCoperta[dimParola];
    CopriParola(Parola,ParolaCoperta,dimParola);
    IndovinaParola(Parola,ParolaCoperta,dimParola);

    return 0;

}


void CopriParola(char Parola[],char ParolaCoperta[],int dim)
{
    for(int i=0; i<dim; i++)
    {
        ParolaCoperta[i] = 95;
    }
}

void IndovinaParola(char Parola[], char ParolaCoperta[],int dim)
{
    int tentativi = 0;
    char ParolaInserita[dim];
    int indice = 0;
    while(tentativi < 7)
    {
        cin.getline(ParolaInserita,n);

        if(strcmp(ParolaInserita,Parola) == 0)
        {
            cout << "Corretto! La parola e' " << Parola;
            break;
        }

    for(int i=0; i<dim; i++)
    {
        if(ParolaInserita[indice] == Parola[i])
        {
            ParolaCoperta[i] = Parola[i];
        }
    }

    for(int i=0;i<dim;i++)
    {
      cout << ParolaCoperta[i] << " ";
    }

    tentativi++;
}
}
