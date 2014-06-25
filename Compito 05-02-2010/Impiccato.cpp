#include <iostream>
#include <cstring>
using namespace std;

void Parola_Segreta( char Nascosta[], int dim_nascosta)
{
	for( int i = 0; i < dim_nascosta; i++)
		{
			Nascosta[i] = '_';
			if( i == dim_nascosta - 1)
				Nascosta[dim_nascosta] = '\0';
		}
	cout << Nascosta << endl;
}

void scopri_lettera( char Parola[], char Nascosta[], char Lettera)
{
	char *ParolaPtr;
	ParolaPtr = Parola;
	bool trovata = false;
	char *NascostaPtr;
	NascostaPtr = Nascosta;
	for( int i = 0; i < strlen( Parola); i++)
		{
			if( Lettera == *ParolaPtr)
				{
					*NascostaPtr = Lettera;
					trovata = true;
				}
			NascostaPtr++;
			ParolaPtr++;
		}
	if( trovata == false)
		cout << "Sbagliato non c'e nessuna '" << Lettera << "' nella frase! RITENTA!" << endl;
	cout << Nascosta << endl;

}

bool parola_pensata( char Parola[])
{
	const int dim_pensata = strlen(Parola);
	char Pensata[dim_pensata];
	char carattere;
	for( int i = 0; i < dim_pensata; i++)
		{
			cin >> carattere; 
			Pensata[i] = carattere;
			if( i == dim_pensata-1)
				Pensata[dim_pensata] = '\0';
		}
	if( strcmp(Pensata, Parola) == 0)
		return true;
	else 
		return false;
}

bool controlla_nascosta( char Nascosta[])
{
	for( int i = 0; i < strlen(Nascosta); i++)
		{
	     	if( Nascosta[i] == '_')
			 	return false;		
		} 
	return true;
}

int main() 
{
	const int dim_parola = 100;
	char Parola[dim_parola];
	cin.getline( Parola, dim_parola);
	const int dim_nascosta = strlen(Parola);
	char Nascosta[dim_nascosta];
	Parola_Segreta(Nascosta, dim_nascosta);
	char Lettera;
	int numero_tentativi = 0;
	int risposta;
	while( numero_tentativi <= 7)
		{
			cout << "1 per inserire una lettera e 2 per una parola"<< endl;
			cin >> risposta;
			if( risposta == 1)
				{
					cout << "Inserisci lettera" << endl;
					cin >> Lettera;
					scopri_lettera(Parola, Nascosta, Lettera);
					if( controlla_nascosta( Nascosta))
						{
							cout << "INDOVINATO! La parola era " << Parola << endl;
							return 0;
						}
				}
			else	
				{
					if( risposta == 2)
						{
							cout << "Inserisci Parola" << endl;
							if( parola_pensata( Parola))
								{
									cout << "INDOVINATO! La parola era " << Parola << endl;
									return 0;
								}
							else
								cout << "SBAGLIATO" << endl;
					}
				}
			if (numero_tentativi == 0)
				{
					cout << "  __________ " << endl;
					cout << " |          | " << endl;
					cout << " |          | " << endl;
					cout << " |            " << endl;
					cout << " | " << endl;
					cout << " | " << endl;
					cout << " | " << endl;
					cout << " | " << endl;
					cout << " | " << endl;
					cout << "---" << endl;
				}
 			if( numero_tentativi == 1)
 				{
 					cout << "  __________ " << endl;
					cout << " |          | " << endl;
					cout << " |          | " << endl;
					cout << " |        (0 0) " << endl;
					cout << " | "<< endl;
					cout << " | " << endl;
					cout << " | " << endl;
					cout << " | " << endl;
					cout << " | " << endl;
					cout << "---" << endl;
 				}
 			if( numero_tentativi == 2)
 				{
 					cout << "  __________ " << endl;
					cout << " |          | " << endl;
					cout << " |          | " << endl;
					cout << " |        (0 0) " << endl;
					cout << " |          | "<< endl;
					cout << " |          | " << endl;
					cout << " |" << endl;
					cout << " |" << endl;
					cout << " |" << endl;
					cout << "---" << endl;
 				}	
 			if( numero_tentativi == 3)
 				{
 					cout << "  __________ " << endl;
					cout << " |          | " << endl;
					cout << " |          | " << endl;
					cout << " |        (0 0) " << endl;
					cout << " |        / | "<< endl;
					cout << " |          | " << endl;
					cout << " | " << endl;
					cout << " | " << endl;
					cout << " | " << endl;
					cout << "---" << endl;
 				}	
 			if( numero_tentativi == 4)
 				{
 					cout << "  __________ " << endl;
					cout << " |          | " << endl;
					cout << " |          | " << endl;
					cout << " |        (0 0) " << endl;
					cout << " |        / | \ "<< endl;
					cout << " |          | " << endl;
					cout << " | " << endl;
					cout << " | " << endl;
					cout << " | " << endl;
					cout << "--- " << endl;
 				}	
 			if( numero_tentativi == 5)
 				{
 					cout << "  __________ " << endl;
					cout << " |          | " << endl;
					cout << " |          | " << endl;
					cout << " |        (0 0) " << endl;
					cout << " |        / | \ "<< endl;
					cout << " |          | " << endl;
					cout << " |         / " << endl;
					cout << " | " << endl;
					cout << " | " << endl;
					cout << "-- -" << endl;
 				}	
 			if( numero_tentativi == 6)
 				{
 					cout << "  __________ " << endl;
					cout << " |          | " << endl;
					cout << " |          | " << endl;
					cout << " |        (0 0) " << endl;
					cout << " |        / | \ "<< endl;
					cout << " |          | " << endl;
					cout << " |         / \ " << endl;
					cout << " | " << endl;
					cout << " | " << endl;
					cout << " ---" << endl;
 				} 
 			numero_tentativi++;							
		}
	cout << "HAI PERSO!";
	return 0;
}
