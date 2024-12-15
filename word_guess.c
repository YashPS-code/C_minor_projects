#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MaxTry 6

int wordGenerator(char *word,char *hint,char *answerCharacter,int *answerPositions){
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
        }else{
            extrudingArr[i]=extrudePos;
        }
    }

    char newString[50];

    for(int i=0;i<=wordLength;i++){
        newString[i]=wordGot[i];
    }
    int numExtrudes=0;

    for(int i=0;i<extrudeSize;i++){
        answerCharacter[i] = newString[extrudingArr[i]];
        answerPositions[i] = extrudingArr[i];
        numExtrudes++;
        newString[extrudingArr[i]]='_';
    }

    strcpy(hint,wordList[wordPick][1]);
    strcpy(word,newString);

    return numExtrudes;
}

int main(){
    char word[50], hint[50], answerCharacter[20], userInp;
    int answerPos[50];
    int userTry = 1, replacedCount=0;;
    int numberOfExtrudes = wordGenerator(word, hint, answerCharacter, answerPos);
    while(userTry<MaxTry){
        printf("%s\t\t\t%s \nEnter your guess of character: ",word,hint);
        scanf(" %c",&userInp);
        int flag = 0;
        for(int i=0; i<sizeof(answerCharacter);i++){
            if(answerCharacter[i]==userInp){
                word[answerPos[i]]=answerCharacter[i];
                replacedCount++;
                flag=1;
            }
        }
        if(flag==0){
            userTry++;
            printf("%d",userTry);
        }
        if(userTry==MaxTry){
            printf("All tries Exhausted.");
            break;
        }
        if(replacedCount==numberOfExtrudes){
            printf("Word Guessed! Well Played");
            break;
        }
    }
    return 0;
}