#pragma once
#include "Numero.h"
#include <string>

using namespace std;

class Decimal : public Numero{
public:
  Decimal(string);
  void calcularValor();
};
