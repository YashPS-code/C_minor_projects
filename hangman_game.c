#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MaxTry = 6;

struct store{
        int num;
        char chr;
    };

int hangman(char *word,char *hint, struct store *answerCharacter){
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
    int extrudeSizeMax = 0.9*wordLength;
    int extrudeSizeMin = 0.5*wordLength;
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

    for(int i=0;i<=wordLength;i++){
        newString[i]=wordGot[i];
    }

    for(int i=0;i<extrudeSize;i++){
        answerCharacter->num = extrudingArr[i];
        answerCharacter->chr = newString[extrudingArr[i]];
        newString[extrudingArr[i]]='_';
    }

    strcpy(word,newString);
    strcpy(hint,wordList[wordPick][1]);
    return 0;
}

int inputCheck(char *work, int *pass)

int main(){
    char word[50];
    char hint[50],userInp;
    int *passStage, userTry = 1;
    struct store* answerCharacter;
    hangman(word,hint,answerCharacter);
    while(userTry<MaxTry){
        printf("%s\t\t\t%s",word,hint);
        scanf(" %c",&userInp);
        inputCheck(word,passStage,userInp,/*extrude array*/);
        if(passStage==0){
            userTry++;
            if(userTry==MaxTry){
                printf("All tries Exhausted.");
                break;
            }
        }

    }
    return 0;
}

int inputCheck(char *word, int *pass, char userInp, /*Another ...*/){
    
}