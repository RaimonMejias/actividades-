#include <fstream>
#include <iostream>
#include <string>
#include "racionales.h"

int main(int argc , char* argv[]) {
  int numerator1, denominator1,numerator2,denominator2;
  char unused;

  FirstComprobator(argc);
  SecondComprobator(argv[1],argv[2]);

  std::ifstream input{argv[1], std::ios_base::in};
  
  while(input >> numerator1 >> unused >> denominator1 >> numerator2 >> unused >> denominator2){
    Racional number1{numerator1,denominator1};
    Racional number2{numerator2,denominator2};
    Output(number1,number2, argv[2]);
  }
  
  std::cout << "Las operaciones se han calculado correctamente" << std::endl;
  std::cout << "Abra " << argv[2] << " para ver los resultados";
  std::cout << std::endl;


}
