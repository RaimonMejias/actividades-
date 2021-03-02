// AUTOR: Raimon Mejías
// FECHA: 02/03/2021
// EMAIL: alu0101390161@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g rational_t.cpp main_rational_t.cpp -o main_rational_t

// pauta de estilo [92]: Use either the // or /* */ syntax, as long as you are consistent.
// You can use either the // or the /* */ syntax; however, // is much more common.
// Be consistent with how you comment and what style you use where.

#include <iostream>
#include <cmath>

// pauta de estilo [41]: Include headers in the following order:
//Related header, C system headers, C++ standard library headers, other libraries' headers, your project's headers.
//Separate each non-empty group with one blank line.

#include "rational_t.hpp"

using namespace std;

int main()
{
  rational_t a(1, 2), b(3), c;

  cout << "a.value()= " << a.value() << endl;
  cout << "b.value()= " << b.value() << endl;
  cout << "c.value()= " << c.value() << endl;

  cout << "a: ";
  a.write();
  cout << "b: ";
  b.write();

  c.read();
  cout << "c: ";
  c.write();

  // FASE II
  // rational_t x(1, 3), y(2, 3);
  // x.write();
  // y.write();
  // cout << "x == y? " << (x.is_equal(y) ? "true" : "false") << endl;
  // cout << "x < y? " << (x.is_greater(y) ? "true" : "false") << endl;
  // cout << "x > y? " << (x.is_less(y) ? "true" : "false") << endl;

  // FASE III
  // cout << "a + b: ";
  // a.add(b).write();
  
  // cout << "b - a: ";
  // b.substract(a).write();

  // cout << "a * b: ";
  // a.multiply(b).write();
  
  // cout << "a / b: ";
  // a.divide(b).write();
  
  return 0;
}
