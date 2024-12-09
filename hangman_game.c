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
    char wordGot[50];
    strcpy(wordGot,wordList[wordPick][0]);
    int wordLength = sizeof(wordGot);
    int extrudeSizeMax = (1/2)*wordLength;
    int extrudeSizeMin = (2/5)*wordLength;
    int extrudeSize = rand()%(extrudeSizeMax-extrudeSizeMin+1)+extrudeSizeMin;
    int extrudingArr[] ={};
    for(int i=0;i<extrudeSize;i++){
        int extrudePos = rand()%wordLength;
        int flag= 1;
        for(int j=1;j<=i;j++){
            if(extrudePos==extrudingArr[j]){
                flag = 0;
            }
        }
        if(flag == 0){
            continue;
        }else{
            extrudingArr[i]=extrudePos;
        }
    }
    for(int i=0;i<extrudeSize;i++){
        wordGot[extrudingArr[i]]=' ';
    } 
    *ptr =wordGot;
    return 0;
}

int main(){
    char word[50];
    int ptr = &word;
    hangman(ptr);

    return 0;
}