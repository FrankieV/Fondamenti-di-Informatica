#include <iostream>

using namespace std;
int const posti_max = 11;
bool Fumatori(int[]);
bool NonFumatori(int[]);
bool Scan(int[]);
int main()
{
    int PostiAereo[posti_max] = {0};
    int posto;
    while(Scan(PostiAereo))
    {
        cout << " Digitare 1 per fumatori o 2 per non fumatori: ";
        cin >> posto;
        if(posto == 1)
        {
            if(Fumatori(PostiAereo) == false)
            {
                char cambia_reparto;
                cout << "  Reparto scelto al completo. Si desidera un posto nell'altro "
                     << "reparto (S/N)? ";
                cin >> cambia_reparto;
                if(cambia_reparto == 'S')
                {
                    NonFumatori(PostiAereo);
                }
                else
                {
                    cout << "  Il prossimo volo parte tra 3 ore " << endl << endl;
                }
            }
        }
        else
        {
            if(NonFumatori(PostiAereo) == false)
            {
                char cambia_reparto;
                cout << "  Reparto scelto al completo. Si desidera un posto nell'altro "
                     << "reparto (S/N)? ";
                cin >> cambia_reparto;
                if(cambia_reparto == 'S')
                {
                    Fumatori(PostiAereo);
                }
                else
                {
                    cout << "  Il prossimo volo parte tra 3 ore " << endl << endl;
                }
            }
        }
    }
    return 0;
}


bool Fumatori(int PostiAereo[])
{
    for(int posto = 1; posto<=5; posto++)
    {
        if(PostiAereo[posto] == 0)
        {
            PostiAereo[posto] = 1;
            cout << " Reparto fumatori, posto " << posto << endl << endl;
            return true;
        }
    }
    return false;
}

bool NonFumatori(int PostiAereo[])
{
    for(int posto = 6; posto<posti_max; posto++)
    {
        if(PostiAereo[posto] == 0)
        {
            PostiAereo[posto] = 1;
            cout << " Reparto NON fumatori, posto " << posto << endl << endl;
            return true;
        }
    }
    return false;
}

bool Scan(int PostiAereo[])
{
    for (int i= 1; i<posti_max; i++)
    {
        if(PostiAereo[i] == 0)
        {
            return true;
        }
    }
    return false;
}
