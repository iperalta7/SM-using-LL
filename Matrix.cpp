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


void Matrix::create(int row, int col){

    for ( int x = 0; x < row ; x ++ ){
        this->first_row[x] = nullptr;
        }

    for(int j = 0; j < col; j++){
        this->first_col[j] = nullptr;
    }

}
