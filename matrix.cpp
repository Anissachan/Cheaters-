
#include "hashtable.h"
#include <iostream>
#include <vector>
#include <string>
#include "matrix.h"

using namespace std;

matrix::matrix(){
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

matrix::matrix(int totalFiles){
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


int matrix::getRows() {
    return rows;
}

int matrix::getCols() {
    return cols;
}

int matrix::getValue(int rows, int cols) {
    return m[rows][cols];
}

int matrix::increment(int rows, int cols){
   return m[rows][cols] = m[rows][cols] + 1;
}

void matrix::showMatrix(int rows, int cols) {
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << m[i][j] << endl;
        }
    }
}
