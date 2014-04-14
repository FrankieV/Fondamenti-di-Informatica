#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
   string player_name;
   string start_game;
   int num_partite;
   char giocata_cpu;
   char giocata_player;
   int vinte_player = 0, vinte_cpu = 0, pareggio = 0;
   string fine_partita ="";

   cout << "- Morra Cinese v.2.0  - " << endl;;
   cout << "Salve, inserisci il tuo nome per iniziare a giocare... \n Nome: ------> ";
   cin >> player_name;
   cout << "\nBenvenuto " << player_name << " =D\n\n";
   cout << "********** REGOLE **********"<< endl;
   cout << " 1. Puoi scegliere tre elementi (uno per volta)\n 2. Per scegliere il sasso digita s \n 3. Per scegliere la carta digita c \n 4. Per scegliere la forbice digita f\n";
   cout << "****************************\n";
   while(start_game != "start")
   {
      cout << "Digita start quando vuoi iniziare la partita\n ----->";
      cin >> start_game;
   }
    cout << "Gentile " << player_name << ", quante partite intendi giocare?\n -----> ";
    cin >> num_partite;

    srand(time(0));

   for(int i = 0; i < num_partite; i++)
   {
       int d1 = rand() % 3+1;

       switch(d1)
       {
       case 1:
        giocata_cpu = 'c';
        break;
       case 2:
        giocata_cpu = 'f';
        break;
       case 3:
        giocata_cpu = 's';
        break;
       }

       cout << player_name << " Immetti la tua giocata\n ----> ";
       cin >> giocata_player;

    cout << "CPU ha giocato " << giocata_cpu << " " << player_name << " ha giocato " << giocata_player << endl;

       if(giocata_cpu != giocata_player)
       {
       if((giocata_cpu == 's' && giocata_player == 'f') || (giocata_cpu == 'f' && giocata_player == 'c') || (giocata_cpu == 'c' && giocata_player == 's'))
       {
           cout << "Vince CPU" << endl;
           vinte_cpu += 1;
       }

       if ((giocata_cpu == 'c' && giocata_player == 'f') || (giocata_cpu == 's' && giocata_player == 'c') || (giocata_cpu == 'f' && giocata_player == 's'))
       {
            cout << "Vince " << player_name << endl;
            vinte_player += 1;
       }
       }
    else
    {
        cout << "Pareggio =D" << endl;
        pareggio += 1;
    }

   }

   if(vinte_player > vinte_cpu)
   {
       cout << "\n" << player_name << " ha vinto la sfida con " << vinte_player << " partite vinte,";
       cout << " CPU ne ha vinte " << vinte_cpu;
       cout << " |Tot pareggi|: " << pareggio << endl;
       cout << "Percuntuale partite vinte da " << player_name << " " << ((float)vinte_player / num_partite)*100<<"%"<< endl;
       cout << "Percuntuale partite vinte da CPU " << ((float)vinte_cpu/num_partite)*100<< "%" << endl;


   }
   else if(vinte_player < vinte_cpu)
   {
       cout << "\nCPU ha vinto la sfida con " << vinte_cpu << " partite vinte,";
       cout << " " << player_name << " ne ha vinte " << vinte_player;
       cout << " Tot pareggi: " << pareggio << endl;
       cout << "Percuntuale partite vinte da " << player_name << " " << ((float)vinte_player/num_partite)*100 << "%" << endl;
       cout << "Percuntuale partite vinte da CPU " << ((float)vinte_cpu/num_partite)*100 << "%" << endl;
   }
   else if (vinte_player == vinte_cpu)
   {
       cout << "La partita si è conclusa in pareggio =)" << endl;
   }


while(fine_partita != "gioca" || fine_partita != "exit")
{
cout << "\nLa partita si e' conclusa, digita gioca se intendi effettuare un'altra partita, digita exit se vuoi uscire ---->";
cin >> fine_partita;

if(fine_partita == "gioca")
{
    main();
}
else if(fine_partita == "exit")
{
    exit(0);
}
else
{
    cout << "Parola non riconosciuta";
}

}

}
