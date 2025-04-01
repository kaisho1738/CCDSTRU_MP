#include "headers_Final.h"

coordinate P[TOTAL_POSITIONS];
coordinate Uno[TOTAL_POSITIONS];
coordinate Tres[TOTAL_POSITIONS];
coordinate Dos[TOTAL_POSITIONS];
coordinate F[TOTAL_POSITIONS]; // All coordinates/ordered pairs not Uno and Tres
coordinate W[12] = {
    {1,1}, {1,2}, {1,3}, {1,4},
	{1,4}, {2,3}, {3,2}, {4,1},
    {4,4}, {4,3}, {4,2}, {4,1},
};

// Function: 1 Removes New line
void removeNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';  // Replace newline with null terminator
    }
}

// Function 2: Initializes the Value of set P
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

// Function 3: Sets Uno and Tres as null
void declareNull(coordinate Uno[], coordinate Tres[]){
    for(int i = 0; i < TOTAL_POSITIONS; i++){
        Tres[i].x = 0;
        Tres[i].y = 0;
        Uno[i].x = 0;
        Uno[i].y = 0;
    }
}

// Function 4: Checks if a point is found in an array
int checkArray(coordinate point, coordinate arr[], int size){
    int flag = 0;
    for (int i = 0; i < size; i++) {
        if (point.x == arr[i].x && point.y == arr[i].y) {
            flag = 1;
        }
    }
    return flag;
} //will return 1 if there is a match

//Function 5: A function to get the value of set F, set of all available positions
void findF(coordinate F[], coordinate Uno[], coordinate Tres[], coordinate P[]){
    // find all element in P that are not in Uno or Tres then give it to F
    int fIndex = 0;
	
	for (int i = 0; i < TOTAL_POSITIONS; i++) {
        F[i].x = 0;
        F[i].y = 0;
    }

    for(int i = 0; i < TOTAL_POSITIONS; i++){
        if(!checkArray(P[i], Uno, TOTAL_POSITIONS) && !checkArray(P[i], Tres, TOTAL_POSITIONS)){
            //condition that checks if the coordinate in Uno and tres are not matched with any of P
            //if there is no match, P will be assigned to F;
            F[fIndex] = P[i];
            fIndex++;
        }
    }
}

//Functtion 6: function to process action with given inputs; remove pos (if pos is in Uno or Tres) otherwise, add the element 
void processPlayerMove(coordinate F[], coordinate Uno[], coordinate Tres[], coordinate pos, playerCons *B){
	int i, found = 0;

	found = checkArray(pos, F, TOTAL_POSITIONS);

	if(B->turn == 1 && B->go == 1){ //Uno's turn and inputted coordinates is in F[]
		if(found){
			for(i = 0; i < TOTAL_POSITIONS; i++){
				if(Uno[i].x == 0 && Uno[i].y == 0){ //Finds an empty array and places coordinates there
					Uno[i] = pos;
					i = TOTAL_POSITIONS;
				}
			}
		B->turn = 0;
		B->go = 0;
		} else printf("Error: Position Already Taken!\n");
	} 
	
	else if(B->turn == 0){ // Dos' turn and inputted coordinates is not in F[]
		if(!found){
			for(i = 0; i < TOTAL_POSITIONS; i++){ // Finds the array with the inputted coordinates
				if(Uno[i].x == pos.x && Uno[i].y == pos.y){ // Inputted coordinates are in Uno's array
					Uno[i].x = 0;
					Uno[i].y = 0;
					i = TOTAL_POSITIONS;
					B->turn = 1;
				}
				else if(Tres[i].x == pos.x && Tres[i].y == pos.y){ // Inputted coordinates are in Tres' array
					Tres[i].x = 0;
					Tres[i].y = 0;
					i = TOTAL_POSITIONS;
					B->turn = 1;
				}
			}
		} else printf("Error: No mark to remove!\n");
	} 
	
	else if(B->turn == 1 && B->go == 0 ){ // Tres' turn and inputted coordinates is in F[]
		if(found){
		for(i = 0; i < TOTAL_POSITIONS; i++){
			if(Tres[i].x == 0 && Tres[i].y == 0){
				Tres[i] = pos;
				i = TOTAL_POSITIONS;
			}
		}
		B->go = 1;
	} else{
		printf("Error: Position Already Taken!\n");
	}
	}
}

// Function 7: Asks for user input
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
	printf("\n");
}

