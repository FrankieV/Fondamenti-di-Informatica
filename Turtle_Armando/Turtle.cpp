#include <iostream>
using namespace std;

const int dim = 20;
const int n = 100;
bool penna_alzata = false;
int posj = 0;
int posi = 0;

void init_pavimento( int A[][dim])
{
	for( int i = 0; i < dim; i++)
	 {
	 	for( int j = 0; j < dim; j++)
	 		A[i][j]=0;
	 }
}


void init_array( int A[])
{
	for( int i = 0; i < n; i++)
		A[i]=9;
}

void inserisci_comandi( int A[])
{
	int comando, cont = 0;
	cin >> comando;
	while( comando != 9 && cont<n)
		{
			A[cont] = comando;
			cin >> comando;
			cont++;
		}
}


void est( int A[][dim])
{
	int passi;
	cout<<"passi? "<<endl;
	cin>>passi;
	if(passi >= dim - posj)
	{
      for( int j = posj+1;  j < dim; j++)
			{
			  if( penna_alzata == false)
    			A[posi][j]=1;
			  posj++;
		   }
	}
   else
    {
      for( int j = 0; j < passi; j++)
      {
      	posj++;
		if( penna_alzata == false)
			A[posi][posj]=1;
      }
	}
}

void sud( int A[][dim])
{
	int passi;
	cout<<"passi? "<<endl;
	cin >> passi;
	if( passi >= dim - posi)
	{
		for( int i = posi + 1; i < dim; i++)
			{
				if( penna_alzata == false)
					A[i][posj] = 1;
				posi++;
			}
	}
	else
	{
		for( int i = 0; i < passi; i++ )
			{
				posi++;
				if( penna_alzata == false)
					A[posi][posj]=1;
			}
	}
}

void ovest( int A[][dim])
{
	int passi;
	cout<<"passi? "<<endl;
	cin>>passi;
	if( passi >= posj)
		{
			for( int j = posj - 1; j >= 0; j--)
				{
				 if( penna_alzata == false)
				 	A[posi][j] = 1;
				 posj--;
				}
		}
	else 
		{
			for( int j = 0; j < passi; j++)
				{
					posj--;
					if( penna_alzata == false)
						A[posi][posj] = 1;
				}
		}
}

void nord( int A[][dim])
{
	int passi;
	cout<<"passi? "<<endl;
	cin>>passi;
	if( passi >= posi)
		{
			for( int i = posi - 1; i >= 0; i--)
				{
				 if( penna_alzata == false)
				 	A[i][posj] = 1;
				 posi--;
				}
		}
	else 
		{
			for( int i = 0; i < passi; i++)
				{
					posi--;
					if( penna_alzata == false)
						A[posi][posj] = 1;
				}
		}
}

void visualizzaPavimento ( int pavimento[] [dim], int dim)
{
	unsigned i,j;
	for(i = 0; i < dim; i++)
		{
			for(j = 0; j < dim; j++)
				if(pavimento[i][j] == 1)
					cout<<"*";
				else cout<<" ";
			cout<<endl;
		}
}

int main() 
{
    int comandi[n];
    int pavimento[dim][dim];
    int cont = 0;
    init_pavimento(pavimento);
    init_array(comandi);
    inserisci_comandi( comandi);
    while(comandi[cont] != 9)
    {
		switch( comandi[cont])
			{
				case 1:
					penna_alzata = true;
					break;
				case 2:
					penna_alzata = false;
					break;
				case 3:
					est(pavimento);
					break;
				case 4:
					ovest(pavimento);
					break;
				case 5:
					sud(pavimento);
					break;
				case 6:
					nord(pavimento);
					break;
				case 7:
					visualizzaPavimento(pavimento, dim);
					break;
			}
		cont++;
	}
	return 0;
}
