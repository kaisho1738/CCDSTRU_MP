#include "functions_V1_0.c"
/*
Last Modified: Chino | 11:00PM | 3/31/25
Version: 0.5
    +1 Working Prototype
    +0.1 Finished a function
    +0.01 Small Changes/Debugging
---------------------------------------
Changes:
	- Added playerCons B
	- Added int x and int y
    - Initialized B.turn and B.go

--------------------------------------
Code Notes [Bugs or other stuff]:
    - 
*/

int main(){
    int A[] = {1,2,3,4};
    int x, y;
    playerCons B;
    B.turn = 1;
    B.go = 0;
	
	initializeP(P, A);
    FindF(F, Uno, Tres, P);
    FindW(C, T, W);
	
    // T = slope looks like '\'
    for(int i = 0; i < SIZE; i++){
        T[i].x = A[i];
        T[i].y = A[i];
    }

    DeclareNull(Uno, Tres);

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
