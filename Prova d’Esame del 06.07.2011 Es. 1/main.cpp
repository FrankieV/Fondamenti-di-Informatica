#include <iostream>
#include <cstring>
const int dim = 100;
using namespace std;
bool Ordine_Alfabetico(char[]);
int short_word(char[],char[]);
int media_lunghezze(char []);
void Scarti_Media(char[], int);

int main()
{
    char Frase[dim];
    cin.getline(Frase,dim,'\n');
    char Short_Word[strlen(Frase)];
    if(Ordine_Alfabetico(Frase))
        cout << "Frase Crescente" << endl;
    else
        cout << "Frase non Crescente" << endl;

    int min_lenght = short_word(Frase,Short_Word);
    cout << "La parola piu' corta e' " << Short_Word << endl;
    cout << "Lunghezza della parola piu' corta " << min_lenght << endl;
    int media = media_lunghezze(Frase);
    cout << "Media lunghezza delle parole: " << media << endl;
    Scarti_Media(Frase,media);

}

bool Ordine_Alfabetico(char A[])
{
    char p[1];
    p[0] = A[0];
    for(int i=0; i < strlen(A); i++)
    {
        if(A[i] == ' ')
        {
            if(A[i+1] >= p[0])
            {
                p[0] = A[i+1];
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}

int short_word(char Frase[], char Short_Word[])
{
    int cont = 0;
    int cont_Min = 0;
    int index = 0;

    char tmp[strlen(Short_Word)];

    while(Frase[index] != ' ')
    {
        Short_Word[index] = Frase[index];
        index++;
        cont_Min++;
    }
    int pos = ++index;
    while(Frase[pos] != '\0')
    {
        while(Frase[pos] != ' ' && Frase[pos] != '\0')
        {
            tmp[cont] = Frase[pos];
            cont++;
            pos++;

        }
        tmp[cont] = '\0';

        if(cont < cont_Min)
        {
            strcpy(Short_Word,tmp);
            cont_Min = cont;
        }

        cont = 0;
        pos++;
    }


    return cont_Min;
}

int media_lunghezze(char Frase[])
{
    int media = 0;
    int lunghezza_parole = 0;
    int num_parole = 0;
    int pos = 0;

    while(Frase[pos] != '\0')
    {
         if(Frase[pos] != ' ')
         {
             lunghezza_parole++;
         }
         else
         {
             num_parole++;
         }

         pos++;
    }

    media = lunghezza_parole/num_parole;

    return media;
}

void Scarti_Media(char Frase[], int media)
{
    int lunghezza_parole = 0;
    int pos = 0;
    while(Frase[pos] != '\0')
    {
         if(Frase[pos] != ' ')
         {
             cout << Frase[pos];
             lunghezza_parole++;
         }
         else
         {
             cout << " Media lunghezza " << media - lunghezza_parole;
             lunghezza_parole = 0;
             cout << endl;
         }

         pos++;
    }

    cout << " Media lunghezza " << media - lunghezza_parole;
}
