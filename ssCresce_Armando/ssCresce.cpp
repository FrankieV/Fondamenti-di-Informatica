# include <iostream>
using namespace std;
bool init_sequenza( int A[], int dim)//funziona alla perfezione
{
	int n;
	int e=0;
	for(int i = 0; i < dim ; i++)
		{
			A[i]=-1;
		}
 	cin>>n;
 	if (n < 0)
 	 {
 	  cout<<"Empty";
 	  return false;
     }
	else
	 {
    	while( n >= 0)
 	 	 	{
 	 			A[e]=n;
 	 			cin>>n;
 	 			e++;
 	 		}
	}
	return true;
}

int crescente_maggiore( int A[], int &maggiore, int &indice)//funziona perfettamente
{
	int e=0;
	int cont=1;
	while( A[e] != -1)
	 {
	 	if( A[e] <= A[e+1])
	 		{
	 		cont++;
	 	    }
		else 
	 		{
	 			if( cont > maggiore)
	 				{
	 					maggiore=cont;
	 					indice=(e+1)-maggiore;
	 				}
  				cont=1;
	 		}
	 	e++;
	 }
}

void StampaSequenzaMaggiore( int A[], int i)
{
	while( A[i] <= A[i+1])
	 {
	 	cout<<A[i];
	 	i++;
	 }
	cout<<A[i]<<endl;;
}

int main()
{
	const int dim=100;
	int A[dim];
	int indice=0;
	int massimo=0;
	if(init_sequenza( A, dim))
	 {
	  crescente_maggiore(A,massimo,indice);
	  StampaSequenzaMaggiore(A, indice);
	  cout<<massimo;
	 }
	return 0;
}
