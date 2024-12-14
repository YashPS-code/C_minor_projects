#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int hangman(char *ptr){
    srand(time(NULL));
    char *wordList[4][2] = {
        { "geeksforgeeks", "Computer coding" },
        { "elephant", "A large mammal with a trunk" },
        { "pizza", "A popular Italian dish" },
        { "beach", "Sandy shore by the sea" },
    };
    int wordPick = rand()%4;
    char *wordGot = wordList[wordPick][0];
    const int wordLength = strlen(wordGot);
    int extrudeSizeMax = 0.5*wordLength;
    int extrudeSizeMin = 0.4*wordLength;
    int extrudeSize = rand()%(extrudeSizeMax-extrudeSizeMin+1)+extrudeSizeMin;
    int extrudingArr[10] = {};
    for(int i=0;i<extrudeSize;i++){
        int extrudePos= (rand()%wordLength);
        int flag= 1;
        for(int j=0;j<i;j++){
            if(extrudePos==extrudingArr[j]){
                flag = 0;
                break;
            }
        }
        if(flag == 0 ){
            i--;
            continue;
        }else{
            extrudingArr[i]=extrudePos;
        }
    }

    char newString[50];

    for(int i=0;i<wordLength;i++){
        newString[i]=wordGot[i];
    }
    
    for(int i=0;i<extrudeSize;i++){
        newString[extrudingArr[i]]='_';
    }
    return 0;
}

int main(){
    char word[50];
    char *ptr = word;
    hangman(ptr);
    printf("%s",word);

    return 0;
}