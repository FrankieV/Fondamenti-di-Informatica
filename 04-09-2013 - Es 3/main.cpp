#include <iostream>
using namespace std;
const int dim = 10;
void Prodotto_Triple(int A[],int dim,int molt, int pos_1, int pos_2);

int main()
{
    int A[dim] = {1,8,4,3,2,6,5,9,10,11};
    int moltiplicando = 0;
    int pos_1 = 1;
    int pos_2 = 2;
    Prodotto_Triple(A,dim,moltiplicando,pos_1,pos_2);

}

void Prodotto_Triple(int A[],int dim,int molt, int pos_1, int pos_2)
{
    while(molt < dim)
    {
        while(pos_1 < dim-1)
        {
            while(pos_2 < dim)
            {
                if(pos_1 != molt)
                {
                    if(pos_2 != molt && pos_2 != pos_1)
                    {
                        if(A[molt] != A[pos_1] * A[pos_2])
                        {
                            return Prodotto_Triple(A,dim,molt,pos_1,pos_2+=1);
                        }
                        else
                        {
                            cout << molt << " " << pos_1 << " " << pos_2 << endl;
//                            cout << A[molt] << " = " << A[pos_1] << " * " << A[pos_2];
                            break;
                        }
                    }
                    else
                    {
                         return Prodotto_Triple(A,dim,molt,pos_1,pos_2+=1);
                    }
                }
                else
                {
                     return Prodotto_Triple(A,dim,molt,pos_1+=1,pos_2);
                }
            }

            return Prodotto_Triple(A,dim,molt,pos_1+=1, pos_2 = pos_1+1);
        }

        return Prodotto_Triple(A,dim,molt+=1, pos_1 = 0, pos_2 = 1);
    }
}
