int main(int argc, char *argv[]) {
    std::string fname1(argv[1]);
    int row_1 = std::stoi(argv[2]), col_1 = std::stoi(argv[3]);
    std::string fname2(argv[4]);
    int row_2 = std::stoi(argv[5]), col_2 = std::stoi(argv[6]);

    //creates and reads from file and prints out Matrix 1
    std::cout << "Matrix 1: " << std::endl;
   Matrix A(row_1, col_1);
   A.create(row_1, col_1);
    A.read_file(fname1);
    A.write();


   //creates and reads from file and prints out Matrix 2
   std::cout << "Matrix 2: " << std::endl;
   Matrix B(row_2, col_2);
   B.create(row_2, col_2);
   B.read_file(fname2);
    B.write();

   //creates an object of Matrix C to be passed by reference for certain choices
   Matrix C(row_1, col_2);
   C.create(row_1, col_2);

  
    //if statement to do what user asks
   if(choice == "M"){ //for multiply
       if (){
           std::cout << "\nResulting Matrix from Matrix Multiplication: \n" <<std::endl;
           C.write();
       }else{
           std::cout << "Matrix Multiplication will not work with these two matrices" << std::endl;
       }

   }else if (){ //for addition
       if(A.add(B, C)){
           std::cout << "\nResulting Matrix from Matrix Addition: \n";
           C.write();
       }else{
           std::cout << "Matrix Addition will not work with these two matrices" << std::endl;

       }
