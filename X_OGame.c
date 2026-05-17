#include <stdio.h>
#include <string.h>

#define SIZE 3

char board[SIZE][SIZE][SIZE];

// void initializeBoard()
// {
//     int l, r, c;

//     for(l=0; l<SIZE; l++)
//     {
//         for(r=0; r<SIZE; r++)
//         {
//             for(c=0; c<SIZE; c++)
//             {
//                 board[l][r][c] = '-';
//             }
//         }
//     }
// }
void initializeBoard(){
    memset(board, '-', sizeof(board));
}

void displayBoard(){
    int l, r, c;

    for(l=0; l<SIZE; l++){
        printf("\nLayer %d\n", l);

        for(r=0; r<SIZE; r++){
            for(c=0; c<SIZE; c++){
                printf("%c ", board[l][r][c]);
            }
            printf("\n");
        }
    }
}

int checkWin(char p){
    int l, r, c;

    /* row check */
    for(l=0; l<SIZE; l++){
        for(r=0; r<SIZE; r++){
            if(board[l][r][0]==p &&
               board[l][r][1]==p &&
               board[l][r][2]==p){
                return 1;
            }
        }
    }

    /* column check */
    for(l=0; l<SIZE; l++){
        for(c=0; c<SIZE; c++){
            if(board[l][0][c]==p &&
               board[l][1][c]==p &&
               board[l][2][c]==p){
                return 1;
            }
        }
    }

    /* diagonal check */
    for(l=0; l<SIZE; l++){
        if(board[l][0][0]==p &&
           board[l][1][1]==p &&
           board[l][2][2]==p){
            return 1;
        }

        if(board[l][0][2]==p &&
           board[l][1][1]==p &&
           board[l][2][0]==p){
            return 1;
        }
    }
    return 0;
}

int isDraw(){
    int l, r, c;

    for(l=0; l<SIZE; l++){
        for(r=0; r<SIZE; r++){
            for(c=0; c<SIZE; c++){
                if(board[l][r][c]=='-')
                    return 0;
            }
        }
    }
    return 1;
}

int main(){
    int layer, row, col;
    int player = 1;

    char mark;

    initializeBoard();

    while(1){
        displayBoard();
        mark = (player==1) ? 'X' : 'O';

        printf("\nPlayer %d (%c)\n", player, mark);

        printf("Enter layer row column: ");

        scanf("%d%d%d", &layer, &row, &col);

        /* validation */

        if(layer<0 || layer>=3 ||
           row<0 || row>=3 ||
           col<0 || col>=3){
            printf("Invalid position!\n");
            continue;
        }

        if(board[layer][row][col] != '-'){
            printf("Cell already occupied!\n");
            continue;
        }

        board[layer][row][col] = mark;

        /* win check */

        if(checkWin(mark)){
            displayBoard();

            printf("\nPlayer %d Wins!\n",
                   player);

            break;
        }

        /* draw */

        if(isDraw()){
            displayBoard();

            printf("\nGame Draw!\n");
            break;
        }

        /* change player */

        player = 3 - player; /* 1->2, 2->1 */
    }

    return 0;
}