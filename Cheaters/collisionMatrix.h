//
// Created by aniss on 12/5/2019.
//

#ifndef CHEATER_COLLISIONMATRIX_H
#define CHEATER_COLLISIONMATRIX_H

#include <iostream>
#include <stdio.h>
#include "hashtable.h"

using namespace std;

class collisionMatrix{

private:
    int **m;
    int rows;
    int cols;

public:
    collisionMatrix();
    collisionMatrix(int totalFiles);
    int getRows();
    int getCols();
    int getValue(int rows, int cols);
    int increment(int rows, int cols);
    void showMatrix(int rows, int cols);
    ~collisionMatrix();
};




#endif //CHEATER_COLLISIONMATRIX_H