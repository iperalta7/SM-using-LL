#include "Matrix.h"

//Default Constructor
Matrix::Matrix() {
    this->row = 0;
    this->col = 0;
}


//Parametized constructor
Matrix::Matrix(int row, int col){
    this->row = row;
    this->col = col;
}
