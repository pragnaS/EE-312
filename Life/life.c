#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "life.h"

void populateWorld(char fname[], char* grid[], int* numRows, int* numCols) {
 
    FILE *fptr;
    *numCols = 0;
    *numRows = 0;
    fptr = fopen(fname, "r");       //opening world.txt file
 
    if (fptr == NULL)
        printf("File does not exist");
    else {
        char buf[BUFSIZ];
        while (fgets(buf, sizeof(buf), fptr)) {         //reading each row into a buffer
 
            char *testString = (char *) malloc(strlen(buf)+1);    //allocating memory on heap to store contents in buffer
	    strcpy(testString, buf);      //storing buffer contents onto heap
            grid[*numRows] = testString;    //storing row into grid[row_index]
            (*numRows)++;                   //updating row index
        }
        *numCols = strlen(buf) - 1;
    }

    for (int i = 0; i < *numRows; i++) {              //convert the data from 1's and 0's to *'s and .'s
        for (int j = 0; j < *numCols + 1; j++) {
            if (grid[i][j] == '1') {
                grid[i][j] = '*';
            }
            else
                grid[i][j] = '.';
        }
    }

    fclose(fptr); //closing file pointer
}

void showWorld(char* grid[], int numRows, int numCols){
    for(int i=0; i<numRows; i++){
            for(int j=0; j<numCols; j++){
                printf("%c", grid[i][j]);           //printing grid contents to screen
            }
            printf("\n");
        }
 }


void iterateGeneration(char* grid[], int numRows, int numCols) {
    char **tempGrid = malloc(numRows * sizeof(*tempGrid));      //allocating memory to store list of pointers to each row

    for (int i = 0; i < numRows; i++) {
        tempGrid[i] = malloc(numCols * sizeof(**tempGrid));    //allocating memory to each row
    }

    for (int i = 0; i < numRows; i++) {              //copying world grid to temporary grid
        for(int j=0; j< numCols; j++){
	    tempGrid[i] = grid[i];
}
}

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            int check_neighbor = checkCell(grid, numRows, numCols, i, j);     //checking status of cell
            if((check_neighbor == 3) && grid[i][j] == '.')
                newCell(tempGrid, i, j);    //creating a live cell
            if((check_neighbor >=4) && grid[i][j] == '*')
                killCell(tempGrid, i, j);   //killing an overcrowded cell
            if((check_neighbor <=1) && grid[i][j] == '*')
                killCell(tempGrid, i, j);   //killing a lonely cell
            if((check_neighbor == 2 || check_neighbor == 3) && grid[i][j] == '*')
                continue;
        }
    }

    for (int i = 0; i < numRows; i++){
        for(int j = 0; j< numCols; j++){
		grid[i] = tempGrid[i];
}           //copying contents of updated temp grid back into the original grid
    }

    for(int i = 0; i < numRows; i++){
            free(tempGrid[i]);                 //freeing up temp grid allocation
        }
    free(tempGrid);
}

int checkCell(char* grid[], int numRows, int numCols, int curRow, int curCol){
    int neighbor_cell = 0;

    if(curRow == 0){					
        if(curCol == 0){				//checking top left vertex of grid
            if(grid[curRow+1][curCol] == '*')
                neighbor_cell++;
            if(grid[curRow][curCol+1] == '*')
                neighbor_cell++;
            if(grid[curRow+1][curCol+1] == '*')
                neighbor_cell++;
        }
        else if(curCol == numCols-1){			//checking top right vertex of grid
                if(grid[curRow][curCol-1] == '*')
                    neighbor_cell++;
                if(grid[curRow+1][curCol] == '*')
                    neighbor_cell++;
                if(grid[curRow+1][curCol-1] == '*')
                    neighbor_cell++;
             }
        else{					
            if(grid[curRow+1][curCol] == '*')		//checking top row cells
                neighbor_cell++;
            if(grid[curRow+1][curCol-1] == '*')
                neighbor_cell++;
            if(grid[curRow+1][curCol+1] == '*')
                neighbor_cell++;
            if(grid[curRow][curCol-1] == '*')
                neighbor_cell++;
            if(grid[curRow][curCol+1] == '*')
                neighbor_cell++;
        }
    }
    else if(curRow == numRows-1){			
            if(curCol == 0){				//checking bottom left vertex of grid
                if(grid[curRow-1][curCol] == '*')
                    neighbor_cell++;
                if(grid[curRow-1][curCol+1] == '*')
                    neighbor_cell++;
                if(grid[curRow][curCol+1] == '*')
                    neighbor_cell++;
          }
          else if(curCol == numCols-1){			//checking bottom right vertex of grid
                   if(grid[curRow-1][curCol] == '*')
                        neighbor_cell++;
                   if(grid[curRow-1][curCol-1] == '*')
                        neighbor_cell++;
                   if(grid[curRow][curCol-1] == '*')
                        neighbor_cell++;
            }
            else{					//checking bottom row of grid
                if(grid[curRow-1][curCol] == '*')
                    neighbor_cell++;
                if(grid[curRow-1][curCol-1] == '*')
                    neighbor_cell++;
                if(grid[curRow-1][curCol+1] == '*')
                    neighbor_cell++;
                if(grid[curRow][curCol-1] == '*')
                    neighbor_cell++;
                if(grid[curRow][curCol+1] == '*')
                    neighbor_cell++;
            }
    }
    else if((curCol == 0) && (curRow != 0 || curRow != numRows-1)){
        if(grid[curRow-1][curCol] == '*')
            neighbor_cell++;
        if(grid[curRow+1][curCol] == '*')
            neighbor_cell++;
        if(grid[curRow][curCol+1] == '*')
            neighbor_cell++;
        if(grid[curRow+1][curCol+1] == '*')
            neighbor_cell++;
        if(grid[curRow-1][curCol+1] == '*')
            neighbor_cell++;
    }
    else if((curCol == numCols-1) && (curRow != 0 || curRow != numRows-1)){
        if(grid[curRow-1][curCol] == '*')
            neighbor_cell++;
        if(grid[curRow+1][curCol] == '*')
            neighbor_cell++;
        if(grid[curRow][curCol-1] == '*')
            neighbor_cell++;
        if(grid[curRow+1][curCol-1] == '*')
            neighbor_cell++;
        if(grid[curRow-1][curCol-1] == '*')
            neighbor_cell++;
    }
    else{
        if(grid[curRow-1][curCol-1] == '*')
            neighbor_cell++;
        if(grid[curRow-1][curCol] == '*')
            neighbor_cell++;
        if(grid[curRow-1][curCol+1] == '*')
            neighbor_cell++;
        if(grid[curRow][curCol-1] == '*')
            neighbor_cell++;
        if(grid[curRow][curCol+1] == '*')
            neighbor_cell++;
        if(grid[curRow+1][curCol-1] == '*')
            neighbor_cell++;
        if(grid[curRow+1][curCol] == '*')
            neighbor_cell++;
        if(grid[curRow+1][curCol+1] == '*')
            neighbor_cell++;
    }

    return neighbor_cell;

}

void killCell(char* grid[], int curRow, int curCol){
    grid[curRow][curCol] = '.';
}

void newCell(char* grid[], int curRow, int curCol){
    grid[curRow][curCol] = '*';
}


