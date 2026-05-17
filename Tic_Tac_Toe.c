#include <stdio.h>
#include <string.h>

#define SIZE 3

char board[SIZE][SIZE];

void initializeBoard(){
    memset(board, '-', sizeof(board));
}

void displayBoard()
{
    int i, j;

    printf("\n");

    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            printf(" %c ", board[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

int checkWin(char p)
{
    int i;

    /* rows */

    for(i=0;i<SIZE;i++)
    {
        if(board[i][0]==p &&
           board[i][1]==p &&
           board[i][2]==p)
        {
            return 1;
        }
    }

    /* columns */

    for(i=0;i<SIZE;i++)
    {
        if(board[0][i]==p &&
           board[1][i]==p &&
           board[2][i]==p)
        {
            return 1;
        }
    }

    /* diagonals */

    if(board[0][0]==p &&
       board[1][1]==p &&
       board[2][2]==p)
    {
        return 1;
    }

    if(board[0][2]==p &&
       board[1][1]==p &&
       board[2][0]==p)
    {
        return 1;
    }

    return 0;
}

int isDraw()
{
    int i, j;

    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            if(board[i][j]=='-')
                return 0;
        }
    }

    return 1;
}

int playGame()
{
    int row, col;
    int player = 1;

    char mark;

    initializeBoard();

    while(1)
    {
        displayBoard();

        mark = (player==1) ? 'X' : 'O';

        printf("Player %d (%c)\n", player, mark);

        printf("Enter row and column (0-2): ");

        scanf("%d%d", &row, &col);

        if(row<0 || row>=3 ||
           col<0 || col>=3)
        {
            printf("Invalid position!\n");
            continue;
        }

        if(board[row][col] != '-')
        {
            printf("Cell already occupied!\n");
            continue;
        }

        board[row][col] = mark;

        if(checkWin(mark))
        {
            displayBoard();

            printf("Player %d Wins This Game!\n", player);

            return player;
        }

        if(isDraw())
        {
            displayBoard();

            printf("Game Draw!\n");

            return 0;
        }

        player = 3 - player;
    }
}

int main()
{
    int score[2][100] = {0};

    int totalX = 0;
    int totalO = 0;

    int game = 0;

    int result;
    char choice;

    while(1)
    {
        printf("\n============================\n");
        printf("        GAME %d\n", game+1);
        printf("============================\n");

        result = playGame();

        if(result == 1)
        {
            totalX++;
            score[0][game] = 1;
        }

        else if(result == 2)
        {
            totalO++;
            score[1][game] = 1;
        }

        printf("\nSCOREBOARD\n");
        printf("Player X : %d\n", totalX);
        printf("Player O : %d\n", totalO);

        game++;

        if(totalX != totalO && game >= 3)
        {
            break;
        }

        printf("\nPlay another game? (y/n): ");
        scanf(" %c", &choice);

        if(choice!='y' && choice!='Y')
            break;
    }

    printf("\n============================\n");
    printf("       FINAL RESULT\n");
    printf("============================\n");

    printf("Player X Total Wins = %d\n", totalX);
    printf("Player O Total Wins = %d\n", totalO);

    if(totalX > totalO)
    {
        printf("\nULTIMATE WINNER : PLAYER X 😼\n");
    }

    else if(totalO > totalX)
    {
        printf("\nULTIMATE WINNER : PLAYER O 😼\n");
    }

    else
    {
        printf("\nPerfect Tie Between Both Players!\n");
    }

    printf("\nMATCH HISTORY\n");

    int i;

    for(i=0;i<game;i++)
    {
        printf("Game %d -> ", i+1);

        if(score[0][i]==1)
            printf("Player X Won\n");

        else if(score[1][i]==1)
            printf("Player O Won\n");

        else
            printf("Draw\n");
    }

    return 0;
}