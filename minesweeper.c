// Author: Evan Glazer
// minesweeper.c


#include <stdio.h>

#define SIZE 8
#define BOMB 9

int main() {
	// Variables defined within game
	int cases, loopings;
	int board[SIZE][SIZE];
    int i,j, numBombs, row, col, square1, square2;	

    // Open the input file.
    FILE* ofp = fopen("mine.txt", "r");
    fscanf(ofp, "%d", &cases);

    // Go through each case.
    for (loopings=1; loopings<=cases; loopings++) {

        // Initialize the board.
        for (i=0; i<SIZE; i++)
            for (j=0; j<SIZE; j++)
                board[i][j] = 0;

        // Read in each bomb.
        fscanf(ofp, "%d", &numBombs);
        for (i=0; i<numBombs; i++) {
            fscanf(ofp, "%d%d", &row, &col);
            board[row][col] = BOMB;
        }

        // Go through each square on the board.
        for (row=0; row<SIZE; row++) {
            for (col=0; col<SIZE; col++) {

                if (board[row][col] == BOMB) continue;

                // check the  adjacent squares to the one.
                for (square1=-1; square1<=1; square1++) {
                    for (square2=-1; square2<=1; square2++) {

                        // Only add if the adjacent square is inbounds and is a bomb.
                        if (row+square1 >= 0 && row+square1 < SIZE)
                            if (col+square2 >=0 && col+square2 < SIZE)
                                if (board[row+square1][col+square2] == BOMB)
                                    board[row][col]++;
                    }
                }
            }
        }

        // Go through each row of the board to print.
        printf("Board #%d:\n", loopings);
        for (i=0; i<SIZE; i++) {

            // Print this row, accounting for bombs.
            for (j=0; j<SIZE; j++) {
                if (board[i][j] != BOMB)
                    printf("%d ", board[i][j]);
                else
                    printf("* ");
            }
            printf("\n");
        }

        // Line between cases.
        printf("\n");
    }
	// Close the file opened
    fclose(ofp);
    // Return 0
    return 0;
// End Main    
}
