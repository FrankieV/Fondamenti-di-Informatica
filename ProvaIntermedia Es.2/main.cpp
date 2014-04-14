/* Esercizio 2. Si scriva in C++ un programma che, letta da input una sequenza di naturali terminata dal tappo 0 0
(ZERO ZERO), ed evitando l’uso degli array, stampi su standard output la stringa “TROVATO” se nella sequenza è
presente almeno un elemento il cui valore è pari alla posizione che occupa nella sequenza (si noti che il primo
elemento occupa la posizione 1).
ESEMPIO: Se la sequenza letta da input fosse 5 3 2 1 6 8 7 5 9 0 0 il programma dovrebbe stampare “TROVATO”
poiché l’elemento 7 occupa la posizione 7. Si noti che anche l’elemento 9 soddisfa la proprietà ma il programma deve
stampare la stringa “TROVATO” una sola volta.*/

#include <iostream>

using namespace std;

int main()
{
    int prec;
    int corr;
    int pos = 0;
    bool trovato = false;
    cin >> prec;
    cin >> corr;
    while(prec != 0 || corr != 0 )
    {
        pos++;
        if(pos == corr)
        {
            trovato = true;
        }
        prec =  corr;
        cin >> corr;
    }
    if(trovato)
    {
        cout << "TROVATO";
    }
}
