using namespace std;
int main()
{

int i=2, a;

cout<<"Inserisci un numero: ";
cin>>a;
while (a%i!=0){
      i++;}

if (a==i)
   cout<<"E' primo!"<<endl;
else
   cout<<"NON e' primo!"<<endl;


}
