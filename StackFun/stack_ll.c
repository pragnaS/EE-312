#include "stack_ll.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void makeStack(Stack312 *s){
    s->top == NULL;
}

bool isEmpty(Stack312 s){
    if(s.top == NULL){
        return true;
    }
}

void push(StackEntry e,Stack312 *s){
    StackNode *temp = (StackNode *) malloc(sizeof(StackNode));
    temp->next = s->top;
    temp->pixel = e;
    s->top = temp;
}

StackEntry pop(Stack312 *s){
    StackNode *temp = s->top;
    s->top = temp->next;
    StackEntry output = temp->pixel;
    free(temp);
    return output;

}


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

void checkNeighbor(char* grid[], int numRows, int numCols, int row, int col, char inputColor, char origColor, Stack312 *s){
    StackEntry temp;
    if(row == 0){
        if(col == 0){
            if(grid[row+1][col] == origColor){
                wrap_and_push(grid, inputColor, row+1, col, origColor, s);
}
            if(grid[row][col+1] == origColor){
                wrap_and_push(grid, inputColor, row, col+1, origColor, s);   
}
            if(grid[row+1][col+1] == origColor){
                wrap_and_push(grid, inputColor, row+1, col+1, origColor, s);
}
        }
        else if(col == numCols-1){
            if(grid[row][col-1] == origColor)
                wrap_and_push(grid, inputColor, row, col-1, origColor, s);
            if(grid[row+1][col] == origColor)
                wrap_and_push(grid, inputColor, row+1, col, origColor, s);
            if(grid[row+1][col-1] == origColor)
                wrap_and_push(grid, inputColor, row+1, col-1, origColor, s);
        }
        else{
            if(grid[row+1][col] == origColor)
                wrap_and_push(grid, inputColor, row+1, col, origColor, s);
            if(grid[row+1][col-1] == origColor)
                wrap_and_push(grid, inputColor, row+1, col-1, origColor, s);
            if(grid[row+1][col+1] == origColor)
                wrap_and_push(grid, inputColor, row+1, col+1, origColor, s);
            if(grid[row][col-1] == origColor)
                wrap_and_push(grid, inputColor, row, col-1, origColor, s);
            if(grid[row][col+1] == origColor)
                wrap_and_push(grid, inputColor, row, col+1, origColor, s);
        }
    }
    else if(row == numRows-1){
        if(col == 0){
            if(grid[row-1][col] == origColor)
                wrap_and_push(grid, inputColor, row-1, col, origColor, s);
            if(grid[row-1][col+1] == origColor)
                wrap_and_push(grid, inputColor, row-1, col+1, origColor, s);
            if(grid[row][col+1] == origColor)
                wrap_and_push(grid, inputColor, row, col+1, origColor, s);
        }
        else if(col == numCols-1){
            if(grid[row-1][col] == origColor)
                wrap_and_push(grid, inputColor, row-1, col, origColor, s);
            if(grid[row-1][col-1] == origColor)
                wrap_and_push(grid, inputColor, row-1, col-1, origColor, s);
            if(grid[row][col-1] == origColor)
                wrap_and_push(grid, inputColor, row, col-1, origColor, s);
        }
        else{
            if(grid[row-1][col] == origColor)
                wrap_and_push(grid, inputColor, row-1, col, origColor, s);
            if(grid[row-1][col-1] == origColor)
                wrap_and_push(grid, inputColor, row-1, col-1, origColor, s);
            if(grid[row-1][col+1] == origColor)
                wrap_and_push(grid, inputColor, row-1, col+1, origColor, s);
            if(grid[row][col-1] == origColor)
                wrap_and_push(grid, inputColor, row, col-1, origColor, s);
            if(grid[row][col+1] == origColor)
                wrap_and_push(grid, inputColor, row, col+1, origColor, s);
        }
    }
    else if((col == 0) && (row != 0 || row != numRows-1)){
        if(grid[row-1][col] == origColor)
            wrap_and_push(grid, inputColor, row-1, col, origColor, s);
        if(grid[row+1][col] == origColor){
            wrap_and_push(grid, inputColor, row+1, col, origColor, s);
}

        if(grid[row][col+1] == origColor)
            wrap_and_push(grid, inputColor, row, col+1, origColor, s);
        if(grid[row+1][col+1] == origColor)
            wrap_and_push(grid, inputColor, row+1, col+1, origColor, s);
        if(grid[row-1][col+1] == origColor)
            wrap_and_push(grid, inputColor, row-1, col+1, origColor, s);
    }
    else if((col == numCols-1) && (row != 0 || row != numRows-1)){
        if(grid[row-1][col] == origColor)
            wrap_and_push(grid, inputColor, row-1, col, origColor, s);
        if(grid[row+1][col] == origColor)
            wrap_and_push(grid, inputColor, row+1, col, origColor, s);
        if(grid[row][col-1] == origColor)
            wrap_and_push(grid, inputColor, row, col-1, origColor, s);
        if(grid[row+1][col-1] == origColor)
            wrap_and_push(grid, inputColor, row+1, col-1, origColor, s);
        if(grid[row-1][col-1] == origColor)
            wrap_and_push(grid, inputColor, row-1, col-1, origColor, s);
    }
    else{
        if(grid[row-1][col-1] == origColor)
            wrap_and_push(grid, inputColor, row-1, col-1, origColor, s);
        if(grid[row-1][col] == origColor)
            wrap_and_push(grid, inputColor, row-1, col, origColor, s);
        if(grid[row-1][col+1] == origColor)
            wrap_and_push(grid, inputColor, row-1, col+1, origColor, s);
        if(grid[row][col-1] == origColor)
            wrap_and_push(grid, inputColor, row, col-1, origColor, s);
        if(grid[row][col+1] == origColor)
            wrap_and_push(grid, inputColor, row, col+1, origColor, s);
        if(grid[row+1][col-1] == origColor)
            wrap_and_push(grid, inputColor, row+1, col-1, origColor, s);
        if(grid[row+1][col] == origColor)
            wrap_and_push(grid, inputColor, row+1, col, origColor, s);
        if(grid[row+1][col+1] == origColor)
            wrap_and_push(grid, inputColor, row+1, col+1, origColor, s);
    }
}

void wrap_and_push(char* grid[], char input_color, int row, int col, char color, Stack312 *s){
    StackEntry wrapped;
    wrapped.row = row;
    wrapped.col = col;
    wrapped.color = color;
    
    grid[row][col] = input_color;
    push(wrapped, s);
}
    




