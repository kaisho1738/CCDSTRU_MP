#include <stdio.h>
#include <string.h>
#include <windows.h>
#define SIZE 4  
#define TOTAL_POSITIONS (SIZE * SIZE)
#define ROWS 4
#define COLS 4

/*
Last Modified: Chino | 2:01AM | 3/31/25
Version: 1.2
    +1 Working Prototype
    +0.1 Finished a function
    +0.01 Small Changes/Debugging
---------------------------------------
Changes:
- Added logic to CheckWin
- Changed B to *B
- Adjusted struct calling format due to pointer struct
--------------------------------------
Code Notes [Bugs or other stuff]:
- to add differentiating symbols

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

void removeNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';  // Replace newline with null terminator
    }
}

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
    int wIndex = 0;
    for(int i = 0; i < 12; i++){
        if(!CheckArray(C[i], T, 8)){ //has a fixed size of 8
            W[wIndex] = C[i];
            wIndex++;
        }
    }
}

//function to process action with given inputs; remove pos (if pos is in Uno or Tres) otherwise, add the element 
void ProcessPlayerMove(coordinate F[], coordinate Uno[], coordinate Tres[], coordinate pos, playerCons *B){
	int i, j, found;
	
	found = CheckArray(pos, F, TOTAL_POSITIONS); //Tries to find the coordinates in F[] and change the value of found
	
	if(B->turn == 1 && B->go == 1 && found == 1){ //Uno's turn and inputted coordinates is in F[]
		for(j = 0; j < TOTAL_POSITIONS; j++){
			if(Uno[j].x == 0 && Uno[j].y == 0){ //Finds an empty array and places coordinates there
				Uno[j].x = pos.x;
				Uno[j].y = pos.y;
				j = TOTAL_POSITIONS;
			}
		}
		B->turn = 0;
		B->go = 0;
	}
	else if(B->turn == 0 && found == 0){ // Anyone's turn and inputted coordinates is not in F[]
		for(j = 0; j < TOTAL_POSITIONS; j++){ // Finds the array with the inputted coordinates
			if(Uno[j].x == pos.x && Uno[j].y == pos.y){ // Inputted coordinates are in Uno's array
				Uno[j].x = 0;
				Uno[j].y = 0;
				j = TOTAL_POSITIONS;
			}
			else if(Tres[j].x == pos.x && Tres[j].y == pos.y){ // Inputted coordinates are in Tres' array
				Tres[j].x = 0;
				Tres[j].y = 0;
				j = TOTAL_POSITIONS;
			}
		}
		B->turn = 1;
	}
	else if(B->turn == 1 && B->go == 0 && found == 1){
		for(j = 0; j < TOTAL_POSITIONS; j++){
			if(Uno[j].x == 0 && Uno[j].y == 0){
				Uno[j].x = pos.x;
				Uno[j].y = pos.y;
				j = TOTAL_POSITIONS;
			}
		}
		B->go = 1;
	}
}

// function for user input
void GetPos(coordinate *pos, playerCons *B){
	if(B->turn == 1 && B->go == 1){ // Uno's turn
		printf("Your turn, Uno! Input coordinates: ");
		scanf("%d %d", pos->x, pos->y);
	}
	else{ // Tres' turn
		printf("Your turn, Tres! Input coordinates: ");
		scanf("%d %d", pos->x, pos->y);
	}
}

// function to check if there are any winning conditions
int CheckWin(coordinate Uno[], coordinate Tres[], coordinate W[], coordinate F[]){
	int i, j, dosWin = 1;
	coordinate temp;
	
	for(i = 0; i < TOTAL_POSITIONS; i++){
		temp.x = 0;
		temp.y = 0;
		if(CheckArray(temp, F, TOTAL_POSITIONS) != 1){
			dosWin = 0;
			i = TOTAL_POSITIONS;
		}
	}
	if(dosWin == 0){
		for(i = 0; i < 3; i++){
			if(i == 0){
				temp.x = 1;
				temp.y = 1;
				if(CheckArray(temp, Uno, TOTAL_POSITIONS) == 1){
					temp.y = 2;
					if(CheckArray(temp, Uno, TOTAL_POSITIONS) == 1){
						temp.y = 3;
						if(CheckArray(temp, Uno, TOTAL_POSITIONS) == 1){
							temp.y = 4;
							if(CheckArray(temp, Uno, TOTAL_POSITIONS) == 1)
								return 1;
						}
					}
				}
				else if(CheckArray(temp, Tres, TOTAL_POSITIONS) == 1){
					temp.y = 2;
					if(CheckArray(temp, Uno, TOTAL_POSITIONS) == 1){
						temp.y = 3;
						if(CheckArray(temp, Uno, TOTAL_POSITIONS) == 1){
							temp.y = 4;
							if(CheckArray(temp, Uno, TOTAL_POSITIONS) == 1)
								return 2;
						}
					}
				}
			}
			else if(i == 1){
				temp.x = 1;
				temp.y = 4;
				if(CheckArray(temp, Uno, TOTAL_POSITIONS) == 1){
					temp.x = 2;
					temp.y = 3;
					if(CheckArray(temp, Uno, TOTAL_POSITIONS) == 1){
						temp.x = 3;
						temp.y = 2;
						if(CheckArray(temp, Uno, TOTAL_POSITIONS) == 1){
							temp.x = 4;
							temp.y = 1;
							if(CheckArray(temp, Uno, TOTAL_POSITIONS) == 1)
								return 1;
						}
					}
				}
				else if(CheckArray(temp, Tres, TOTAL_POSITIONS) == 1){
					temp.x = 2;
					temp.y = 3;
					if(CheckArray(temp, Tres, TOTAL_POSITIONS) == 1){
						temp.x = 3;
						temp.y = 2;
						if(CheckArray(temp, Tres, TOTAL_POSITIONS) == 1){
							temp.x = 4;
							temp.y = 1;
							if(CheckArray(temp, Uno, TOTAL_POSITIONS) == 1)
								return 2;
						}
					}
				}
			}
			else if(i == 2){
				temp.x = 4;
				temp.y = 1;
				if(CheckArray(temp, Uno, TOTAL_POSITIONS) == 1){
					temp.y = 2;
					if(CheckArray(temp, Uno, TOTAL_POSITIONS) == 1){
						temp.y = 3;
						if(CheckArray(temp, Uno, TOTAL_POSITIONS) == 1){
							temp.y = 4;
							if(CheckArray(temp, Uno, TOTAL_POSITIONS) == 1)
								return 1;
						}
					}
				}
				else if(CheckArray(temp, Tres, TOTAL_POSITIONS) == 1){
					temp.y = 2;
					if(CheckArray(temp, Tres, TOTAL_POSITIONS) == 1){
						temp.y = 3;
						if(CheckArray(temp, Tres, TOTAL_POSITIONS) == 1){
							temp.y = 4;
							if(CheckArray(temp, Uno, TOTAL_POSITIONS) == 1)
								return 2;
						}
					}
				}
			}
		}
	}
	return dosWin;
}

// Function to evaluate or flag when a game is over
int EvaluateGameOver(){};

// Function to declare all as spaces 
void SetBoard(char Board[ROWS][COLS]){
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			Board[i][j] = ' ';
		}
	}
}

// display 
void PrintInput(coordinate pos, char Board[ROWS][COLS]){
	if(Board[pos.x-1][pos.y-1] == 'x'){
		Board[pos.x-1][pos.y-1] = ' ';
	} else{
		Board[pos.x-1][pos.y-1] = 'x';
	}

    printf("      1   2   3   4\n");
    puts("    +---+---+---+---+");

    for (int i = 0; i < ROWS; i++){
        printf("  %d |", i + 1);
        for (int j = 0; j < COLS; j++){
				printf(" \033[31m%c\033[0m |", Board[i][j]);
        }
        printf("\n");
        puts("    +---+---+---+---+");
    }
}
