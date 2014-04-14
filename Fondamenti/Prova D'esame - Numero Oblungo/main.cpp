#include <iostream>

using namespace std;
int VerificaOblungo(int);

int main()
{
    int N;
    cin >> N;
    int a = VerificaOblungo(N);
    if(a!=N)
    cout << a << "*" << a+1;
    else
    cout << "Nessun Oblungo";
}


int VerificaOblungo(int N)
{
    int a = 0;
    for(int i=0; i<N; i++)
    {
        if(a*(a+1) == N)
        {
            return a;
        }
        a++;
    }
    return N;
}
