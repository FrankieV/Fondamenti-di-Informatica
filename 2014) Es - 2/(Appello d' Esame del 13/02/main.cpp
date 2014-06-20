#include <iostream>
#include <cstring>

using namespace std;
const int dim = 100;
bool Anagrammi(char []);

int main()
{
    char elenco_Parole[dim];
    char tmp_Parole[dim];
    char tmp2_Parole[dim];
    cin.getline(elenco_Parole,dim);
    strcpy(tmp_Parole,elenco_Parole);
    strcpy(tmp2_Parole,elenco_Parole);
    bool trovato = false;
    if(Anagrammi(elenco_Parole))
    {
        char lettere[6] = "aeiou";
        int pos = 0;
        while(pos < strlen(lettere))
        {
            char *token = strtok(tmp_Parole," ");
            while(token != NULL && trovato == false)
            {
                for(int i = 0; i < strlen(token); i++)
                {
                    if(lettere[pos] == token[i])
                    {
                        cout << token << " ";
                        pos++;
                        trovato = true;
                        break;
                    }
                }

                token = strtok(NULL, " ");
            }

            strcpy(tmp_Parole,tmp2_Parole);
            trovato = false;
        }
    }
    else
    {
        cout << "Le parole non sono anagrammi";
    }
}

bool Anagrammi(char elenco_Parole[])
{
    int cont = 0;
    bool prima_volta = true;
    char *token = strtok(elenco_Parole, " ");
    char tmp[strlen(token)];
    strcpy(tmp,token);
    while(token != NULL)
    {
        if(prima_volta)
        {
            token = strtok(NULL," ");
        }


        for(int i = 0; i < strlen(token); i++)
        {
            for(int j = 0; j < strlen(token); j++)
            {
                if(token[i] == tmp[j])
                {
                    tmp[j] = -1;
                    break;
                }
            }
        }
        for(int i =0; i < strlen(tmp); i++)
        {
            if(tmp[i] != -1 && tmp[i] == 'a' || tmp[i] == 'e' || tmp[i] == 'i' || tmp[i] == 'o' || tmp[i] == 'u' )
            {
                cont++;
            }
        }

        if(cont != 1)
        {
            return false;
        }

        prima_volta = false;
        cont = 0;
        strcpy(tmp,token);
        token = strtok(NULL," ");
    }

    return true;
}
