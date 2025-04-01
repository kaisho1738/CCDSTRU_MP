#include "headers_V1_3.h"
/*
Last Modified: Chino | 11:55AM | 3/31/25
Version: 1.21
    +1 Working Prototype
    +0.1 Finished a function
    +0.01 Small Changes/Debugging
---------------------------------------
Changes:
- Adjusted function names to follow the standard naming convention
- Added logic to evaluateGameOver()
- Removed findW() as deemed unnecessary
- Adjusted values of W[]
--------------------------------------
Code Notes [Bugs or other stuff]:
- to add differentiating symbols
- to fix findF repeating coordinates
*/
coordinate P[TOTAL_POSITIONS];
coordinate T[TOTAL_POSITIONS];
coordinate Uno[TOTAL_POSITIONS];
coordinate Tres[TOTAL_POSITIONS];
coordinate Dos[TOTAL_POSITIONS];
coordinate F[TOTAL_POSITIONS]; // All coordinates/ordered pairs not Uno and Tres
coordinate W[12] = {
    {1,1}, {1,2}, {1,3}, {1,4},
	{1,4}, {2,3}, {3,2}, {4,1},
    {4,4}, {4,3}, {4,2}, {4,1},
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

void declareNull(coordinate Uno[], coordinate Tres[]){
    for(int i = 0; i < TOTAL_POSITIONS; i++){
        Tres[i].x = 0;
        Tres[i].y = 0;
        Uno[i].x = 0;
        Uno[i].y = 0;
    }
}

int checkArray(coordinate point, coordinate arr[], int size){
    int flag = 0;
    for (int i = 0; i < size; i++) {
        if (point.x == arr[i].x && point.y == arr[i].y) {
            flag = 1;
        }
    }
    return flag;
} //will return 1 if there is a match

//function to get F
void findF(coordinate F[], coordinate Uno[], coordinate Tres[], coordinate P[]){
    // find all element in P that are not in uno or tres then give it to F
    int fIndex = 0;
    for(int i = 0; i < TOTAL_POSITIONS; i++){
        if(!checkArray(P[i], Uno, TOTAL_POSITIONS) && !checkArray(P[i], Tres, TOTAL_POSITIONS)){
            //condition that checks if the coordinate in Uno and tres are not matched with any of P
            //if there is no match, P will be assigned to F;
            F[fIndex] = P[i];
            fIndex++;
        }
    }
}

//function to process action with given inputs; remove pos (if pos is in Uno or Tres) otherwise, add the element 
void processPlayerMove(coordinate F[], coordinate Uno[], coordinate Tres[], coordinate pos, playerCons *B){
	int i, found;
	
	found = checkArray(pos, F, TOTAL_POSITIONS); //Tries to find the coordinates in F[] and change the value of found
	
	if(B->turn == 1 && B->go == 1 && found == 1){ //Uno's turn and inputted coordinates is in F[]
		for(i = 0; i < TOTAL_POSITIONS; i++){
			if(Uno[i].x == 0 && Uno[i].y == 0){ //Finds an empty array and places coordinates there
				Uno[i] = pos;
				i = TOTAL_POSITIONS;
			}
		}
		B->turn = 0;
		B->go = 0;
	}
	else if(B->turn == 0 && found == 0){ // Dos' turn and inputted coordinates is not in F[]
		for(i = 0; i < TOTAL_POSITIONS; i++){ // Finds the array with the inputted coordinates
			if(Uno[i].x == pos.x && Uno[i].y == pos.y){ // Inputted coordinates are in Uno's array
				Uno[i].x = 0;
				Uno[i].y = 0;
				i = TOTAL_POSITIONS;
			}
			else if(Tres[i].x == pos.x && Tres[i].y == pos.y){ // Inputted coordinates are in Tres' array
				Tres[i].x = 0;
				Tres[i].y = 0;
				i = TOTAL_POSITIONS;
			}
		}
		B->turn = 1;
	}
	else if(B->turn == 1 && B->go == 0 && found == 1){ // Tres' turn and inputted coordinates is in F[]
		for(i = 0; i < TOTAL_POSITIONS; i++){
			if(Tres[i].x == 0 && Tres[i].y == 0){
				Tres[i] = pos;
				i = TOTAL_POSITIONS;
			}
		}
		B->go = 1;
	}
}

// function for user input
void getPos(coordinate *pos, playerCons *B){
	if(B->turn == 1 && B->go == 1){ // Uno's turn
		printf("Your turn, Uno! Input coordinates: ");
		scanf("%d,%d", &pos->x, &pos->y);
	}
	else if(B->turn == 1 && B->go == 0){ // Tres' turn
		printf("Your turn, Tres! Input coordinates: ");
		scanf("%d,%d", &pos->x, &pos->y);
	}
	else if(B->turn == 0){ // Dos' turn
		printf("Your turn, Dos! Input coordinates: ");
		scanf("%d,%d", &pos->x, &pos->y);
	}
}

// function to check if there are any winning conditions
int checkWin(coordinate Uno[], coordinate Tres[], coordinate W[], coordinate F[]){
	int i, j, whoWins = 0;
	coordinate temp;
	
	if(whoWins == 0){
		for(i = 0; i < 3; i++){ // Checks different win conditions and changes the value depending on who won
			if(i == 0){ // Checks if {1,1}, {1,2}, {1,3}, {1,4} is in Uno or Tres
				if(checkArray(W[0], Uno, TOTAL_POSITIONS) == 1){ // Evaluating Uno
					if(checkArray(W[1], Uno, TOTAL_POSITIONS) == 1){
						if(checkArray(W[2], Uno, TOTAL_POSITIONS) == 1){
							if(checkArray(W[3], Uno, TOTAL_POSITIONS) == 1)
								whoWins = 1;
						}
					}
				}
				else if(checkArray(W[0], Tres, TOTAL_POSITIONS) == 1){ // Evaluating Tres
					if(checkArray(W[1], Tres, TOTAL_POSITIONS) == 1){
						if(checkArray(W[2], Tres, TOTAL_POSITIONS) == 1){
							if(checkArray(W[3], Tres, TOTAL_POSITIONS) == 1)
								whoWins = 3;
						}
					}
				}
			}
			else if(i == 1){ // Checks if {1,4}, {3,2}, {2,3}, {4,1} is in Uno or Tres
				if(checkArray(W[4], Uno, TOTAL_POSITIONS) == 1){ // Evaluating Uno
					if(checkArray(W[5], Uno, TOTAL_POSITIONS) == 1){
						if(checkArray(W[6], Uno, TOTAL_POSITIONS) == 1){
							if(checkArray(W[7], Uno, TOTAL_POSITIONS) == 1)
								whoWins = 1;
						}
					}
				}
				else if(checkArray(W[4], Tres, TOTAL_POSITIONS) == 1){ // Evaluating Tres
					if(checkArray(W[5], Tres, TOTAL_POSITIONS) == 1){
						if(checkArray(W[6], Tres, TOTAL_POSITIONS) == 1){
							if(checkArray(W[7], Tres, TOTAL_POSITIONS) == 1)
								whoWins = 3;
						}
					}
				}
			}
			else if(i == 2){ // Checks if {4,1}, {4,2}, {4,3}, {4,4} is in Uno or Tres
				temp.x = 4;
				temp.y = 1;
				if(checkArray(temp, Uno, TOTAL_POSITIONS) == 1){ // Evaluating Uno
					temp.y = 2;
					if(checkArray(temp, Uno, TOTAL_POSITIONS) == 1){
						temp.y = 3;
						if(checkArray(temp, Uno, TOTAL_POSITIONS) == 1){
							temp.y = 4;
							if(checkArray(temp, Uno, TOTAL_POSITIONS) == 1)
								whoWins = 1;
						}
					}
				}
				else if(checkArray(temp, Tres, TOTAL_POSITIONS) == 1){ //Evaluating Tres
					temp.y = 2;
					if(checkArray(temp, Tres, TOTAL_POSITIONS) == 1){
						temp.y = 3;
						if(checkArray(temp, Tres, TOTAL_POSITIONS) == 1){
							temp.y = 4;
							if(checkArray(temp, Tres, TOTAL_POSITIONS) == 1)
								whoWins = 3;
						}
					}
				}
			}
		}
	}
	return whoWins;
}

// Function to evaluate or flag when a game is over
void evaluateGameOver(int winner, coordinate pos, playerCons *B, char Board[][COLS]){
	switch(winner){ // Prints based on the value of winner and change the value of over
		case 0: // If no player has won
			printf("Keep playing!\n");
			break;
		case 1: // If Uno has won
			printf("\nUno wins!\n");
			printf("Game Over!\n");
			printInput(pos, Board);
			B->over = 1;
			break;
		case 2: // If Dos has won
			printf("\nDos wins!\n");
			printf("Game Over!\n");
			printInput(pos, Board);
			B->over = 1;
			break;
		case 3: // If Tres has won
			printf("\nTres wins!\n");
			printf("Game Over!\n");
			printInput(pos, Board);
			B->over = 1;
			break;
	}
}

// Function to declare all as spaces 
void setBoard(char Board[ROWS][COLS]){
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			Board[i][j] = ' ';
		}
	}
}

// display 
void printInput(coordinate pos, char Board[ROWS][COLS]){
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
