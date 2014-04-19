#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string.h>

using namespace std;
int EstraiOperando();
char EstraiOperatore();
void EffettuaOperazione(int, int, char);
void RispostaCorretta();
void RispostaErrata(int,int,char);



int main()
{
    srand(time(NULL));

    int numA = EstraiOperando();
    int numB = EstraiOperando();
    char operatore = EstraiOperatore();

    EffettuaOperazione(numA,numB,operatore);
}


int EstraiOperando()
{
    return rand() % 10 + 1;
}

char EstraiOperatore()
{
    char operatori[] = "+-*/";
    return operatori[rand() % strlen(operatori)];
}

void EffettuaOperazione(int numA, int numB, char op)
{
    int num = 0;

    switch(op)
    {
    case '+':
        int somma;
        somma = numA + numB;
        cout << "Quanto fa " << numA << "+" << numB << "?" << endl;
        cin >> num;
        if(num == somma)
        {
            RispostaCorretta();
        }
        else
        {
            RispostaErrata(numA,numB,op);
        }
        break;
    case '-':
        int differenza;
        differenza = abs(numA-numB);
        cout << "Quanto fa " << numA << "-" << numB << "?" << endl;
        cin >> num;
        if(num == differenza)
        {
            RispostaCorretta();
        }
        else
        {
            RispostaErrata(numA,numB,op);
        }
        break;
    case '*':
        int moltiplicazione;
        moltiplicazione = numA * numB;
        cout << "Quanto fa " << numA << "*" << numB << "?" << endl;
        cin >> num;
        if(num == moltiplicazione)
        {
            RispostaCorretta();
        }
        else
        {
            RispostaErrata(numA,numB,op);
        }
        break;
    case '/':
        int divisione;
        divisione = numA / numB;
        cout << "Quanto fa " << numA << "/" << numB << "?" << endl;
        cin >> num;
        if(num == divisione)
        {
            RispostaCorretta();
        }
        else
        {
            RispostaErrata(numA,numB,op);
        }
        break;
    }
}

void RispostaCorretta()
{
    int n = rand() % 4;
    switch(n)
    {
    case 0:
        cout << "Bravo!";
        break;
    case 1:
        cout << "Eccellente!";
        break;
    case 2:
        cout << "Continua Cosi'!";
        break;
    case 3:
        cout << "Ottimo Lavoro!";
        break;
    }
}

void RispostaErrata(int numA,int numB,char operatore)
{
    int n = rand() % 4;
    switch(n)
    {
    case 0:
        cout << "No, riprova!" << endl;
        break;
    case 1:
        cout << "Sbagliato. Prova ancora!" << endl;
        break;
    case 2:
        cout << "Non ti arrendere, riprova!" << endl;
        break;
    case 3:
        cout << "Niente da fare, Prova ancora!" << endl;
        break;
    }

    EffettuaOperazione(numA,numB,operatore);
}
