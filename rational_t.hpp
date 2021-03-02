// AUTOR: Raimon Mejías
// FECHA: 2/3/2021
// EMAIL: alu0101390161@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: Use either the // or /* */ syntax, as long as you are consistent.
// You can use either the // or the /* */ syntax; however, // is much more common.
// Be consistent with how you comment and what style you use where.

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]:: All header files should have #define guards to prevent multiple inclusion.
# define EPSILON 1e-6

using namespace std;

class rational_t
{
  // pautas de estilos [44]: A class definition should usually start with a public: section, followed by protected:, then private:. Omit sections that would be empty.
  // y [73]: primero "public" y después "private"
public:
    //constructor
  rational_t(const int = 0, const int = 1);
  //destructor
  ~rational_t() {}
  
  // pauta de estilo [71]: Use only spaces, and indent 2 spaces at a time.
  // getters
  int get_num() const;
  int get_den() const;
  
  // setters
  void set_num(const int);
  void set_den(const int);

  double value(void) const;

  // FASE II
  // bool is_equal(const rational_t&, const double precision = EPSILON) const;
  // bool is_greater(const rational_t&, const double precision = EPSILON) const;
  // bool is_less(const rational_t&, const double precision = EPSILON) const;
  
  // FASE III
  // rational_t add(const rational_t&);
  // rational_t substract(const rational_t&);
  // rational_t multiply(const rational_t&);
  // rational_t divide(const rational_t&);
  
  void write(ostream& = cout) const;
  void read(istream& = cin);
  
private:
  // pauta de estilo [11]: Data members of classes, both static and non-static, are named like ordinary nonmember variables, but with a trailing underscore.
  int num_, den_;
};
