// life.h
// -- EE 312 Project 2

/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Pragna Subrahmanya, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name:Pragna Subrahmanya
 * email address:pragnals@utexas.edu
 * UTEID:ps28338
 * Section 5 digit ID:
 *
 *///
// Created by priebe on 9/5/2018.
//

#ifndef UNTITLED1_LIFE_H
#define UNTITLED1_LIFE_H

#endif //UNTITLED1_LIFE_H

void populateWorld(char fname[], char *grid[], int *numRows, int *numCols);

void showWorld(char *grid[], int numRows, int numCols);

void iterateGeneration(char *grid[], int numRows, int numCols);

int checkCell(char* grid[], int numRows, int numCols, int curRow, int curCol);

void killCell(char* grid[], int curRow, int curCol);

void newCell(char* grid[], int curRow, int curCol);
