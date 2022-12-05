int main(int argc, char *argv[]) {
    std::string fname1(argv[1]);
    int row_1 = std::stoi(argv[2]), col_1 = std::stoi(argv[3]);
    std::string fname2(argv[4]);
    int row_2 = std::stoi(argv[5]), col_2 = std::stoi(argv[6]);

    //creates and reads from file and prints out Matrix 1
    std::cout << "Matrix 1: " << std::endl;
   Matrix A(row_1, col_1);
   A.create(row_1, col_1);


   //creates and reads from file and prints out Matrix 2
   std::cout << "Matrix 2: " << std::endl;
   Matrix B(row_2, col_2);
   B.create(row_2, col_2);

   //creates an object of Matrix C to be passed by reference for certain choices
   Matrix C(row_1, col_2);
   C.create(row_1, col_2);

  
