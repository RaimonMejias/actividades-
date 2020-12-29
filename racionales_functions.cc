#include <fstream>
#include <iostream>
#include <numeric>
#include "racionales.h"

std::ostream& operator<<(std::ostream &out, const Racional &racional){

  if(racional.denominator() == 0){
    std::cerr << "Un numero racional no puede tener como denominador 0";
    exit(1);
  }
   if(racional.denominator() < 0){
    out << racional.numerator()*-1 << "/" << racional.denominator()*-1;
    return out;
  }
  out << racional.numerator() << "/" << racional.denominator();
  return out; 
}

Racional operator+(Racional &number1, Racional &number2){
   if(number1.denominator() == 0 || number2.denominator() == 0){
    std::cerr << "Un numero racional no puede tener como denominador 0";
    exit(1);
  }
  if (number1.denominator() == number2.denominator()){
    return Racional(number1.numerator()+number2.numerator(),number1.denominator());
  }
  int lcm =std::lcm(number1.denominator(),number2.denominator());

  int numerator1 = (lcm*number1.numerator())/number1.denominator();

  int numerator2 = (lcm*number2.numerator())/number2.denominator();

  return Racional(numerator1+numerator2,lcm);
}

Racional operator-(Racional &number1, Racional &number2){
   if(number1.denominator() == 0 || number2.denominator() == 0){
    std::cerr << "Un numero racional no puede tener como denominador 0";
    exit(1);
  }
  if (number1.denominator() == number2.denominator()){
    return Racional(number1.numerator()+number2.numerator(),number1.denominator());
  }
  int lcm =std::lcm(number1.denominator(),number2.denominator());

  int numerator1 = (lcm*number1.numerator())/number1.denominator();

  int numerator2 = (lcm*number2.numerator())/number2.denominator();

  return Racional(numerator1-numerator2,lcm);
}

Racional operator*(Racional &number1, Racional &number2){
  if(number1.denominator() == 0 || number2.denominator() == 0){
    std::cerr << "Un numero racional no puede tener como denominador 0";
    exit(1);
  }
  return Racional(number1.numerator()*number2.numerator(),number1.denominator()*number2.denominator());
}

Racional operator/(Racional &number1, Racional &number2){
  if(number1.denominator() == 0 || number2.denominator() == 0){
    std::cerr << "Un numero racional no puede tener como denominador 0";
    exit(1);
  }
  return Racional(number1.numerator()*number2.denominator(),number1.denominator()*number2.numerator());
}

bool operator<(Racional &number1, Racional &number2){
  double real1 = number1.numerator()/number1.denominator();
  double real2 = number2.numerator()/number2.denominator();
  if(real1 < real2){
    return true;
  }
  return false;
}

bool operator>(Racional &number1, Racional &number2){
  
  double real1 = number1.numerator()/number1.denominator();
  double real2 = number2.numerator()/number2.denominator();
  if(real1 > real2){
    return true;
  }
  return false;
}

bool operator==(Racional &number1, Racional &number2){
  double real1 = number1.numerator()/number1.denominator();
  double real2 = number2.numerator()/number2.denominator();
  if(real1 == real2){
    return true;
  }
  return false;
}

void Output(Racional &number1, Racional &number2, std::string file){
  std::ofstream outputfile{file, std::ios_base::app};
  outputfile << number1 << " + " << number2 << " = " << number1 + number2 << std::endl;
  outputfile << number1 << " - " << number2 << " = " << number1 - number2 << std::endl;
  outputfile << number1 << " * " << number2 << " = " << number1 * number2 << std::endl;
  outputfile << number1 << " / " << number2 << " = " << number1 / number2 << std::endl;
  outputfile << number1 << " < " << number2 << " = " << (number1 < number2) << std::endl;
  outputfile << number1 << " > " << number2 << " = " << (number1 > number2) << std::endl;
  outputfile << number1 << " == " << number2 << " = " << (number1 == number2) << std::endl;
}

void FirstComprobator(int parameters){

  if(parameters < 3){
    std::cerr << "Falta/n archivos" << std::endl;
    std::cerr << "Metodo de uso: ./racionales <inputfile.txt> <outputfile.txt>" << std::endl;
    std::cerr << "Para mas informacion escriba <--help 0> en la linea de comandos" << std::endl;
    std::cerr << std::endl; 
    exit(1);
  }
}

void SecondComprobator(std::string file1, std::string file2){
  if(file1 == "--help"){
    Helpinformation();
  }
   std::ifstream inputfile{file1};
   std::ofstream outputfile{file2};

  if (!inputfile){
    std::cerr << "No existe o no se pudo abrir < inputfile.txt >" << std::endl;
    std::cerr << "Para mas informacion escriba --help en la linea de comandos" << std::endl;
    exit(1);
  }
  if (!outputfile){
    std::cerr << "No existe o no se pudo abrir < outputfile.txt >" << std::endl;
    std::cerr << "Para mas informacion escriba --help en la linea de comandos" << std::endl;
    exit(1);
  }
}

void Helpinformation(){

  std::cout << "Este programa utiliza dos ficheros uno de entrada y otro de salida, los cuales se llamaran de manera predeterminada inputfile.txt y outputfile.txt" << std::endl;
  std::cout << std::endl;
  std::cout << "Metodo de uso: ./racionales <inputfile.txt> <outputfile.txt>" << std::endl;
  std::cout << std::endl;
  std::cout << "inputfile.txt: en este fichero se pondra los numeros racionales, separados por un espacio, con lo que se han de hacer las operaciones" << std::endl;
  std::cout << std::endl;
  std::cout << "outputfile.txt: en este fichero saldran los resultados de las operaciones hechas con los numeros de inputfile.txt" << std::endl;
  std::cout << std::endl;
  std::cout << "Los numeros racionales han de escribirse de la siguiente manera: 'a/b'";
  exit(1); 
}
