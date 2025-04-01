#include "functions_Final_v2.1.c"
/*
 Description: A 4x4 Tic-Tac-Toe Game where Uno, Dos and Tres play against each other.
 Uno and Tres can mark coordinates while Dos can remove marks. When the board fills up
 and no winning conditions are met by either Uno and Tres, Dos wins.
 
 Programmed by: ID: 12411388, Kim Francis C. Herrera - S26
 Programmed by: ID: 12412686, James Benedict T. Marquez - S26
 Last modified: April 1, 2025
 Version: 1.6
 Acknowledgements:
    - https://byjus.com/maths/set-theory-symbols/ For decoding the MP specs with regards to sets
    - https://gist.github.com/JBlond/2fea43a3049b38287e5e9cefc87b2124 ASCII color table
*/

int main(){
    int A[] = {1,2,3,4};
    int winner = 0;
    coordinate pos = {0,0};
    playerCons B;
    B.turn = 1;
    B.go = 0;
    char Board[SIZE][SIZE];

    initializeNull(Uno, Tres); // Initializes Uno and Tres to NULL / 0
    initializeP(P, A); // Initialize the values of P[]
    setBoard(Board); // Declaration of spaces

    printf("Let's play!\n\n"); // Starting the game
	do{
	    initializeF(F, Uno, Tres, P); // Initializes F[]
	    winner = checkWin(Uno, Tres, W, F); // Checks for a winner
	    evaluateGameOver(winner, Uno, Tres, &B, Board); // Prints based on the value of winner
	    if(winner == 0){ // If no winner has been decided
            getPos(&pos, &B);
		    processPlayerMove(F, Uno, Tres, pos, &B);
            printBoard(Board, Uno, Tres);
            system("pause"); //awaits the user for any input before clearing
            system("cls"); //clears the screen
		}
    }while(B.over != 1); // If no winner has been decided
    return 0;
}
