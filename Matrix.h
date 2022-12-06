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
        
        /* Parameters requires two integers.
           used in member function: write().
           Prints out a number of zeros based on the difference between the two parameters. */
        void printzeros(int lo, int hi);
        
         /* Function to be called when the file stream object in read method which inserts a value that is not equal to zero.
        Parameters require  the row (i), column (j), and value (val) of the non-zero matrix Node.
        creates a node and stores the corresponding column, row, and value. It will set the two pointers in the node to nullptr. Then
         traverses through matrix and finds the node pointer in the respective row and column and set the two internal node pointers to the newly created
         node*/
        void add_node(int i, int j, int val);
        
        /*No parameters required
         The write() member function essentially just prints out the Sparse Matrix representation with the 0s
         It has to loop through the num of rows and num of cols to be able to print out the 0, since 0s are not saved in the linked list for storage
         std::setw is used to help for spacing in the console.*/
        void write();
        
        /*Add Member Function adds the values of Matrix to the current Matrix object
         Parameters: an instance of a Matrix object called B passed by value, and a reference to an empty Matrix C
         they are the same and adds the nodes data to the corresponding positional node of the current Matrix*/
        int add(Matrix B, Matrix &C);
        
        /*Add Member Function adds the values of Matrix to the current Matrix object
         Parameters: an instance of a Matrix object called B
         Loops through the Lists of Linked Lists by rows and checks the curr nodes corresponding col value to check if
         they are the same and subtracts the nodes data to the corresponding positional node of the current Matrix*/
        int subtract(Matrix B, Matrix &C);
        
        /*Multiplies two Matrices by having a new empty matrix created and appending the new nodes into Matrix C
         Parameters: An existing Matrix object called B, Another Matrix object C passed by reference so we can add nodes into it after
         the algorithm submits a new node*/
        int multiply(Matrix B, Matrix &C);
        
        /* Parameters: A Matrix object named B passed by reference.
          Loops through Lists of Linked Lists up until defined rows for class
          When a node is given it will create a new node using B's add_node method but use the curr
          node's row, col public values and its actual value and place the row in the col param, col in the row param and value in the val param
         */
        void transpose(Matrix &B );
};


#endif//MATRIX_H
