#include "functions_V1_4.c"
/*
Last Modified: Chino | 11:55AM | 3/31/25
Version: 1.41
    +1 Working Prototype
    +0.1 Finished a function
    +0.01 Small Changes/Debugging
---------------------------------------
Changes:
- Adjusted logic of while loop in main()
- Removed for loop of T[]
--------------------------------------
Code Notes [Bugs or other stuff]:
*/

int main(){
    int A[] = {1,2,3,4};
    int winner = 0;
    coordinate pos = {0,0};
    playerCons B;
    B.turn = 1;
    B.go = 0;
    B.over = 0;
    char Board[ROWS][COLS];

    declareNull(Uno, Tres); // Initializes Uno and Tres to NULL / 0
    initializeP(P, A); // Initialize the values of P[]
    setBoard(Board); // Declaration of spaces

    printf("Let's play!\n\n"); // Starting the game
	do{
	    findF(F, Uno, Tres, P); // Initializes F[]
	    winner = checkWin(Uno, Tres, W, F); // Checks for a winner
	    evaluateGameOver(winner, pos, &B, Board); // Prints based on the value of winner
	    if(winner == 0){ // If no winner has been decided
		    getPos(&pos, &B);
		    processPlayerMove(F, Uno, Tres, pos, &B);
		}
    }while(B.over != 1); // If no winner has been decided
    return 0;
}

/*

  // checker
  for(int i = 0; i < TOTAL_POSITIONS; i++){
    printf("x: %d , y: %d\n", P[i].x, P[i].y);
}


  // checker
  for(int i = 0; i < SIZE; i++){
    printf("x: %d , y: %d\n", T[i].x, T[i].y);
}

 // checker
 printf("\n");
 for(int i = 0; i < SIZE; i++){
     printf("x: %d , y: %d\n", Uno[i].x, Uno[i].y);
     printf("x: %d , y: %d\n", Tres[i].x, Tres[i].y);
 }
     */