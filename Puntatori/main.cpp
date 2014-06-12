#include <iostream>
#include <cstring>

using namespace std;



int main()
{
    int a = 10;
    int b = 2;
    int *p = &a;
    cout << *p << endl;

    *p = 3;
    cout << *p << endl;

    p = &b;
    cout << *p << "\n\n";

    int s = 5;
    int* punt = &s;
    int ** punt2 = &punt;
    int *** punt3 = &punt2;



    //**punt3 = &s;

    ***punt3 = 9;

   // **punt2 = 4;

    cout << **punt2 << endl;
    cout << *punt;

    cout << "\n\n";

    int A[4] = {8,2,3,4};

    cout << *A << endl; // Stampa il primo elemento dell'array
    cout << *(A+1) << endl; // Puntatore al secondo elemento dell'array

    *(A+1) = 5; // Cambio il valore al secondo elemento dell'array 2 diventa 5

    cout << *(A+1) << endl; // Oppure cout << A[1]

    *(A) = *(A+3);

    *A = *A;

    cout << *A << "\n\n";

    cout << "// ARITMETICA DEI PUNTATORI" << endl;

    int my_array[5] = {4, 2, 10, 7, 6};
    int my_array2[3] = {2,4,3};
    int *pt1 = my_array+1; // Punta al secondo elemento dell'array ovvero a 2
    pt1++; // pt1++ dovrebbe incrementare l'oggetto al quale punta (2) di uno, ovvero 2+1=3
   cout << *pt1 << endl; // Stampa 10 anzichè 3, perchè il valore di pt1 è stato incrementato di 4 byte (che è la dim. degli interi) e non di 1

   int *pt2 = my_array2;

    cout << *pt1 + *pt2 << endl;


    cout << "\n\n" << "// PUNTATORI COSTANTI E PUNTATORI A COSTANTI //" << endl;

    int x = 5;
    int e = 6;
    int* const ptr = &x; // Puntatore costante

    *ptr = 2; // Posso modificare l'oggetto puntato da ptr
    // *ptr = e; SI

    cout << *ptr << endl;

   // ptr = &e    NO! ptr non può cambiare valore

   const int H = 3;
   const int F = 5;
   const int *puntatore = &H;

//   *puntatore = 3; // NON posso modificare il valore a cui punta

   puntatore = &F; // Posso modificare il suo valore

   cout << *puntatore;

cout << "\n\n" << "// PUNTATORI  A STRUTTURE //" << endl;

struct persona
{
    char name[30];
    int eta;
    int peso;
    float altezza;
};

persona Impiegato = {"Frank Villella",19,67,1.78};
persona *P_persona;
P_persona = &Impiegato;

cout << P_persona->eta << endl;
cout << Impiegato.eta;

cout << "\n\n" << "// ARRAY DI PUNTATORI //" << endl;

int *array_int[10]; // array di puntatori


char *P_CHAR = new char[100]; // array dinamico di 100 caratteri

*P_CHAR = 'F';
P_CHAR[1] = 'R';
cout << *(P_CHAR+1) << endl; // Stampa R
P_CHAR[2] = '\0';
cout << P_CHAR << endl; // stampa FR
*P_CHAR = *(P_CHAR+1);
cout << P_CHAR << endl;

char *P_CHAR2 = new char[50];

strcpy(P_CHAR2,P_CHAR);

cout << "char2: " << P_CHAR2; // Non copia la F perchè *P_CHAR = *(P_CHAR+1), ovvero punta al secondo carattere

// P_CHAR = new char[200]; // Posso creare allocare più memoria

int *f = new int;
*f = 10;


cout << endl<< *f << endl;

delete f;

//cout << *f << endl;

f = new int; // Rialloco la mamoria
*f = 10;

cout << *f << endl;



int Arr[5] = {1,2,3,4,5};
int sum = 0;
int *ptr_2 = Arr+4;
while(ptr_2 >= Arr)
{
sum += *ptr_2;
ptr_2--;
}
cout << sum << endl;


int ex[3] = {2,1,5};

int * Asd[10];
for(int i =0; i<10; i++)
Asd[i]=ex;


cout << *Asd[3] << endl;

int * ptr33 = new int[15] ;

ptr33[2] = 2;

cout << ptr33[2]+2 << endl;
cout << *(ptr33+2) +2; // stesso risultato di sopra.



}
