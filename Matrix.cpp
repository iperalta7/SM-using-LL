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

void Matrix::add_node( int i, int j, int val){
    Node *a = new Node();
    (*a).data = val;
    (*a).row = i;
    (*a).column = j;
    (*a).next_col = nullptr;
    (*a).next_col = nullptr;
    // initializes new node and stores the row, column, data datas.
    // pointers in the new node are set to NULL.

    if(this->first_col[j] == nullptr){ //if a col ptr is NULL, set the curr point to new node
        this->first_col[j] = a;
    }else{
        Node *current = this->first_col[j];  // a pointer to the node of sparse matrix col nodes (respective column)
        while ((*current).next_col != nullptr) {// Traverse column right before last node in linked list.
            current = (*current).next_col;
        }
        current->next_col = a;              // Sets that pointer to the address of the newly created node.
    }

    if (this->first_row[i] == nullptr) {// Same thing as we did with the column pointers but with the respective rows;
        this->first_row[i] = a;
    }else{
        Node *current = this->first_row[i];
        while ((*current).next_row != nullptr) {
            current = (*current).next_row;
        }
        current->next_row = a;
    }
}

void Matrix::printzeros(int low, int high){
    for (int i=0; i < (high - low); i++)
        std::cout << std::setw(5) << 0.00;
}
