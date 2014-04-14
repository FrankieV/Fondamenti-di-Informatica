#include <iostream>

using namespace std;
const int dim = 20;
const int n = 100;
int M[dim][dim] = {0};
int Posizione[dim][dim];
int LeggiComandi(int[]);
void EseguiComandi(int[],int);
bool pennaAlzata = false;
bool pennaAbbassata = true;
void Est();
void visualizzaPavimento();
int posizioneRiga = 0;
int posizioneColonna = 0;

int main()
{
    Posizione[0][0];
    int Comandi[n];
    int dimComandi = LeggiComandi(Comandi);
    EseguiComandi(Comandi,dimComandi);

    return 0;

}


int LeggiComandi(int V[])
{
    int seq;
    int pos = 0;
    cin >> seq;
    while(seq != 9 && seq < n)
    {
        if(seq != 8)
        {
            V[pos] = seq;
            pos++;
        }
        cin >> seq;
    }
    return pos;
}

void EseguiComandi(int Comandi[],int dimComandi)
{
    int comando = 0;

    for(int i=0; i<dimComandi; i++)
    {
        comando = Comandi[i];

        switch(comando)
        {
        case 1:
            pennaAbbassata = false;
            pennaAlzata = true;
            break;
        case 2:
             pennaAlzata = false;
            pennaAbbassata = true;
            break;
        case 3:
            Est();
            break;
        case 4:
            //Ovest();
            break;
        case 5:
            //   Sud();
            break;
        case 6:
            //  Nord();
            break;
        case 7:
            visualizzaPavimento();
            break;
        default:
            break;
        }
    }
}

void Est()
{
    int passi;
    cout<<"passi? "<<endl;
    cin >> passi;
    if(passi < dim && (posizioneColonna + passi) < dim )
    {
        if(pennaAbbassata)
        {
            for(int i=1; i<=passi; i++)
            {
                M[posizioneRiga][i] = 1;
                posizioneColonna = i;
            }
        }
        else if(pennaAlzata)
        {
            posizioneColonna = passi;
        }
    }
    else
    {
        if(pennaAbbassata)
        {
            for(int i=1; i<dim; i++)
            {
                M[posizioneRiga][i] = 1;
                posizioneColonna = i;

            }
        }
        else if(pennaAlzata)
        {
            posizioneColonna = passi;
        }
    }


}

void visualizzaPavimento()
{
    unsigned i,j;
    for (i=0; i<dim; i++)
    {
        for (j=0; j<dim; j++)
            if (M[i][j]== 1)
                cout<<"*";
            else cout<<" ";
        cout<<endl;
    }
}
