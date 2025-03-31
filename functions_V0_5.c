#include <stdio.h>
#define SIZE 4  
#define TOTAL_POSITIONS (SIZE * SIZE)

/*
Last Modified: Kim | 7:59PM | 3/31/25
Version:
    +1 Working Prototype
    +0.1 Finished a function
    +0.01 Small Changes/Debugging
---------------------------------------
Changes:
- Added outline of functions to do
--------------------------------------
Code Notes [Bugs or other stuff]:


*/

typedef struct{
    int x;
    int y;
} coordinate;

coordinate P[TOTAL_POSITIONS];
coordinate T[TOTAL_POSITIONS];
coordinate Uno[TOTAL_POSITIONS];
coordinate Tres[TOTAL_POSITIONS];
coordinate Dos[TOTAL_POSITIONS];
coordinate F[TOTAL_POSITIONS]; //All coordinates/ordered pairs not Uno and Tres
coordinate W[TOTAL_POSITIONS]; //All coordinates from set c that are not a part of T

void DeclareNull(coordinate Uno[], coordinate Tres[]){
    for(int i = 0; i < TOTAL_POSITIONS; i++){
        Tres[i].x = 0;
        Tres[i].y = 0;
        Uno[i].x = 0;
        Uno[i].y = 0;
    }
}


//function to get F
void FindF(coordinate F[], coordinate Uno[], coordinate Tres[]){

}

// function to get W
void FindW(coordinate C[], coordinate T[], coordinate W[]){

}

// function for user input
void ProcessPlayerMove(coordinate P[], coordinate Uno[], coordinate Tres[], int Turn, int Go){

}

//function to check availability of pos; remove pos (if both are the same) and to add the element otherwise
void GetPos();

// function to check if there are any winning conditions
int CheckWin(coordinate Uno[], coordinate Tres[]){}; //add to parameter the array that contains the pre-defined winning conditions
// would either return 1 or 0 to signify if there is a winner

// function to check if the board is full and there is no winning conditions
int CheckBoard(){};

// If there is no winner, the following function should toggle the turn value
void ModifyTurn(){};
// should return to the ask user input function from here

// Function to evaluate or flag when a game is over
int EvaluateGameOver(){};

// Function to give a visual, print like a tictactoe game 
void PrintInput(){};
