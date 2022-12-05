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
        
        /*Parameter: name of file to use (string)
         reads from the files and all values that are not zero are
         saved to the corresponding Matrix class. Lists of Linked Lists;
        */
        void read_file(std::string fname);

};


#endif//MATRIX_H