// Function 8: Checks if there are any winning conditions
int checkWin(coordinate Uno[], coordinate Tres[], coordinate W[], coordinate F[]){
	int i, j, whoWins = 2;
	
	for(j = 0; j < TOTAL_POSITIONS; j++){ // Checks if there are coordinate values in F[] and change the value of whoWins accordinlgy
		if (F[j].x != 0){
            whoWins = 0;
            j = TOTAL_POSITIONS;
        }
	}
	
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
				
				if(checkArray(W[0], Tres, TOTAL_POSITIONS) == 1){ // Evaluating Tres
					if(checkArray(W[1], Tres, TOTAL_POSITIONS) == 1){
						if(checkArray(W[2], Tres, TOTAL_POSITIONS) == 1){
							if(checkArray(W[3], Tres, TOTAL_POSITIONS) == 1)
								whoWins = 3;
						}
					}
				}
			}
			else if(i == 1){ // Checks if {1,4}, {2,3}, {3,2}, {4,1} is in Uno or Tres
				if(checkArray(W[4], Uno, TOTAL_POSITIONS) == 1){ // Evaluating Uno
					if(checkArray(W[5], Uno, TOTAL_POSITIONS) == 1){
						if(checkArray(W[6], Uno, TOTAL_POSITIONS) == 1){
							if(checkArray(W[7], Uno, TOTAL_POSITIONS) == 1)
								whoWins = 1;
						}
					}
				}
				
				if(checkArray(W[4], Tres, TOTAL_POSITIONS) == 1){ // Evaluating Tres
					if(checkArray(W[5], Tres, TOTAL_POSITIONS) == 1){
						if(checkArray(W[6], Tres, TOTAL_POSITIONS) == 1){
							if(checkArray(W[7], Tres, TOTAL_POSITIONS) == 1)
								whoWins = 3;
						}
					}
				}
			}
			else if(i == 2){ // Checks if {4,1}, {4,2}, {4,3}, {4,4} is in Uno or Tres
				if(checkArray(W[8], Uno, TOTAL_POSITIONS) == 1){ // Evaluating Uno
					if(checkArray(W[9], Uno, TOTAL_POSITIONS) == 1){
						if(checkArray(W[10], Uno, TOTAL_POSITIONS) == 1){
							if(checkArray(W[11], Uno, TOTAL_POSITIONS) == 1)
								whoWins = 1;
						}
					}
				}
				
				if(checkArray(W[8], Tres, TOTAL_POSITIONS) == 1){ //Evaluating Tres
					if(checkArray(W[9], Tres, TOTAL_POSITIONS) == 1){
						if(checkArray(W[10], Tres, TOTAL_POSITIONS) == 1){
							if(checkArray(W[11], Tres, TOTAL_POSITIONS) == 1)
								whoWins = 3;
						}
					}
				}
			}
		}
	}
	return whoWins;
}

// Function 9: Checks if the game is over
void evaluateGameOver(int winner, coordinate pos, playerCons *B, char Board[][COLS]){
	switch(winner){ // Prints based on the value of winner and change the value of over
		case 0: // If no player has won
			printInput(Board, Uno, Tres);
			break;
		case 1: // If Uno has won
			printf("Uno wins!\n");
			printf("Game Over!\n");
			printInput(Board, Uno, Tres);
			B->over = 1;
			break;
		case 2: // If Dos has won
			printf("Dos wins!\n");
			printf("Game Over!\n");
			printInput(Board, Uno, Tres);
			B->over = 1;
			break;
		case 3: // If Tres has won
			printf("Tres wins!\n");
			printf("Game Over!\n");
			printInput(Board, Uno, Tres);
			B->over = 1;
			break;
	}
}

// Function 9: Sets the board to all spaces/null
void setBoard(char Board[ROWS][COLS]){
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			Board[i][j] = ' ';
		}
	}
}

// Function 10: Prints the board with the elements contained in Uno and Tres
// Does not print Dos since an element is directly removed from Uno and Tres in function processPlayerMove
void printInput(char Board[ROWS][COLS], coordinate Uno[], coordinate Tres[]) {
    // Reset the board to empty
    setBoard(Board);  // Clear all cells to ' '

    // Mark Uno's positions with 'X'
    for (int i = 0; i < TOTAL_POSITIONS; i++) {
        if (Uno[i].x != 0 || Uno[i].y != 0) { //checks if there is an existing value
            int x = Uno[i].x - 1; //if there is an existing value, x or y is assigned as the index of the board
            int y = Uno[i].y - 1;
            if (x >= 0 && x < ROWS && y >= 0 && y < COLS) { //Checks the limit of the board
                Board[x][y] = 'X'; //Assigns a symbol to a specific element of Board
            }
        }
    }

    // Mark Tres' positions with 'O'
    for (int i = 0; i < TOTAL_POSITIONS; i++) {
        if (Tres[i].x != 0 || Tres[i].y != 0) { //checks if there is an existing value
            int x = Tres[i].x - 1; //if there exists a value, x and y will serve as the index of the board
            int y = Tres[i].y - 1;
            if (x >= 0 && x < ROWS && y >= 0 && y < COLS) {
                Board[x][y] = 'O'; //Assigns a symbol to a specific element of Board
            }
        }
    }

    // Upper column of table
    printf("      1   2   3   4\n");
    puts("    +---+---+---+---+");

    for (int i = 0; i < ROWS; i++) {
        printf("  %d |", i + 1); //Number at the side of the table
        for (int j = 0; j < COLS; j++) {
            if (Board[i][j] == 'X') {
                printf(" \033[31m%c\033[0m |", Board[i][j]);  // Red for Uno; Prints out all the values or X's 
            } else if (Board[i][j] == 'O') {
                printf(" \033[34m%c\033[0m |", Board[i][j]);  // Blue for Tres  Red for Uno; Prints out all the values or O's contained
            } else {
                printf(" %c |", Board[i][j]);  // Empty cell
            }
        }
        printf("\n");
        puts("    +---+---+---+---+");
    }
}