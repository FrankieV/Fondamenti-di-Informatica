#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void Gadget();

unsigned int Pasti_Adulti = 0;
unsigned int Pasti_Bambini = 0;
unsigned int gadget_Nana = 0;
unsigned int gadget_HelloSpank = 0;
unsigned int gadget_Bum = 0;
unsigned int gadget_GigiLaTrottola = 0;
unsigned int gadget_George = 0;


int main()
{
    srand(time(0));
    char scelta;


    while(scelta != 'Z')
    {
        cout << "Pasto per bambini o pasto per adulti? (B/A/Z per terminare)" << endl;
        cin >> scelta;

        switch(scelta)
        {
        case 'B':
        {
            char si_no;
            cout << "Si desidera un gadget? (S/N)" << endl;
            cin >> si_no;
            if(si_no == 'S')
            {
                Gadget();
            }
            Pasti_Bambini++;
            break;
        }
        case 'A':
        {
            Pasti_Adulti++;
            break;
        }
        }
    }

    cout << "Pasti per adulti: " << Pasti_Adulti << endl;
    cout << "Pasti per bambini: " << Pasti_Bambini << endl;
    cout << "Nana': " << gadget_Nana << endl;
    cout << "Hello Spank: " << gadget_HelloSpank << endl;
    cout << "Bum Bum: " << gadget_Bum << endl;
    cout << "Gigi la Trottola: " << gadget_GigiLaTrottola << endl;
    cout << "George il Re della Giungla: " << gadget_George << endl;
}

void Gadget()
{
    int estrai_gadget = rand() % 5;

    switch(estrai_gadget)
    {
    case 0:
        cout << "Nana'" << endl;
        gadget_Nana++;
        break;
    case 1:
        cout << "Hello Spank" << endl;
        gadget_HelloSpank++;
        break;
    case 2:
        cout << "Gigi la Trottola" << endl;
        gadget_GigiLaTrottola++;
        break;

    case 3:
        cout << "Bum Bum" << endl;
        gadget_Bum++;
        break;

    case 4:
        cout << "George il Re della Giungla" << endl;
        gadget_George++;
        break;
    }
}
