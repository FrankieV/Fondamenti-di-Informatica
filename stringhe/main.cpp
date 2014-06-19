#include <iostream>
#include <cstring>
using namespace std;

// ARRAY DI CARATTERI

int main()
{
    const int dim = 20;
    char A[dim];
//    char F[];

    cin.getline(A,dim);

    char B[strlen(A)];

    strcpy(B,A);


//    bool uguali = true;
//    for(int i=0; i<=strlen(B); i++)
//    {
//        if(B[i] != C[i])
//        {
//           uguali = false;
//        }
//    }
//
//    if(uguali == false)
//    {
//        cout << "Le parole non sono uguali.";
//    }
//    else
//    {
//        cout << "Ok =)";
//    }

//    if(strcmp(B,C) != 0 )
//    {
//        cout << "NOn sono uguali";
//    }
//
//   if(strcmp(B,C) == 0)
//   {
//       cout << "Le parole sono uguali";
//   }
//   else
//   {
//       cout << "Le parole non sono uguali";
//   }

//    char D[strlen(B) + strlen(C)];
//
//    int dim_Max = strlen(B) + strlen(C);
//    int cont = 0;
//
//    for(int i = 0; i < strlen(B); i++)
//    {
//        D[i] = B[i];
//    }
//    for(int i=strlen(B); i <= dim_Max; i++)
//    {
//        D[i] = C[cont];
//        cont++;
//    }

//    strcat(C,B);
//    char D[strlen(C)];
//    strcpy(D,C);
//    cout << D;







    char C[15] = "salve a tutti";
    char *token = strtok((C+3)," ");
    while(token != NULL)
    {
        cout << token << endl;
        token = strtok(NULL," ");
    }

//    int delim = '\0';  // IL VALORE di \0 è zero.
//    cout << delim;






}

