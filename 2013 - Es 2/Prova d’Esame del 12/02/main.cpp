#include <iostream>
#include <cstring>

using namespace std;
const int n = 50;
void TriangoloEnigmistico(char[],int);

int main()
{
    char Parola[n];
    cin.getline(Parola,n);
    int dimParola = strlen(Parola);
    TriangoloEnigmistico(Parola,dimParola);
}

void TriangoloEnigmistico(char Parola[],int dimParola)
{
    int cont = 0;
    for(int i=0;i<dimParola;i++)
    {
        cout << " " << Parola[i] << " ";
    }
            cout << endl;

    while(cont < dimParola)
    {
        Parola[cont] = 32; // 32 rappresento lo spazio nel codice ASCII (non è necessario in questo snippet, basta anche un -1 ad es.)
        for(int j=0; j<dimParola; j++)
        {
            cout << " "  << Parola[j] << " ";
        }
          cout << endl;
        cont++;
    }
}
