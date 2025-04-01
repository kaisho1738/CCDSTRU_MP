#include "functions_V1_3.c"
/*
Last Modified: Chino | 11:55AM | 3/31/25
Version: 1.21
    +1 Working Prototype
    +0.1 Finished a function
    +0.01 Small Changes/Debugging
---------------------------------------
Changes:
- Adjusted function names to follow the standard naming convention
- Adjusted logic of main to utilize functions
- Removed calling of findW()
--------------------------------------
Code Notes [Bugs or other stuff]:
*/

int main(){
    int A[] = {1,2,3,4};
    int winner;
    coordinate pos = {0,0};
    playerCons B;
    B.turn = 1;
    B.go = 0;
    B.over = 0;
    char Board[ROWS][COLS];

    declareNull(Uno, Tres);
    initializeP(P, A);
    setBoard(Board);

    for(int i = 0; i < SIZE; i++){
        T[i].x = A[i];
        T[i].y = A[i];
    }
	
    while(B.over != 1){
    findF(F, Uno, Tres, P);
	printInput(pos, Board);
    getPos(&pos, &B);
    processPlayerMove(F, Uno, Tres, pos, &B);
    winner = checkWin(Uno, Tres, W, F);
    evaluateGameOver(winner, pos, &B, Board);
    }
    return 0; // Add return statement for `main()`
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