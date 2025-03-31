#include <stdio.h>
#define SIZE 4  
#define TOTAL_POSITIONS (SIZE * SIZE)

/*
Last Modified: Chino | 11:00PM | 3/31/25
Version:
    +1 Working Prototype
    +0.1 Finished a function
    +0.01 Small Changes/Debugging
---------------------------------------
Changes:
- Added playerCons struct
- Added logic to ProcessPlayerMove
- Added logic to GetPos
- Added static array for C
- Made helper function [CheckArray]
- Added logic in FindF and FindW
--------------------------------------
Code Notes [Bugs or other stuff]:


*/
typedef struct{
    int turn;
    int go;
    int over;
} playerCons;

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
coordinate C[12] = {
    {1,1}, {1,2}, {1,3}, {1,4},
    {2,2}, {2,3}, {3,3}, {3,2},
    {4,4}, {4,3}, {4,2}, {4,1}
};

void initializeP(coordinate P[], int A[]){
	int i, j, index = 0;
	// P = A x A
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            P[index].x = A[i];
            P[index].y = A[j];
            index++;
        }
    }
}

void DeclareNull(coordinate Uno[], coordinate Tres[]){
    for(int i = 0; i < TOTAL_POSITIONS; i++){
        Tres[i].x = 0;
        Tres[i].y = 0;
        Uno[i].x = 0;
        Uno[i].y = 0;
    }
}

int CheckArray(coordinate point, coordinate arr[], int size){
    int flag = 0;
    for (int i = 0; i < size; i++) {
        if (point.x == arr[i].x && point.y == arr[i].y) {
            flag = 1;
        }
    }
    return flag;
} //will return 1 if there is a match

//function to get F
void FindF(coordinate F[], coordinate Uno[], coordinate Tres[], coordinate P[]){
    // find all element in P that are not in uno or tres then give it to F
    int fIndex = 0;
    for(int i = 0; i < TOTAL_POSITIONS; i++){
        if(!CheckArray(P[i], Uno, TOTAL_POSITIONS) && !CheckArray(P[i], Tres, TOTAL_POSITIONS)){
            //condition that checks if the coordinate in Uno and tres are not matched with any of P
            //if there is no match, P will be assigned to F;
            F[fIndex] = P[i];
            fIndex++;
        }
    }
}


// function to get W
void FindW(coordinate C[], coordinate T[], coordinate W[]){
    int WIndex = 0;
    for(int i = 0; i < 12; i++){
        if(!CheckArray(C[i], T, 8)){ //has a fixed size of 8
            W[WIndex] = C[i];
            WIndex++;
        }
    }
}

//function to process action with given inputs; remove pos (if pos is in Uno or Tres) otherwise, add the element 
void ProcessPlayerMove(coordinate F[], coordinate Uno[], coordinate Tres[], playerCons B, int x, int y){
	int i, j;
	coordinate temp;
	temp.x = 0;
	temp.y = 0;
	
	for(i = 0; i < TOTAL_POSITIONS; i++){ //Tries to find the coordinates in F[] and adds it to temp
		if(F[i].x == x && F[i].y == y){	
			temp.x = x;
			temp.y = y;
		}
	}
	
	if(B.turn == 1 && B.go == 1 && temp.x != 0 && temp.y != 0){ //Uno's turn and inputted coordinates is in F[]
		for(j = 0; j < TOTAL_POSITIONS; j++){
			if(Uno[j].x == 0 && Uno[j].y == 0){ //Finds an empty array and places coordinates there
				Uno[j].x = temp.x;
				Uno[j].y = temp.y;
				j = TOTAL_POSITIONS;
			}
		}
		B.turn = 0;
		B.go = 0;
	}
	if(B.turn == 0 && temp.x == 0 && temp.y == 0){ // Anyone's turn and inputted coordinates is not in F[]
		for(j = 0; j < TOTAL_POSITIONS; j++){ // Finds the array with the inputted coordinates
			if(Uno[j].x == x && Uno[j].y == y){ // Inputted coordinates are in Uno's array
				Uno[j].x = 0;
				Uno[j].y = 0;
				j = TOTAL_POSITIONS;
			}
			else if(Tres[j].x == x && Tres[j].y == y){ // Inputted coordinates are in Tres' array
				Tres[j].x = 0;
				Tres[j].y = 0;
				j = TOTAL_POSITIONS;
			}
		}
		B.turn = 1;
	}
	if(B.turn == 1 && B.go == 0 && temp.x != 0 && temp.y != 0){
		for(j = 0; j < TOTAL_POSITIONS; j++){
			if(Uno[j].x == 0 && Uno[j].y == 0){
				Uno[j].x = temp.x;
				Uno[j].y = temp.y;
				j = TOTAL_POSITIONS;
			}
		}
		B.go = 1;
	}
}

// function for user input
void GetPos(int *x, int *y, playerCons B){
	if(B.turn == 1 && B.go == 1){ // Uno's turn
		printf("Your turn, Uno! Input coordinates: ");
		scanf("%d %d", x, y);
	}
	else{ // Tres' turn
		printf("Your turn, Tres! Input coordinates: ");
		scanf("%d %d", x, y);
	}
}

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
