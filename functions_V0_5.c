#include <stdio.h>
#define SIZE 4  
#define TOTAL_POSITIONS (SIZE * SIZE)

/*
Last Modified: Chino | 7:05PM | 3/31/25
Version:
    +1 Working Prototype
    +0.1 Finished a function
    +0.01 Small Changes/Debugging
---------------------------------------
Changes:
- Changed size of array for Uno, Tres, Dos to TOTAL_POSITIONS
- Changed i < SIZE to i < TOTAL_POSITIONS of for loop of DeclareNull
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

void DeclareNull(coordinate Uno[], coordinate Tres[]){
    for(int i = 0; i < TOTAL_POSITIONS; i++){
        Tres[i].x = 0;
        Tres[i].y = 0;
        Uno[i].x = 0;
        Uno[i].y = 0;
    }
}
