#include "stack_arr.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void makeStack(Stack312 *s){
    s->top = -1;
}

bool isEmpty(Stack312 s){
    return s.top == -1;
}

bool isFull(Stack312 s){
    return s.top == MAX_ELEMENTS-1;
}

void push(StackEntry e,Stack312 *s){
    if(isFull(*s))
        return;
    (s->top)++;
    s->elements[s->top] = e;
}

StackEntry pop(Stack312 *s){
    if(isEmpty(*s))
        return -1;
    return s->elements[s->top--];
}

bool isPair(char bracket1, char bracket2){
    if(bracket1=='(' && bracket2==')')
        return true;
    else if(bracket1=='{' && bracket2=='}')
        return true;
    else if(bracket1=='[' && bracket2==']')
            return true;
    return false;
}

