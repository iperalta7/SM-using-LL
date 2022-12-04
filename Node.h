
#ifndef NODE_H
#define NODE_H

//class for Nodes
// points to the node in the row
// points to the node in the next col
// holds the position using a row, col value
// also holds the

class Node {
public:
    int data;
    int row;
    int column;
    Node *next_row;
    Node *next_col;
    Node();//default constructor
    friend class Matrix;
};


#endif//NODE_H

