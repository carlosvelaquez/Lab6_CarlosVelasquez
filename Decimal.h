#pragma once
#include "Numero.h"
#include <string>

using namespace std;

class Decimal : public Numero{
public:
  Decimal();
  ~Decimal();
  Decimal(string);
  Decimal(int);
  void calcularValor();
};
