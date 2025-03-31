#include <stdio.h>
#define SIZE 4  
#define TOTAL_POSITIONS (SIZE * SIZE)

/*
Last Modified: Kim | 5:15 | 3/31/25
Version:
    +1 Working Prototype
    +0.1 Finished a function
    +0.01 Small Changes/Debugging
---------------------------------------
Changes:

--------------------------------------
Code Notes [Bugs or other stuff]:


*/

typedef struct{
    int x;
    int y;
} coordinate;

coordinate P[TOTAL_POSITIONS];
coordinate T[SIZE];
coordinate Uno[SIZE];
coordinate Tres[SIZE];
coordinate Dos[SIZE];
coordinate F[TOTAL_POSITIONS]; //All coordinates/ordered pairs not Uno and Tres

void DeclareNull(coordinate Uno[], coordinate Tres[]){
    for(int i = 0; i < SIZE; i++){
        Tres[i].x = 0;
        Tres[i].y = 0;
        Uno[i].x = 0;
        Uno[i].y = 0;
    }
}