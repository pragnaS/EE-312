#include "recurse.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void populateWorld(char fname[], char* grid[], int* numRows, int* numCols) {
    FILE *fptr;
    *numCols = 0;
    *numRows = 0;

    fptr = fopen(fname, "r");       //opening txt file

    if (fptr == NULL)
        printf("File does not exist");
    else {
        char buf[BUFSIZ];
        while (fgets(buf, sizeof(buf), fptr)) {    //reading each row into a buffer
            char *testString = (char *) malloc(strlen(buf) + 1);    //allocating memory on heap to store contents in buffer
            strcpy(testString, buf);      //storing buffer contents onto heap
            grid[*numRows] = testString;    //storing row into grid[row_index]
            (*numRows)++;                   //updating row index
        }
        *numCols = strlen(buf) - 1;
    }
}

void showWorld(char* grid[], int numRows, int numCols){
    for(int i=0; i<numRows; i++){
        for(int j=0; j<numCols; j++){
            printf("%c", grid[i][j]);           //printing grid contents to screen
        }
        printf("\n");
    }
}

int checkNeighbor(char* grid[], int numRows, int numCols, int row, int col, char inputColor, char origColor) {
    int count = 0;
    for(int i=-1; i<=1; i++){
        if(!((row+i)<0 || (row+i)>=numRows)){
            for(int j=-1; j<=1; j++){
                if(!((col+j)<0 || (col+j)>=numCols)){
                    if(grid[row+i][col+j] == origColor){
                        count++;
                        grid[row+i][col+j] = inputColor;
                        count = checkNeighbor(grid, numRows, numCols, row+i, col+j, inputColor, origColor);
                    }
                }
            }
        }
    }
    return count;

}
