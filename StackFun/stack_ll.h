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

typedef struct StackNode {
   StackEntry pixel;
   struct StackNode *next;
} StackNode;
   
typedef struct Stack312 {
   struct StackNode *top;
} Stack312;

void makeStack(Stack312 *s);

bool isFull(Stack312 s);

bool isEmpty(Stack312 s);

void push(StackEntry e,Stack312 *s);

StackEntry pop(Stack312 *s);

void populateWorld(char fname[], char* grid[], int* numRows, int* numCols);

void showWorld(char* grid[], int numRows, int numCols);

void wrap_and_push(char* grid[], char input_color, int row, int col, char color, Stack312 *s);

void checkNeighbor(char* grid[], int numRows, int numCols, int row, int col, char inputColor, char origColor, Stack312 *s);
