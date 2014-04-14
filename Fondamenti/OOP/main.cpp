#include <iostream>
#include "cliente.h"


using namespace std;

    void Cliente::inserisci_nome()
    {
        cout << "Inserisci il tuo nome ";
        cin >> nome;
        cout << endl;
    }

     void Cliente::inserisci_cognome()
     {
        cout << "Inserisci il tuo cognome ";
        cin >> cognome;
        cout << endl;
     }

     void Cliente::inserisci_indirizzo()
     {
        cout << "Inserisci il tuo indrizzo ";
        cin >> indirizzo;
        cout << endl;
     }

int main()
{
    Cliente client;
    client.inserisci_cognome();
    client.inserisci_nome();
    client.inserisci_indirizzo();

    cout << "Nome: " << client.nome << "\n Cognome: " << client.cognome << "\n Indirizzo: " << client.indirizzo;

}
