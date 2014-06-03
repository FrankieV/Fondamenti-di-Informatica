#include <iostream>
#include <cstring>


using namespace std;

const int dim_max = 6;
void Leggi(char *, char *);
bool Verifica_Incastro(char*,char*,char*,char*);

int main()
{
    char A[dim_max];
    char B[dim_max];
    cin >> A >> B;
    char C[strlen(A)+strlen(B)];
    cin >> C;
    char Schema[strlen(C)];
    Leggi(Schema,C);
    if(Verifica_Incastro(A,B,C,Schema))
        cout << "Incastro ok";
    else
        cout << "Incastro NON possibile";


}

void Leggi(char Schema[], char * C)
{
    for(int i=0; i<strlen(C); i++)
    {
        cin >> Schema[i];
    }
}

bool Verifica_Incastro(char *A, char *B, char *C, char * Schema)
{
    int posA = 0;
    int posB = 0;
    for(int i=0; i<strlen(Schema); i++)
    {
        if(Schema[i] == 'a')
        {
            if(C[i] != A[posA])
                return false;

            posA++;
        }
        else if(Schema[i] == 'b')
        {
            if(C[i] != B[posB])
                return false;

            posB++;
        }
    }
    return true;

}


