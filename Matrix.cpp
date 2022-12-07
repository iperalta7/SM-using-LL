#include "Matrix.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

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

    for ( int x = 0; x < row ; x ++ ){ //sets the corresponding array of node pointers to nullptrs up to value of rows given
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
            if(token != 0){
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
    (*a).next_row = nullptr;
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
    for (int i=0; i < (high - low); i++) //prints the zeros based on the difference of hi and lo
        std::cout << std::setw(5) << 0;
}

void Matrix::write(){
    for (int i=0; i < this->row; i++){
        Node *current = this->first_row[i];       //  Node pointer that points to the current corresponding pointer in the sparse matrix
        for (int j=0; j < this->col; j++){
            if (current != nullptr){
                printzeros(j, current->column);       // finds the column data of the first node, and prints the corresponding zeros in respect
                j = (*current).column;
                std::cout << std::setw(5) << (*current).data;  // will then print the actual node's value.
                current = (*current).next_row;       // changes the pointer to the next node in the row. So now it points to the next node
            }else{
                printzeros (j,this->col);                  //  if pointer in the  matrix is null, prints the zeros for that row.
                j= this->col;
            }
        }
        std::cout << std::endl;
    }
}

int Matrix::add(Matrix B, Matrix &C) {
    if (this->row != B.row and this->col != B.col) {
        return 0;
    }else {
      // loop
        for(int i = 0; i < this->row; i++){ //2d loops to so we can add_node based i, j.
            for(int j = 0; j < this->col; j++){
                Node* curr_row = this->first_row[i]; //set curr_row node pointer to the current i iteration in the list of node pointers of ccurrent matrix class
                Node* B_row = B.first_row[i]; //set B_row node ptr to curr i iteration of list in B matrix
                Node* curr_col = this->first_col[j]; //these two are unused
                Node* B_col = B.first_col[j];
                int total = 0; //init value that will up two corresponding values

                while(curr_row != nullptr ){ //loop through end of row linked list
                    if(curr_row->column == j){ //if column for node matches j then we add node's data to total and break
                        total += curr_row->data;
                        break;
                    }
                    curr_row = curr_row->next_row;
                }
                while(B_row != nullptr){ //loop through end of B_rows index of first in row list
                    if(B_row-> column == j){ //same thing if
                        total += B_row->data;
                        break;
                    }
                    B_row = B_row->next_row;
                }
                    if(total != 0){ //wont save if total us 0
                        C.add_node(i, j, total); //then we add node to C
                    }
            }
        }
        return 1;
    }
}

//our attempt to doing Matrix subtraction
// same thing with add except we set total = curr_row->data if the col matches and subtract the nodes data when it loops through B matrix.
int Matrix::subtract(Matrix B, Matrix &C){
  if (this->row != B.row and this->col != B.col) {
    return 0;
  }else {

    for(int i = 0; i < this->row; i++){
      for(int j = 0; j < this->col; j++){
        Node* curr_row = this->first_row[i];
        Node* B_row = B.first_row[i];
        Node* curr_col = this->first_col[j];
        Node* B_col = B.first_col[j];
        int total = 0;

        while(curr_row != nullptr ){
          if(curr_row->column == j){
            total = curr_row->data;
            break;
          }
          curr_row = curr_row->next_row;
        }

        while(B_row != nullptr){
          if(B_row-> column == j){
            total -= B_row->data;
            break;
          }
          B_row = B_row->next_row;
        }

        if(total != 0){
          C.add_node(i, j, total);
        }
      }
    }
    return 1;
  }
}

int Matrix::multiply(Matrix B, Matrix &C){
    if(this->col != B.row){     //returns 0 if the rule doesn't apply
        return 0;

    }else {
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < C.col; j++) {
                Node *row_node = this->first_row[i]; // initializes two pointers and hold the address to the matrix's pointer for that row and column
                Node *col_node = B.first_col[j];
                int total = 0;//  used to assign to the referenced matrix.
                for (int k = 0; k < this->row; k++) {
                    if (row_node == nullptr || col_node == nullptr)// if both nodes are null, the multiplication will end up to be 0 anyways so we just break
                        k = this->row;
                    else if ((*row_node).column < (*col_node).row) // Compares the index of the row and column pointers.
                        row_node = (*row_node).next_row;           // If one is less than the other, the lower one is advanced
                    else if ((*col_node).row < (*row_node).column)
                        col_node = (*col_node).next_col;
                    else {
                        total += (*row_node).data * (*col_node).data;// if there is a match, the datas of the curr row and col nodes are multipled and added to the total
                        col_node = (*col_node).next_col;          // Both column and row pointers are then advanced
                        row_node = (*row_node).next_row;
                    }
                }
                if (total != 0 ){
                  C.add_node(i, j, total);// The total data is then stored and added to the resultant matrix
                }
            }
        }
        return 1;
    }
}


void Matrix::transpose(Matrix &B){
    for(int i = 0; i < this->row; i++) {
      Node *row_node = this->first_row[i];
      if (row_node == nullptr) {
        continue;
      } else {
        while (row_node != nullptr) {
          B.add_node(row_node->column, row_node->row, row_node->data);
          row_node = row_node->next_row;
        }
      }
    }
}
