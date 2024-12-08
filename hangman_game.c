#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int hangman(){
    srand(time(NULL));
    char *wordList[4][2] = {
        { "geeksforgeeks", "Computer coding" },
        { "elephant", "A large mammal with a trunk" },
        { "pizza", "A popular Italian dish" },
        { "beach", "Sandy shore by the sea" },
    };
    int wordPick = rand()%4;
    char wordGot[] = (char*)wordList[wordPick][0];
    int wordLength = sizeof(wordGot);
    int extrudeSizeMax = (1/2)*wordLength;
    int extrudeSizeMin = (2/5)*wordLength;
    int extrudeSize = rand()%(extrudeSizeMax-extrudeSizeMin+1)+extrudeSizeMin;
    for(int i=0;i<extrudeSize;i++){
        int extrudeingArr[] ={};
        int extrudePos = rand()%wordLength;
        for(int j=1;j<=i;j++){
            if(extrudePos){
                return 0;
            }

        }
    }

    return 0;
}

int main(){
    hangman();
    hangman();

    return 0;
}