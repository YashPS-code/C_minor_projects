#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int game(char ch){
    char str[3]={'s','p','r'};
    srand(time(NULL));
    int compChoice = rand()%3;
    char result = str[compChoice];
    if(ch==result){
        printf("tie\n");
    }else if(ch=='s' && result=='p' || ch=='p' && result=='r' || ch=='r' && result=='s'){
        printf("Computer Wins\n");
    }else if(ch=='p' && result=='s' || ch=='r' && result=='p' || ch=='s' && result=='r'){
        printf("User Wins\n");
    }else{
        printf("Invalid Input\n");
    }
    return 0;
}

int main(){
    char userChoice;
    int (*fptr)(char);
    fptr = &game;
    printf("s:Stone\np:Paper\nr:Scissor\n");
    while(true){
        printf("Enter your Choice: ");
        scanf(" %c",&userChoice);
        /*if(userChoice != 's' || userChoice !='p'|| userChoice != 'r'){
            break;
        }*/
        fptr(userChoice);
    }
    return 0;
}