#include <stdio.h>
#include <conio.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char gameboard[3][3];
const char PLAYER='X';
const char COMPUTER='O';
void rboard();//function to reset the board
void pboard();
int checkvacantspaces();
void playermove();
void computermove();
char cwinner();
void displaywinner(char);

int main()
{char winner =' ';

rboard();

while(winner == ' ' && checkvacantspaces() !=0)
{
    pboard();

    playermove();

    winner = cwinner();
    if(winner != ' ' || checkvacantspaces()==0)
    {
        break;
    }
   
   computermove();

    winner = cwinner();
    if(winner != ' ' || checkvacantspaces()==0)
    {
        break;
    }
   
}
pboard();
    displaywinner(winner);
return 0;
}


void rboard(){

for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        gameboard[i][j]= ' ';

    }
}

}
void pboard()
{
  printf(" %c | %c | %c", gameboard[0][0], gameboard[0][1],gameboard[0][2]);
  printf("\n---|---|---\n");
  printf(" %c | %c | %c", gameboard[1][0], gameboard[1][1],gameboard[1][2]);
  printf("\n---|---|---\n");
  printf(" %c | %c | %c", gameboard[2][0], gameboard[2][1],gameboard[2][2]);
  printf("\n");
}


int checkvacantspaces()
{
int freespaces= 9;

for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
      if(gameboard[i][j] != ' ')
      {
        freespaces--;
      }
    }
    return freespaces;
}
}



void playermove(int x, int y)
{
{
        int x;
        int y;

        printf("\nEnter row from(1-3)");
        scanf("%d",&x);
        x--;
        printf("\nEnter column from(1-3)");
        scanf("%d",&y);
        y--;

    if(gameboard[x][y] !=' ')
    {
        printf("\nInvalid move!\n");
    }
    else{

        gameboard[x][y]= PLAYER;
        //break;
    }
        
   }while(gameboard[x][y]!=' ')
   break;
}


void computermove()
{
   //creates a seed based on current time
   srand(time(0));
   int x;
   int y;

   if(checkvacantspaces()>0)
   {
    do
    {
        x= rand()%3;
        y= rand()%3;

    } while (gameboard[x][y] != ' ');
    gameboard[x][y]= COMPUTER;

   }
   else{
    displaywinner(' ');
   }
}



char cwinner()
{
//check rows here :-
   for(int i=0;i<3;i++)
   {
      if(gameboard[i][0]==gameboard[i][1] && gameboard[i][0]==gameboard[i][2] )
      {
          return gameboard[i][0];
      }
   }
    //check columns

    for(int i=0;i<3;i++)
   {
      if(gameboard[0][i]==gameboard[1][0] && gameboard[0][i]==gameboard[2][i] )
      {
          return gameboard[0][i];
      }
   }

     //check diagonal :-
   
   
      if(gameboard[0][0]==gameboard[1][1] && gameboard[0][0]==gameboard[2][2] )
      {
          return gameboard[0][0];
      }
     if(gameboard[0][2]==gameboard[1][1] && gameboard[0][0]==gameboard[2][0] )
      {
          return gameboard[0][2];
      }

      return ' ';
}



void displaywinner(char winner)
{
if(winner == PLAYER)
{
    printf("YAY! You win!");

}
else if(winner==COMPUTER)
{
    printf("ALAS! YOU LOSE!");

}
else{
    printf("DRAW!");
}
}