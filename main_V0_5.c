#include "functions_V0_5.c"
/*
Last Modified: Chino | 9:58PM | 3/31/25
Version: 0.5
    +1 Working Prototype
    +0.1 Finished a function
    +0.01 Small Changes/Debugging
---------------------------------------
Changes:
    - Removed int Turn, Go and Over
--------------------------------------
Code Notes [Bugs or other stuff]:
    - 
*/

int main(){
    int A[] = {1,2,3,4};
    int B; // true or false
    int C; // vertical lines and slopes
    
    int index = 0;

    // P = A x A
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            P[index].x = A[i];
            P[index].y = A[j];
            index++;
        }
    }

    // T = slope looks like '/'
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
