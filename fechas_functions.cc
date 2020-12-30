#include <iostream>
#include <fstream>
#include "fechas_functions.h"

std::ostream& operator<<(std::ostream &out, const Fechas &fecha){
  if(fecha.day_ > 31 ||fecha.day_ <= 0){
    std::cout << "coloque un dia valido" << std::endl;
    exit(1);
  }
  if(fecha.month_ > 12 ||fecha.month_  <= 0){
    std::cout << "Coloque un mes valido" << std::endl;
    exit(1);
  }
  if(fecha.year_ < 0){
    std::cout << "Coloque un año valido" << std::endl;
  }
  out << fecha.day_ << "/" << fecha.month_ << "/" << fecha.year_;
  return  out;
}

Fechas operator+(const Fechas &fecha, int number){
  Fechas new_date = Fechas(fecha.day()+number, fecha.month(),fecha.year());
  if(new_date.day() > 31){
    if(new_date.month() != 12){
      return Fechas(new_date.day()-31, new_date.month()+1,new_date.year());
    }
    if(new_date.month() == 12){
      return Fechas(new_date.day()-31, new_date.month()-11,new_date.year()+1);
    }
  }  
  return new_date;
}

std::string LeapYear(const Fechas &fecha){

  std::string leap_year{};

  if(fecha.year()%4 == 0){
    if(fecha.year()%100 == 0 && fecha.year()%400 == 0 ){
      leap_year = " es bisiesto"; 
      return leap_year;
    }
    if(fecha.year()%100 != 0){
      leap_year = " es bisiesto";
      return leap_year;
    }
  }
  return leap_year = " no es bisiesto";
}

void PlusDates(const Fechas &fecha, int upcoming_dates, std::string file){
  std::ofstream outputfile{file, std::ios_base::app};
  for(int i = 1; i < upcoming_dates+1; ++i){
    Fechas new_fecha;
    new_fecha = fecha+i;
     outputfile << new_fecha << " " << LeapYear(new_fecha) << std::endl; 
  }
}

void FirstComprobator(int parameters){

  if(parameters > 4 ){
    std::cerr << "Error: sobran parametros" << std::endl;
    std::cerr << "Metodo de uso: ./fechas <dd/mm/aa> <N-numero> <outputfile.txt>" << std::endl;
    std::cerr << "Para mas informacion escriba <--help> como primer parametro en la linea de comandos" << std::endl;
    std::cerr << std::endl; 
    exit(1);
  }
  if(parameters < 4){
    std::cerr << "Error: Faltan parametros" << std::endl;
    std::cerr << "Metodo de uso: ./fechas <dd/mm/aa> <N-numero> <outputfile.txt>" << std::endl;
    std::cerr << "Para mas informacion escriba <--help> como primer parametro en la linea de comandos" << std::endl;
    std::cerr << std::endl; 
    exit(1);
  }
  
}

void SecondComprobator(std::string help){
  if(help == "--help"){

    std::cout << "Este programa dado una fecha, un numero y un fichero de salida, mostrara los n-siguientes dias de la fecha dada y dira si el año es bisiesto o no" << std::endl;
    std::cout << std::endl;
    std::cout << "Metodo de uso: ./fechas <dd/mm/aa> ;;<N-numero> <outputfile.txt>" << std::endl;
    std::cout << std::endl;
    std::cout << "dd/mm/aa: se debera poner la fecha de la forma 'Dia Mes Año' con las comillas, de lo contrario el programa no funcionara" << std::endl;
    std::cout << std::endl;
    std::cout << "N-numero: Este numero sera el indicativo de cuantas fechas avanzara el programa" << std::endl;
    std::cout << std::endl;
    std::cout << "outputfile.txt: en este fichero saldran las n siguientes fechas y si el año es bisiesto o no" << std::endl;
    exit(1); 
  }
}
