
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char   uint8_t;

uint8_t configArray[3]={0,0,0};
uint8_t position;
uint8_t Error_Input_Flag=0;
void drawBoard(uint8_t *board)
{
    int i=0;
    for (i=0; i<9; i++)
    {
        if (i==3||i==6)
        {
            printf("\n");
        }
        if (board[i]>9)
        {
            printf("%c   ",board[i]);
        }
        else
        {
            printf("%d   ",board[i]);
        }
    }

    printf("\n*********************\n");
}
void updateBoard (uint8_t *board, uint8_t position, uint8_t value)
{
    if (board[position-1]!=position||position<1||position>9)
    {
        Error_Input_Flag=1;
    }
    else
    {
        board[position-1]=value;
    }
}
uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t * symbol)
{
    if (playerNumber==1)
    {
        if (symbol[playerNumber-1]=='x'||symbol[playerNumber-1]=='o'||symbol[playerNumber-1]=='X'||symbol[playerNumber-1]=='O')
        {
            return 0;
        }
        else
        {
            printf("Wrong symbol...please enter only x or o\n");
            printf("please enter again\n");
            printf("*******************\n");
            return 1;
        }
    }
    else
    {
        if (symbol[playerNumber-1]!=symbol[playerNumber-2])
        {
            if (symbol[playerNumber-1]=='x'||symbol[playerNumber-1]=='o'||symbol[playerNumber-1]=='X'||symbol[playerNumber-1]=='O')
            {
                return 0;
            }
            else
            {
                printf("Wrong symbol...please enter only x or o\n");
                printf("please enter again\n");
                printf("*******************\n");
                return 1;
            }

        }
        else
        {
            printf("Wrong symbol...player 1 was selected this symbol\n");
            printf("please enter again\n");
            printf("*******************\n");
            return 1;
        }
    }
}
void setPlayerConfig(uint8_t *configArray)
{
    uint8_t check=1;
    while (check==1)
    {
        printf("Enter your symbol (x or o)\n");
        printf("Player 1\n");
        scanf(" %[^\n]s",&configArray[0]);
        if (configArray[1]==0)
        {
            check=getPlayerSymbol(1,configArray);
        }
        else
        {
            printf("Wrong symbol...please enter only x or o\n");
            printf("please enter again\n");
                printf("*******************\n");
        }
    }

    check=1;
    while (check==1)
    {
        printf("Player 2\n");
        scanf(" %[^\n]s",&configArray[1]);


if (configArray[2]==0)
        {
            check=getPlayerSymbol(1,configArray);
        }
        else
        {
            printf("Wrong symbol...please enter only x or o\n");
                printf("please enter again\n");
                printf("*******************\n");
        }
    }
}

void loadAndUpdate(uint8_t playerNumber)
{
    printf("Enter the wanted position\n");

    scanf(" %d",&position);

}

void getGameState(uint8_t *board, uint8_t *gameState)
{
    if (board[0]==board[1]&&board[0]==board[2])
    {
        *gameState=0;
    }
    else if (board[0]==board[3]&&board[0]==board[6])
    {
        *gameState=0;
    }
    else if (board[0]==board[4]&&board[0]==board[8])
    {
        *gameState=0;
    }
    else if (board[1]==board[4]&&board[1]==board[7])
    {
        *gameState=0;
    }
    else if (board[2]==board[4]&&board[2]==board[6])
    {
        *gameState=0;
    }
    else if (board[2]==board[5]&&board[2]==board[8])
    {
        *gameState=0;
    }
    else if (board[3]==board[4]&&board[3]==board[5])
    {
        *gameState=0;
    }
    else if (board[6]==board[7]&&board[6]==board[8])
    {
        *gameState=0;
    }
}
int main()
{
    uint8_t game_State=2;
    uint8_t i;
    uint8_t board[9]= {1,2,3,4,5,6,7,8,9};
    setPlayerConfig(configArray);
    printf("**************\n");
    printf("Player 1 Symbol is \n ");
    printf("%c\n",configArray[0]);
    printf("Player 2 Symbol is\n ");
    printf("%c\n",configArray[1]);
    printf("**************\n");
    printf("Start the game\n");
    printf("Player 1 is : %c               player 2 is : %c \n",configArray[0],configArray[1]);
    printf("**************\n");
    drawBoard(board);
    for ( i=1; i<=9; i++)
    {
        if (i%2!=0)
        {
            printf("Player1's turn\n");
            loadAndUpdate(1);
            updateBoard(board,position,configArray[0]);
            if (Error_Input_Flag==1)
            {
                printf("Wrong Input....Please Enter Again\n");
                i--;
                Error_Input_Flag=0;
                printf("**************\n");
            }
            else
            {
                getGameState(board,&game_State);
                drawBoard(board);
            }

        }

        else
        {
            printf("Player2's turn\n");
            loadAndUpdate(2);
            updateBoard(board,position,configArray[1]);
            if (Error_Input_Flag==1)
            {
                printf("Wrong Input....Please Enter Again\n");
                i--;
                Error_Input_Flag=0;
                printf("**************\n");
            }
            else
            {
                getGameState(board,&game_State);
                drawBoard(board);
            }
        }

        if (game_State!=2)
        {
            break;
        }

    }

    if (game_State==0)
    {
        if (i%2!=0)
        {
            printf ("The winner is player1 ");
        }
        else
        {
            printf ("The winner is player2  ");
        }
    }
    else
    {
        printf ("The game is draw ");
    }

    return 0;

}

