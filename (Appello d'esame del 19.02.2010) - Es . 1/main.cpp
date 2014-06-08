#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;
const int dim = 100;
bool Controlla_Anagrammi(char[], char[]);
void Permuta_Lettere(char[]);
bool Verifica_Inversa(char[],char[]);


int main()
{
    srand(time(0));

    char Parola1[dim];
    cin.getline(Parola1,dim,'\n');
    char Parola2[dim];
    cin.getline(Parola2,dim,'\n');
    if(strlen(Parola1) == strlen(Parola2))
    {
        char temp[strlen(Parola2)];
        strcpy(temp,Parola2);
        if(Controlla_Anagrammi(Parola1,Parola2))
            cout << "Le due parole sono anagrammi" << endl;
        else
            Permuta_Lettere(Parola1);

        if(Verifica_Inversa(Parola1,temp))
            cout << "Le parole sono inverse" << endl;
        else
            cout << "Le parole non sono inverse" << endl;
    }
    else
        cout << "Le due parole hanno lunghezze diverse" << endl;

    return 0;
}


bool Controlla_Anagrammi(char p1[], char p2[])
{
    if(strcmp(p1,p2) == 0)
    return false;

    for(int i = 0; i < strlen(p1); i++)
    {
        for(int j=0; j < strlen(p2); j++)
        {
            if(p1[i] == p2[j])
            {
                p2[j] = -1;
                break;
            }
        }
    }


    for(int i = 0; i < strlen(p2); i++)
    {
        if(p2[i] != -1)
        {
            return false;
        }
    }

    return true;
}

void Permuta_Lettere(char p1[])
{
    char temp[strlen(p1)];
    strcpy(temp,p1);
    char tmp2[strlen(temp)];
    strcpy(tmp2, temp);
    int parole = 0;
    int index = 0;

    while(parole < strlen(temp))
    {
        int num_random = rand() % strlen(p1);

        if(tmp2[num_random] != -1)
        {
            temp[index] = tmp2[num_random];
            tmp2[num_random] = -1;
            index++;
            parole++;
        }
    }

    cout << temp << endl;
}

bool Verifica_Inversa(char p1[], char p2[])
{
    int pos = strlen(p2)-1;
    for(int i = 0; i < strlen(p1); i++)
    {
        if(p1[i] != p2[pos])
            return false;

        pos--;
    }

    return true;
}

