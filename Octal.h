#pragma once
#include "Numero.h"
#include <string>

using namespace std;

class Octal : public Numero{
public:
  Octal();
  ~Octal();
  Octal(string);
  Octal(int);
  void calcularValor();
};
