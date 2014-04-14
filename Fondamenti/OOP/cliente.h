#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

class Cliente
{
    public:
        char nome[20];
        char cognome[20];
        char indirizzo[30];
        void inserisci_nome( );
        void inserisci_cognome( );
        void inserisci_indirizzo( );
};

#endif // CLIENTE_H_INCLUDED
