#include "hashtable.h"
#include <iostream>
#include <vector>
#include <string>
#include "collisionMatrix.h"

using namespace std;

collisionMatrix::collisionMatrix(){
    rows = 2;
    cols = 2;
    m = new int* [rows]();

    for(int i = 0; i < rows; i++){
        m[i] = new int [cols]();
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            m[i][j] = 0;
        }
    }
}

collisionMatrix::collisionMatrix(int totalFiles){
    rows = totalFiles;
    cols = totalFiles;
    m = new int* [rows]();

    for(int i = 0; i < rows; i++){
        m[i] = new int [cols]();
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            m[i][j] = 0;
        }
    }
}


int collisionMatrix::getRows() {
    return rows;
}

int collisionMatrix::getCols() {
    return cols;
}

int collisionMatrix::getValue(int rows, int cols) {
    return m[rows][cols];
}

int collisionMatrix::increment(int rows, int cols){
    return m[rows][cols] = m[rows][cols] + 1;
}

void collisionMatrix::showMatrix(int rows, int cols) {
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << m[i][j] << " ";
        }
        cout<<endl;
    }
}

collisionMatrix::~collisionMatrix() {
    for(int i = 0; i < rows; i++){
        delete[] m[i];
    }
    delete[] m;
}