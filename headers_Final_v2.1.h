#include <stdio.h>
#include <string.h>
#include <windows.h>
#define SIZE 4  
#define TOTAL_POSITIONS (SIZE * SIZE)

typedef struct{
    int turn;
    int go;
    int over;
} playerCons;

typedef struct{
    int x;
    int y;
} coordinate;

int checkArray(coordinate point, coordinate arr[], int size);
int checkWin(coordinate Uno[], coordinate Tres[], coordinate W[], coordinate F[]);
void evaluateGameOver(int winner, coordinate Uno[], coordinate Tres[], playerCons *B, char Board[][SIZE]);
void getPos(coordinate *pos, playerCons *B);
void initializeF(coordinate F[], coordinate Uno[], coordinate Tres[], coordinate P[]);
void initializeNull(coordinate Uno[], coordinate Tres[]);
void initializeP(coordinate P[], int A[]);
void printBoard(char Board[SIZE][SIZE], coordinate Uno[], coordinate Tres[]);
void processPlayerMove(coordinate F[], coordinate Uno[], coordinate Tres[], coordinate pos, playerCons *B);
void setBoard(char Board[SIZE][SIZE]);