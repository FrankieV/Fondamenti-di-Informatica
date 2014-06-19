#include <iostream>

using namespace std;
int VerificaOblungo(int,int,int);

int main()
{
    int N;
    cin >> N;
    int incr = 0;
    int i = 0;
    int a = VerificaOblungo(N,incr,i);
    if(a!=N)
    cout << a << "*" << a+1;
    else
    cout << "Nessun Oblungo";
}


int VerificaOblungo(int N,int a, int i)
{
    while(i<N)
    {
        if(a*(a+1) == N)
        {
            return a;
        }
        return VerificaOblungo(N,a+=1,i+=1);
    }
    return N;
}
