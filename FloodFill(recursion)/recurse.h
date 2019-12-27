//stack_ll.h
//Add documentation including Pre and Post conditions for functions

#include <stdio.h>
#include <stdbool.h>

typedef struct Pixel {
   int row;
   int col;
   char color;
} Pixel;

typedef Pixel StackEntry;

void populateWorld(char fname[], char* grid[], int* numRows, int* numCols);

void showWorld(char* grid[], int numRows, int numCols);

int checkNeighbor(char* grid[], int numRows, int numCols, int row, int col, char inputColor, char origColor);

