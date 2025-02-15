#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
char player = 'X';
char computer = 'O';

void resetBoard();
void printBoard();
int checkEmptySpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char winner);

int main(){
    char answer;
    do{
        char winner = ' ';
        resetBoard();
        printBoard();
        while(winner == ' ' && checkEmptySpaces() != 0){
            playerMove();
            printBoard();
            winner = checkWinner();
            if(winner != ' ' || checkEmptySpaces() == 0){
                printWinner(winner);
                break;
            }
            computerMove();
            printBoard();
            winner = checkWinner();
            if(winner != ' ' || checkEmptySpaces() == 0){
                printWinner(winner);
                break;
            }
        }
        
        printf("Do you want to play again?y/n\n");
        scanf("%c");
        scanf("%c", &answer);
        answer = tolower(answer);
    }while(answer == 'y');
    printf("Thank you for playing!Adios <33\n");
}

void resetBoard(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}
void printBoard(){
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}
int checkEmptySpaces(){
    int emptySpaces = 9;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != ' '){
                emptySpaces --;
            }
        }
    }
    return emptySpaces;
}
void playerMove(){
    int x,y;
    do{
        printf("Enter row number(1-3): ");
        scanf("%d", &x);
        x--;
        printf("Enter column number(1-3): ");
        scanf("%d", &y);
        y--;
        if(board[x][y] != ' ') printf("That space is already occupied\n");
        if (x < 0 || x >= 3 || y < 0 || y >= 3) {
            printf("Invalid input! Enter numbers between 1 and 3.\n");
            continue;
        }
        

    }while(board[x][y] != ' ');
    board[x][y] = player;
    
}
void computerMove(){
    int x,y;
    srand(time(0));
    do{
        x = rand() % 3;
        y = rand() % 3;
    }while(board[x][y] != ' ');
    board[x][y] = computer;
}
char checkWinner(){
    char winner = ' ';
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]) winner = board[i][0];
    }
    for(int i = 0; i < 3; i++){
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]) winner = board[0][i];
    }
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]) winner = board[0][0];
    if(board[2][0] == board[1][1] && board[2][0] == board[0][2]) winner = board[2][0];
    return winner;
}
void printWinner(char winner){
    if(winner == player) printf("You won!\n");
    else if(winner == computer) printf("You lost!\n");
    else printf("Draw!\n");
}
