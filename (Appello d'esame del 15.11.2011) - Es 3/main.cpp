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
    int posI = 0;
    int posJ = 0;
    int A[N*N] = {-1};
    int pos = 0;
    int tmp[N*N] = {-1};
    int cont = 0;
    bool prima_volta = true;

    while(posI != N/2 && posJ != N/2)
    {
        for(int j = 0; j<N-cont; j++)
        {
            A[pos] = M[posI][j];
            pos++;
            posJ++;
        }

        for(int i = posI; i<N-cont; i++)
        {
            A[pos] = M[i][posJ-1];
            pos++;
            posI++;
        }

        for(int j = posJ; j>=cont; j--)
        {
            A[pos] = M[posI-1][j];
            pos++;
            posJ--;
        }

        for(int i = posI; i>=cont; i--)
        {
            A[pos] = M[i][posJ+1];
            pos++;
            posI--;
        }

        if(prima_volta)
        {
            for(int i = 0; i < N*N; i++)
            {
                tmp[i] = A[i];
                prima_volta = false;
            }
        }

            for(int i = 0; i < N*N; i++)
            {
                cout << A[i];
            }

//        else
//        {
//            for(int i = 0; i < N*N; i++)
//            {
//                for(int j = 0; j < N*N; j++)
//                {
//                    while(A[i] != -1)
//                    {
//                        if(A[i] > tmp[i])
//                        {
//                            return false;
//                        }
//                    }
//                }
//            }
//
//            for(int i = 0; i < N*N; i++)
//            {
//                tmp[i] = A[i];
//            }
//        }

        cont++;
        posI++;
        posJ++;
        pos = 0;
    }

    return true;
}
