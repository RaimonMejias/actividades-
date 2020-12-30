#include <iostream>
#include <sstream>
#include "fechas_functions.h"

int main(int argc, char* argv[]){

  FirstComprobator(argc);
  SecondComprobator(argv[1]);

  std::string outputfile{argv[3]};
  int upcoming_dates = std::stoi(argv[2]);
  int day,month,year;
  std::string unused;
  std::stringstream cadena{argv[1]};
  cadena >> day >>  month  >> year;

  Fechas fecha{day,month,year};
  
  std::cout << upcoming_dates;
  PlusDates(fecha, upcoming_dates, outputfile);


}
