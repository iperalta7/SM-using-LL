#ifndef MATRIX_H
#define MATRIX_H

#include "Node.h"
#include <string>

class Matrix {
public:
        int row, col;
        Node *first_row[100];
        Node *first_col[100];

        Matrix(); //default constructor

        //Constructor to set size of matrix
        Matrix(int row, int col);
        
        //simply just sets the Lists of Node* pointers to all nullptrs
        void create(int row, int col);
};


#endif//MATRIX_H
