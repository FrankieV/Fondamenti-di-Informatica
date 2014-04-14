#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

const char WHITE = ' ';
const char BLACK = 'X';
const char PEDINANERA = 'N';
const char PEDINABIANCA = 'B';
const int SIZE = 8;
const int TOINSERT = 5;

void fill(char toFill[SIZE][SIZE]) {
for (int y=0; y<SIZE; y++) {
for (int x=0; x<SIZE; x++) {
if (y%2==0 && x%2==0) {
toFill[y][x]=WHITE;
}
else if (y%2==0 && x%2!=0) {
toFill[y][x]=BLACK;
}
else if (y%2!=0 && x%2==0) {
toFill[y][x]=BLACK;
}
else toFill[y][x]=WHITE;
}
}
}

void randomInsert(char toInsert[SIZE][SIZE], char symbol) {
int newX,newY;
for (int i=1; i<=TOINSERT; i++) {
do {
newY = rand()%SIZE;
newX = rand()%SIZE;
}
while (toInsert[newY][newX]!=BLACK);
toInsert[newY][newX]=symbol;
}
}

void result(int biancaX, int neraY, int neraX) {
int biancaY = neraY+1;
cout <<"Pedina nera in "<<char(neraX+'A')
<<abs(neraY-8)<<" catturabile da pedina bianca "
<<char(biancaX+'A')<<abs(biancaY-8)<<endl;
}

void catchable(char scacchiera[SIZE][SIZE]) {
int catched= 0;
for (int y=0; y<SIZE-1; y++) {
for (int x=0; x<SIZE; x++) {
if (scacchiera[y][x]==PEDINANERA) {
if (x+1<SIZE && y-1>=0 && scacchiera[y+1][x+1]==PEDINABIANCA && scacchiera[y-1][x-1]==BLACK) {
result(x+1, y,x);
catched++;
}
if (x-1>=0 && y-1>=0 && scacchiera[y+1][x-1]==PEDINABIANCA && scacchiera[y-1][x+1]==BLACK) {
result (x-1, y,x);
catched++;
}
}
}
}
if (catched==0) cout<<"Nessuna pedina nera e' catturabile da alcuna pedina bianca";
}

void show(char toShow[SIZE][SIZE]) {
char start = 'A';
cout <<" -";
for (int i=0; i<SIZE; i++) {
cout <<start;
start++;
}

cout <<endl<<endl;
int counter = SIZE;
for (int y=0; y<SIZE; y++) {
cout <<counter << " ";
counter--;
for (int x=0; x<SIZE; x++) {
cout<< toShow[y][x];
}
cout<<endl;
}
cout<<endl;
}

int main()
{
srand(time(NULL));
char scacchiera[SIZE][SIZE];
char command;
do {
fill(scacchiera);
randomInsert(scacchiera,PEDINANERA);
randomInsert(scacchiera,PEDINABIANCA);
show(scacchiera);
catchable(scacchiera);
cout<<endl;
cout<<"Premere 's' per rifare il test"<<endl;

cin>>command;
cout<<endl<<endl;
}
while (command=='s');


return 0;
}
