/* mention the number of players along side the command line call to the program.
i.e. execute on the terminal (for Windows) "./a.exe {some_integer_value<5}" */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

struct ladder{      //structure to define ladders in the board
    int start;
    int end;
};

struct snake{       //structure to define positions of snake
    int start;
    int end;
};

int diceRoll(int **playerPosition,int refPlayer,char **playerSymbols);

void main(int argc, char **argv){
    
    if(argc!=2 || atoi(argv[1])>4){
        printf("Too few arguments at the command line or too many players");
        exit(1);
    }

    int playersNo = atoi(argv[1]);
    char *players[4];

    for(int i=0;i<playersNo;i++){       //player selection of their prefered symbol to play

        printf("Select player symbol for player %d ",i+1);
        scanf(" %c",&players[i]);

        for(int j=0;j<i;j++){
            if(players[j]==players[i]){
                printf("Symbol already taken...enter another symbol");
                i--;
                break;
            }
        }
    }
    
    struct ladder Ladders[] ={
        {2,23},
        {7,29},
        {22,41},
        {28,77},
        {30,32},
        {44,58},
        {54,69},
        {70,90},
        {80,83},
        {87,93}
    };

    struct snake Snakes[] ={
        {3,39},
        {5,35},
        {7,27},
        {12,73},
        {24,65},
        {26,99},
        {34,50},
        {46,59},
        {63,76},
        {67,89},
        {86,97}
    };

    int board[10][10]={
        {100,99,98,97,96,95,94,93,92,91},
        {81,82,83,84,85,86,87,88,89,90},
        {80,79,78,77,76,75,74,73,72,71},
        {61,62,63,64,65,66,67,68,69,70},
        {60,59,58,57,56,55,54,53,52,51},
        {41,42,43,44,45,46,47,48,49,50},
        {40,39,38,37,36,35,34,33,32,31},
        {21,22,23,24,25,26,27,28,29,30},
        {20,19,18,17,16,15,14,13,12,11},
        {1,2,3,4,5,6,7,8,9,10}
        };

    int *playerPos[playersNo];   //array pointer to refer to the position of each player
    char defaultChar = ' ';
    int playingPlayer = 0;      //reference of the player having dice turn

    while(true){
        for(int i=0;i <10; i++){      //looping through numbers of Snake & Ladder board
            for(int j=0; j<10; j++){
                printf("%3d%s%s%s%s",board[i][j],defaultChar,defaultChar,defaultChar,defaultChar);
            }
        printf("\n");
        }
        int positionAdder = diceRoll(playerPos,playingPlayer,players);
        int refPlayer = (refPlayer+1)%4;
    }
}

int diceRoll(int **playerPosition,int refPlayer,char **playerSymbols){
    char *ran;
    printf("player symbol %c has the dice... Press Enter to roll",playerSymbols[refPlayer]);
    gets(ran);

    srand(time(NULL));
    int diceNum = (rand()%5)+1;   //dice

    printf("Dice: %d",diceNum);

    return diceNum;
}