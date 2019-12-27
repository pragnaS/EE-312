#include "recurse.h"
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    //edit these two lines and use the command line arguments
    char *fName = "fake_picture.txt";
    const int MAX_ROWS = 25; //we want the world to fit on one screen
    bool finished = false;

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
        else if(input.row>25 || input.col>25 || input.row<-1 || input.col<-1 || input.row>=numRows || input.col>=numCols){
            printf("Invalid input\n");
            finished = true;
        }
        else{
            char orig_color = world[input.row][input.col];
	        world[input.row][input.col] = input.color;
            if(checkNeighbor(world, numRows, numRows, input.row, input.col, input.color, orig_color) == 0)
                showWorld(world, numRows, numCols);
        }
    }
    printf("\nFINISHED");
}
