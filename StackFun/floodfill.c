#include "stack_ll.h"
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    //edit these two lines and use the command line arguments
    char *fName = argv[1];
    const int MAX_ROWS = 25; //we want the world to fit on one screen
    bool finished = false;

    Stack312 stack;     //declaring a stack structure
    Stack312* stackPt = &stack;    //creating a stack pointer
    makeStack(&stack);    //making a stack

    //array of strings that will hold the grid
    char *world[MAX_ROWS];
    int numRows;
    int numCols;
    StackEntry input;

    populateWorld(fName, world, &numRows, &numCols);
    showWorld(world, numRows, numCols);

    while(!finished) {
        //prompt user for input
        printf("\nenter row\n");
        scanf("%d", &input.row);
        printf("enter col\n");
        scanf("%d", &input.col);
        printf("enter color\n");
        scanf(" %c", &input.color);

        if(input.row == -1 ||input.col == -1){
		finished = true;
        }	
	//checking if input is valid. If invalid, finish program
        else if(input.row>25 || input.col>25 || input.row<-1 || input.col<-1){
            printf("Invalid input\n");
            finished = true;
        }
        else{
            push(input, stackPt);       //pushing user's input pixel on to stack
            char orig_color = world[input.row][input.col];
	    world[input.row][input.col] = input.color;

            while (!isEmpty(stack)) {
                StackEntry temp = pop(stackPt);

                int current_row = temp.row;
                int current_col = temp.col;
                checkNeighbor(world, numRows, numCols, current_row, current_col, input.color, orig_color, stackPt);
            }
            showWorld(world, numRows, numCols);

        }
    }
    printf("\nFINISHED");
}
