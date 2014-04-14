#include <iostream>
#include <cstring>
using namespace std;
int Unisci(char[],char[],int);
void CancellaOccorrenze(char[],int);

int main()
{
    char frase[50];
    cin.getline(frase,50);
    int dim = strlen(frase);
    char frasemodificata[dim];
    int dimModificata = Unisci(frase,frasemodificata,dim);
    CancellaOccorrenze(frasemodificata,dimModificata);
    return 0;


}

int Unisci(char frase[], char modificata[],int dim)
{
    int pos = 0;
    for(int i=0;i<dim;i++)
    {
        if(frase[i] != ' ')
        {
            modificata[pos] = frase[i];
            pos++;
        }
    }
    return pos;
}

void CancellaOccorrenze(char frasemodificata[],int dimModificata)
{
    int pos = 0;
    bool doppio = false;
    int cont = 0;
    char miafrase[dimModificata];
    while(pos<dimModificata)
    {
    for(int i=pos+1;i<dimModificata;i++)
    {
        if(frasemodificata[pos] == frasemodificata[i])
        {
            doppio = true;
            frasemodificata[i] = -1;

        }
    }
    if(doppio == false && frasemodificata[pos]!= -1)
    {
        miafrase[cont] = frasemodificata[pos];
        cont++;
    }
    pos++;
    doppio = false;
    }

    for (int j=0;j<cont;j++)
    {
        cout << miafrase[j];
    }
}

