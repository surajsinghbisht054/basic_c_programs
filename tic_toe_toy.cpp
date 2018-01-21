#include <stdio.h>
#include <stdlib.h>


char b[10] = {'.','.','.','.','.','.','.','.','.','.'};


/*
__author__ = suraj singh bisht
__email__  = surajsinghbisht054@gmail.com
__Github__ = https://github.com/surajsinghbisht054


####################################################################
#          Terminal : TIC TOE TOY Game                            #
####################################################################
*/


// Get Current Status Of board
void printboard(){
    printf("\n\
     |     |      \n\
  %c  |  %c  | %c    \n\
 ____|_____|_____  \n\
     |     |       \n\
  %c  |  %c  | %c    \n\
 ____|_____|_____  \n\
     |     |       \n\
  %c  |  %c  | %c    \n\
     |     |       \n\
\
        ",b[1],b[2],b[3],b[4],b[5],b[6],b[7],b[8],b[9] );

}



// Check Second Player Win
bool check_second_win(){
    if (b[1] == b[2] && b[2] == b[3] && b[3]=='0')
        return true;
    else if (b[4] == b[5] && b[5] == b[6] && b[6]=='0')
        return true;
    else if (b[7] == b[8] && b[8] == b[9] && b[9]=='0')
        return true;
    else if (b[1] == b[4] && b[4] == b[7] && b[7]=='0')
        return true;
    else if (b[2] == b[5] && b[5] == b[8] && b[8]=='0')
        return true;
    else if (b[3] == b[6] && b[6] == b[9] && b[9]=='0')
        return true;
    else if (b[1] == b[5] && b[5] == b[9] && b[9]=='0')
        return true;
    else if (b[3] == b[5] && b[5] == b[7] && b[7]=='0')
        return true;
    else
        return false;

    return true;
}


// Check First Player Win Status
bool check_first_win(){
    if (b[1] == b[2] && b[2] == b[3] && b[3]=='X')
        return true;
    else if (b[4] == b[5] && b[5] == b[6] && b[6]=='X')
        return true;
    else if (b[7] == b[8] && b[8] == b[9] && b[9]=='X')
        return true;
    else if (b[1] == b[4] && b[4] == b[7] && b[7]=='X')
        return true;
    else if (b[2] == b[5] && b[5] == b[8] && b[8]=='X')
        return true;
    else if (b[3] == b[6] && b[6] == b[9] && b[9]=='X')
        return true;
    else if (b[1] == b[5] && b[5] == b[9] && b[9]=='X')
        return true;
    else if (b[3] == b[5] && b[5] == b[7] && b[7]=='X')
        return true;
    else
        return false;

    return true;
}

// Check Tie
bool check_tie(){
    if ((b[0]!='.')&&(b[1]!='.')&&(b[2]!='.')&&(b[3]!='.')&&(b[4]!='.')&&(b[5]!='.')&&(b[6]!='.')&&(b[7]!='.')&&(b[8]!='.')&&(b[9]!='.')){
        return true;
    }
    else{
        return false;
    }
}

// First Player Turn
void FirstPlayerTurn(){
    int d = 1;
    printf("[+] Player 1 [X] Please Enter Your Choose : ");
    scanf("%d", &d);
    b[d]='X';


}

// Second Player Turn
void SecondPlayerTurn(){
    int d = 2;
    printf("[+] Player 2 [0] Please Enter Your Choose : ");
    scanf("%d", &d);
    b[d]='0';


}

// main trigger
main(){

    while(1){
        printf("[+] Current Status Of board\n");
        printboard();
        FirstPlayerTurn();
        if (check_first_win()){
            printf("[-]    First Player win   [-] \n");
            printboard();
            exit(0);
        }
        if (check_tie()){
            printf("Game Tie\n");
            //break;
            exit(0);
        }
        printf("[+] Current Status Of board\n");
        printboard();
        SecondPlayerTurn();
        if (check_second_win()){
            printf("[-]    Second Player Win  [-]\n");
            printboard();
            exit(0);
        }
        if (check_tie()){
            printf("Game Tie\n");
            //break;
            exit(0);
        }
        //win++;
    };

    }

