#include <iostream>

using namespace std;

const int N = 5;
void init_Cornici(int [][N]);
bool Cornici_decr(int [][N]);

int main()
{
    int M[N][N];
    init_Cornici(M);
    if(Cornici_decr(M))
        cout << "OK";
    else
        cout << "NO";
}

void init_Cornici(int M[][N])
{
    for(int i=0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> M[i][j];
        }
    }
}

bool Cornici_decr(int M [][N])
{
    int pos_I = 0;
    int pos_J = 0;
    int A[N*N] = {0};
    int temp[N*N] = {0};
    int index = 0;
    int cont = 0;
    bool prima_volta = true;

    while(pos_I < N/2 && pos_J < N/2)
    {
        for(int i = 0; i < N*N; i++)
        {
            A[i] = 0;
        }

        for(int j = pos_J; j < N -index; j++)
        {
            A[cont] = M[pos_I][j];
            cont++;
        }

        for(int i = pos_I; i < N -index; i++)
        {
            A[cont] = M[i][pos_J];
            cont++;
        }

        for(int i = pos_I; i < (N-1)-index; i++)
        {
            A[cont] = M[i][(N-1)-index];
            cont++;
        }

        for(int j = (N-1)-index ; j > 0; j--)
        {
            A[cont] = M[(N-1)-index][j];
            cont++;
        }

        if(prima_volta)
        {
            for(int i = 0; i < N*N; i++)
            {
                temp[i] = A[i];
            }
            prima_volta = false;
        }
        else
        {
//            for(int i = 0; i < N*N; i++)
//            {
//                cout << " " << A[i];
//            }
//
//            cout << endl;
//
//            for(int i = 0; i < N*N; i++)
//            {
//                cout << " " << temp[i];
//            }

            for(int i = 0; i < N*N; i++)
            {
                for(int j = 0; j < N*N; j++)
                {
                    if(A[i] != 0 && temp[j] != 0)
                    {
                        if(A[i] >= temp[j])
                        {
                            return false;
                        }
                    }
                }
            }

            for(int i = 0; i < N*N; i++)
            {
                temp[i] = 0;
            }


            for(int i = 0; i < N*N; i++)
            {
                temp[i] = A[i];
            }
        }

        index++;
        pos_I++;
        pos_J++;
        cont = 0;
    }

    for(int i = 0; i < N*N; i++)
    {
        if(temp[i] != 0)
        {
            if(temp[i] <= M[N/2][N/2])
                return false;
        }
    }

    return true;

}
