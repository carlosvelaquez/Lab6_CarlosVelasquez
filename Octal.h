#pragma once
#include "Numero.h"
#include <string>

using namespace std;

class Octal : public Numero{
public:
  Octal(string);
  Octal(int);
  void calcularValor();
};
