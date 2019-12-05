//
// Created by aniss on 12/5/2019.
//

#ifndef CHEATER_MATRIX_H
#define CHEATER_MATRIX_H

#include <iostream>
#include <stdio.h>
#include "hashtable.h"

using namespace std;

class matrix{

private:
    int **m;
    int rows;
    int cols;

public:
    matrix();
    matrix(int totalFiles);
    int getRows();
    int getCols();
    int getValue(int rows, int cols);
    int increment(int rows, int cols);
    void showMatrix(int rows, int cols);
    ~matrix();
};




#endif //CHEATER_MATRIX_H
