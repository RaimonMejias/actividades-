#ifndef RACIONALES_H
#define RACIONALES_H

//Declaracion de la clase racional
class Racional{
public:
  Racional() = default;
  Racional(int numerator, int denominator):
         numerator_(numerator), denominator_(denominator){}
  int numerator() const { return numerator_; }
  int denominator() const { return denominator_; }
private:
  int numerator_;
  int denominator_;
};

//Funciones generales

void SecondComprobator(std::string file1, std::string file2);
void FirstComprobator(int parameters);
void Helpinformation();
void Output(Racional &number1, Racional &number2, std::string file);
//Funciones de la clase Racional

std::ostream& operator<<(std::ostream &out, const Racional &racional);
Racional operator+(Racional &number1, Racional &number2);
Racional operator-(Racional &number1, Racional &number2);
Racional operator*(Racional &number1, Racional &number2);
Racional operator/(Racional &number1, Racional &number2);
bool operator<(Racional &number1, Racional &number2);
bool operator>(Racional &number1, Racional &number2);
bool operator==(Racional &number1, Racional &number2);

#endif
