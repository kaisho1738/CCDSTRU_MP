#include "functions_V1_21.c"
/*
Last Modified: Chino | 8:39AM | 3/31/25
Version: 1.21
    +1 Working Prototype
    +0.1 Finished a function
    +0.01 Small Changes/Debugging
---------------------------------------
Changes:
- Adjusted function names to follow the standard naming convention
--------------------------------------
Code Notes [Bugs or other stuff]:
 
*/

int main(){
    int A[] = {1,2,3,4};
    coordinate pos;
    playerCons B;
    B.turn = 1;
    B.go = 0;
    char Name[50], Name2[50];
    int flag = 1;
    char Board[ROWS][COLS];
    int Player = 0;

    declareNull(Uno, Tres);
    initializeP(P, A);
    findW(C, T, W);
    setBoard(Board);

    for(int i = 0; i < SIZE; i++){
        T[i].x = A[i];
        T[i].y = A[i];
    }

    printf("Enter Player Name: ");
    fgets(Name, 50, stdin);
    removeNewline(Name);

    printf("Enter 2nd Player's Name: ");
    fgets(Name2, 50, stdin);
    removeNewline(Name2);
	
    while(flag != 0){
    findF(F, Uno, Tres, P);

    printf("%s's move [x,y]: ", Name);
    scanf("%d,%d", &pos.x, &pos.y);
    processPlayerMove(F, Uno, Tres, pos, &B);
    printInput(pos, Board);

    printf("%s's move [x,y]: ", Name2);
    scanf("%d,%d", &pos.x, &pos.y);
    processPlayerMove(F, Uno, Tres, pos, &B);
    printInput(pos, Board);
    
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