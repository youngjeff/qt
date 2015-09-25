#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define N 15

int chessboard[N+1][N+1]={0};
int whoseTurn = 0;
void initGame(void);
void printChessboard(void);
void playchess(void);
int judge(int x,int y);
using namespace std;

int main()
{
    initGame();

    while(1){
        whoseTurn++;
        playchess();
    }
    return 0;
}

void initGame(void)
{
    char c;

    cout<<"please input \'y\' to enter the game;";
    c = getchar();
    if('y' !=c &&'Y' !=c)
        exit(0);
    system("clear");
    printChessboard();

}
void printChessboard(void)
{
    int i,j;
    for(i = 0;i <= N; i++)
    {
        for(j = 0;j <= N;j++)
        {
            if(0 == i)
                printf("%3d",j);
            else if (j == 0)
                printf("%3d", i);
            else if (1 == chessboard[i][j])
                printf("  0");
            else if (2 == chessboard[i][j])
                printf("  x");
            else
                printf("  *");
        }
        printf("\n");
    }
}

void playchess(void)
{
    int i,j;

    if(1 == whoseTurn %2)
    {
        cout<<"turn to player 1, please input the positon :";
        cin>>i>>j;

        while(chessboard[i][j] != 0)
        {
            cout<<"This position has been occupied , please  input the position,please input the position again";
            cin>>i>>j;

        }
        chessboard[i][j] = 1;
    }
    else
    {
        cout<<"Turn to player 2,please input the position :";
        cin>>i>>j;
        while(chessboard[i][j] != 0)
        {
            cout<<"This position has benn occupied, please input the position again";
            cin>>i>>j;
        }
        chessboard[i][j] = 2;
    }
    system("clear");
    printChessboard();

    if(judge(i,j))
    {
        if(1 == whoseTurn % 2)
        {
            cout<<"winner is player 1 ! \n";
            exit(0);
        }
        else
        {
            cout<<"winner is player 2 ! \n";
            exit(0);
        }
    }

}

int judge(int x,int y)
{
    int i,j;
    int t = 2 - whoseTurn % 2;

    for(i = x - 4, j = y; i <= x; i++)
    {
        if(i >=1 && i <=N -4 && t == chessboard[i][j] && t ==chessboard[i+1][j]
                && t==chessboard[i+2][j] &&t == chessboard[i+3][j]
                &&t == chessboard[i+4][j])
            return 1;
    }
    for (i = x, j = y - 4; j <= y; j++)
    {
        if (j >= 1 && j <= N - 4 && t == chessboard[i][j] && t == chessboard[i][j + 1] && t == chessboard[i][j + 1] && t == chessboard[i][j + 3] && t == chessboard[i][j + 4])
            return 1;
    }
    for (i = x - 4, j = y - 4; i <= x, j <= y; i++, j++)
    {
        if (i >= 1 && i <= N - 4 && j >= 1 && j <= N - 4 && t == chessboard[i][j] && t == chessboard[i + 1][j + 1] && t == chessboard[i + 2][j + 2] && t == chessboard[i + 3][j + 3] && t == chessboard[i + 4][j + 4])
            return 1;
    }
    for (i = x + 4, j = y - 4; i >= 1, j <= y; i--, j++)
    {
        if (i >= 1 && i <= N - 4 && j >= 1 && j <= N - 4 && t == chessboard[i][j] && t == chessboard[i - 1][j + 1] && t == chessboard[i - 2][j + 2] && t == chessboard[i - 3][j + 3] && t == chessboard[i - 4][j + 4])
            return 1;
    }

    return 0;

}






























