#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


#define LEFT 1
#define DOWN 3
#define UP 2
#define RIGHT 0
int main(void)
{


  char aa[10][10];
  int i, a;
  //created and initialized the array

  for (i=0; i<10; i++)
  {
    for (a=0; a<10; a++){
      aa[i][a]='.';

    }

  }


bool avaliable =true;
int x=0, y=0;
int attemps=0;
int alpha=65; // starts at A
aa[0][0]= alpha; //at [0][0] ==A
alpha=66;
int choosen=0;
int j=0;
srand(time(NULL));
//run the while loop untill all the letters in the alphabet or the attemps go
//to four (right, left, up and down)
while(avaliable)
{
//find a new random
int r = rand() % 4;

//switch statement check the avaliable options
  switch(r)
  {
    //not at edge
    case RIGHT:
    right:
    if((x+1 <10)&& aa[x+1][y]=='.')
    {
      //set value and increment marker
      aa[x+1][y]= alpha;
      x=x+1;
      attemps=0;
      alpha++;



    }
    //check other options
    else
    { attemps++;
      if(attemps<4 && alpha <91)
      {
        goto  left;
      }
      //if exceeds all options exit
      else if (attemps==4 || alpha >=90)
      {

        goto escape;
      }

    }
    break;
//not at edge
    case LEFT:
    left:
    if((x-1 >=0)&& aa[x-1][y]=='.')
    {
        //set value and increment marker
      aa[x-1][y]= alpha;
      x=x-1;
      alpha++;
      attemps=0;



    }
    //check other options
    else
    {
      attemps++;
        if(attemps<4 && alpha <91)
        {
          goto  up;
        }//if exceeds all options exit
        else if (attemps==4 || alpha ==90)
        {

          goto  escape;
        }
    }
    break;

//not at edge
    case UP:
    up:
    if((y-1 >=0)&& aa[x][y-1]=='.')
    {
        //set value and increment marker
      aa[x][y-1]= alpha;
      y=y-1;
      alpha++;
      attemps=0;


    }
    //check other options
    else
    {
      attemps++;
        if(attemps<4 && alpha <91)
        {
          goto  down;
        }//if exceeds all options exit
        else if (attemps==4 || alpha ==90)
        {

          goto  escape;
        }
    }

    break;
    //not at edge
    case DOWN:
    down:
    if((y+1 < 10)&& aa[x][y+1]=='.')
    {
        //set value and increment marker
      aa[x][y+1]= alpha;
      y=y+1;
      alpha++;
      attemps=0;


    }
    //check other options
    else
    {
      attemps++;
        if(attemps<4 && alpha <91)
        {
          goto  right;
        }//if exceeds all options exit
       else if (attemps==4 || alpha ==90)
        {

          goto  escape;
        }
    }

    break;
//this happens when the marker has no avaliable options
//right up left and down are all fill
//the program terminates

    escape:

    //print the board

      for (int i=0; i<10; i++)
      {
        for (int a=0; a<10; a++){

          printf("%c", aa[i][a]);
          printf("%c", ' ');
        }

         printf("\n");
      }
//terminate
      exit(0);
        break;


  }
  if(attemps==4 || alpha >90)
  {
    avaliable=false;
//print the board
//terminates at the begining or while loop

  for (int i=0; i<10; i++)
  {
    for (int a=0; a<10; a++){

      printf("%c", aa[i][a]);
      printf("%c", ' ');
    }

     printf("\n");
  }

  }

}

return 0;


}
