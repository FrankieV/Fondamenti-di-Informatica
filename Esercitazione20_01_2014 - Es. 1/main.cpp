#include <iostream>
#include <cstring>

using namespace std;
const int n = 20;
void hideParola(char[],char[]);

int main()
{
    unsigned int tentativi = 0,
    char parolaSegreta[n];
    cin.getline(parolaSegreta,n, '\n');
    char copiaParola[parolaSegreta.strlen()];
    hideParola(parolaSegreta,copiaParola);

    while(tentativi < 7)
    {
        char inserisciParola[n];
        cout << "Inserisci un carattere o l'intera parola: ";
        cin.getline(inserisciParola,n);
    }
}

void hideParola(char Parola[], char CopiaParola[])
{
    strcpy(CopiaParola,Parola);
    for(int i = 0; i < CopiaParola.strlen();i++)
    {
        CopiaParola[i] = " _";
        cout << CopiaParola[i];
    }

}
