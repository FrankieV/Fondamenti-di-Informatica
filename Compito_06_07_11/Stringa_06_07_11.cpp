#include <iostream>
#include <cstring>
using namespace std;

bool increasing_sentence( char A[], int dim)
{
	char B[dim];
	strcpy( B, A);
	char *tokenPtr;
	char *tokenPtr2;
	int word_compare;
	tokenPtr = strtok( B," ");
	tokenPtr2 = tokenPtr;
	while( tokenPtr != NULL)
		{
			word_compare = strcmp( tokenPtr2, tokenPtr);
			if( word_compare > 0)
				return false;
			tokenPtr2 = tokenPtr;
			tokenPtr = strtok( NULL, " ");
		}
	return true;
}


void shortest_word(char A[], int dim)
{
	char B[dim];
	strcpy( B, A);
	char *tokenPtr;
	char *token_min_lenght;
	int lenght;
	int min_lenght;
	tokenPtr = strtok( B, " ");
	token_min_lenght = tokenPtr;
	min_lenght = strlen( tokenPtr);
	while( tokenPtr != NULL)
		{
			if(( strlen( tokenPtr)) < min_lenght)
				{
					min_lenght = strlen( tokenPtr);
					token_min_lenght = tokenPtr;
				}
			tokenPtr = strtok( NULL, " ");
		}
	cout << "Parola piu' corta : " << token_min_lenght << " con lunghezza " << min_lenght << endl;
}


void scarto_media( char A[], int dim)
{
	char B[dim];
	strcpy( B, A);
	char *tokenPtr;
	char *tokenPtr2;
	int cont = 0;
	int somma = 0;
	int media;
	tokenPtr = strtok( B, " ");
	while( tokenPtr != NULL)
		{
			tokenPtr2 = tokenPtr;
			somma += strlen( tokenPtr2);
			cont++;
			tokenPtr = strtok( NULL, " ");
		}	
	media = somma / cont;
	cout << "Media delle lunghezze : " << media << " scarti : ";
	tokenPtr = strtok( A, " ");
	while( tokenPtr != NULL)
		{
			int word_lenght = strlen ( tokenPtr);
			cout << tokenPtr << " " << media - word_lenght << ", ";
			tokenPtr = strtok ( NULL, " ");			
		}
	cout << endl;
}


int main() 
{
	const int dim = 100;
	char A[dim];
	cin.getline( A, dim);
	if ( increasing_sentence( A , dim))
		cout << "Frase Crescente " << endl;
	else 
		cout << "Frase NON Crescente " << endl;
	shortest_word( A, dim);
	scarto_media( A, dim);
	return 0;
}
