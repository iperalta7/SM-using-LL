#include "Matrix.h"
#include <iomanip>
#include <iostream>

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

void Matrix::read_file(std::string fname) {
    int i = 0, j = 0;
    std::ifstream file(fname);
    std::string str;
    while (std::getline(file, str)) {
        std::istringstream ss(str);
        int token;
        while (ss >> token) {
            if(token != 0 ){
                this->add_node(i, j, token); //adds to matrix with corresponding row and col vals
            }
            j++;
        }
        j = 0;
        i++;
    }
}

void Matrix::printzeros(int low, int high){
    for (int i=0; i < (high - low); i++)
        std::cout << std::setw(5) << 0.00;
}
