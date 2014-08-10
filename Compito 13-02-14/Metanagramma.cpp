#include <iostream>
#include <cstring>
using namespace std;

bool Metanagramma( char Elenco[])
{
    const int Dim_Elenco = strlen( Elenco);
    char *Parola_Prec;
    char *Parola_Suc;
    Parola_Prec = strtok( Elenco, " ");
    Parola_Suc = strtok ( NULL, " ");
    char Parola_Precedente[Dim_Elenco];
    char Parola_Successiva[Dim_Elenco];
    strcpy( Parola_Precedente, Parola_Prec);
    strcpy( Parola_Successiva, Parola_Suc);
    const int Dim_Parola = strlen( Parola_Precedente);
    int Cont_Lettere_Uguali = 0;
    int Cont_Vocali = 0;
    bool Lettera_Trovata = false;
    bool Ultima_Volta = false;
    for( int a = 1; a < 5 ; a++)
        {
            for( int i = 0; i < Dim_Parola; i++)
                {
                    for( int j = 0; j < Dim_Parola; j++)
                        {

                            if(( Parola_Precedente[i] == Parola_Successiva[j]) &&( Lettera_Trovata == false))
                                {
                                    Parola_Successiva[j] = '*';
                                    Cont_Lettere_Uguali++;
                                    Lettera_Trovata = true;
                                }
                            else
                                {
                                    if(( Lettera_Trovata == false) && ( j == Dim_Parola-1) && ( Parola_Precedente[i] == 'a' || Parola_Precedente[i] == 'e' || Parola_Precedente[i] == 'i' || Parola_Precedente[i] == 'o' || Parola_Precedente[i] == 'u'))
                                        {
                                            if( Cont_Vocali == 0)
                                               {
                                                    Cont_Vocali++;
                                               }
                                            else
                                                    return false;
                                        }
                                }
                        }
                    Lettera_Trovata = false;
                }

            if( a == 4)
                Ultima_Volta = true;
            if(( Cont_Lettere_Uguali == Dim_Parola) || ( Cont_Lettere_Uguali + Cont_Vocali == Dim_Parola))
                {
                    strcpy( Parola_Prec, Parola_Suc);
                    Parola_Suc = strtok( NULL, " ");
                    if( Ultima_Volta == false)
                        {
                            strcpy( Parola_Precedente, Parola_Prec);
                            strcpy( Parola_Successiva, Parola_Suc);
                        }
                    Cont_Vocali = 0;
                    Cont_Lettere_Uguali = 0;
                }
            else
                return false;
        }
    return true;
}

int main()
{
    const int Dim_Elenco = 100;
    char Elenco[Dim_Elenco];
    cin.getline( Elenco, Dim_Elenco);
    if( Metanagramma( Elenco))
        cout << "E' un metanagramma! ";
    else
        cout << "Non e' un metanagramma! ";
    return 0;
}
