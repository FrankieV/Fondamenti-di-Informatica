#include <iostream>
#include <cstring>

using namespace std;
const int dim = 100;
void Elimina_Lettere(char[],char[]);
void print_Frase(char[]);

int main()
{
    char Frase[dim];
    cin.getline(Frase,dim);
    char Elenco_Parole[strlen(Frase)];
    cin.getline(Elenco_Parole,strlen(Frase));
    Elimina_Lettere(Frase,Elenco_Parole);
    print_Frase(Frase);
}


void Elimina_Lettere(char Frase[], char el_Parole[])
{
    char *token = strtok(el_Parole," ");
    char tmp[strlen(token)];
    while(token != NULL)
    {
        strcpy(tmp,token);


        for(int i=0; i < strlen(tmp); i++)
        {
            for(int j = 0; j < strlen(Frase); j++)
            {
                if(tmp[i] == Frase[j])
                {
                    Frase[j] = -1;
                    break;
                }
            }
        }

        token = strtok(NULL, " ");
    }
}

void print_Frase(char Frase[])
{
    for(int i = 0; i < strlen(Frase); i++)
    {
        if(Frase[i] != -1 && Frase[i] != ' ')
        {
            cout << Frase[i];
        }
    }
}
