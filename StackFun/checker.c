#include <stdlib.h>
#include <stdio.h>
#include "stack_arr.h"
#include <string.h>

int main(int argc, char *argv[]){

    char *fName = argv[1];
    char* grid[1];
    int numCols = 0;
    int missingbrackets = 0;
    int balanced = 1;

    Stack312 stack;     //declaring a stack structure
    Stack312* stackPt = &stack; //creating a stack pointer
    makeStack(&stack);  //creating a stack

    FILE *fptr;

    fptr = fopen(fName, "r");
    if(fptr == NULL)
        printf("File does not exist");
    else{
        char buf[80];
        while (fgets(buf, sizeof(buf), fptr)) {    //reading each equation into a buffer
            char *testString = (char *) malloc(strlen(buf));
            strcpy(testString, buf);
            grid[0] = testString;
            numCols = strlen(buf);

            printf("%s === ", grid[0]);     //printing equation

            // for(int i=0; i<1; i++){
            for (int j = 0; j < numCols; j++) {
                if ((grid[0][j] == '{') || (grid[0][j] == '(') ||
                    (grid[0][j] == '['))        //pushing open brackets on to stack
                    push(grid[0][j], stackPt);
                else if ((grid[0][j] == '}') || (grid[0][j] == ')') || (grid[0][j] == ']')) {
                    StackEntry check = pop(&stack);
                    if (check ==-1) {                //if stack is empty, closing brackets do not have corresponding open brackets
                        if (grid[0][j] == '}') {
                            printf("{");
                            missingbrackets = 1;
                        }
                        if (grid[0][j] == ')') {
                            printf("(");
                            missingbrackets = 1;
                        }
                        if (grid[0][j] == ']') {
                            printf("[");
                            missingbrackets = 1;
                        }
                    } else if (isPair(check, grid[0][j]))      //if pair of brackets exist, continue
                        continue;
                    else if (!isPair(check,grid[0][j])) {     //if pair of brackets does not exist, brackets are mismatched. Equation is not balanced
                        printf("mismatched brackets");
                        balanced = 0;
                        break;
                    }
                }
            }

            if (!isEmpty(stack)&& balanced!=0) {
                while (!isEmpty(stack)) {
                    char missing = pop(&stack);
                    if (missing == '(')
                        printf(")");
                    if (missing == '{')
                        printf("}");
                    if (missing == '[')
                        printf("]");
                }
                missingbrackets = 1;
            }

            if (missingbrackets == 1)
                printf(" missing\n");

            if (missingbrackets == 0 && balanced == 1)
                printf("valid expression\n");

            //resetting conditions for next equation
            missingbrackets = 0;
            balanced = 1;
            printf("\n");
            makeStack(&stack);      //clearing stack for next equation
	    free(testString);
        }
    }
}





