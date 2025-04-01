#include <stdio.h>
#include <string.h>
#include <windows.h>
#define SIZE 4  
#define TOTAL_POSITIONS (SIZE * SIZE)
#define ROWS 4
#define COLS 4

typedef struct{
    int turn;
    int go;
    int over;
} playerCons;

typedef struct{
    int x;
    int y;
} coordinate;

void removeNewline(char *str);
void initializeP(coordinate P[], int A[]);
void declareNull(coordinate Uno[], coordinate Tres[]);
int checkArray(coordinate point, coordinate arr[], int size);
void findF(coordinate F[], coordinate Uno[], coordinate Tres[], coordinate P[]);
void processPlayerMove(coordinate F[], coordinate Uno[], coordinate Tres[], coordinate pos, playerCons *B);
void getPos(coordinate *pos, playerCons *B);
int checkWin(coordinate Uno[], coordinate Tres[], coordinate W[], coordinate F[]);
void evaluateGameOver(int winner, coordinate pos, playerCons *B, char Board[][COLS]);
void setBoard(char Board[ROWS][COLS]);
void printInput(coordinate pos, char Board[ROWS][COLS]);