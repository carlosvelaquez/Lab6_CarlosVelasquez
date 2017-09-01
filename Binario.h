#pragma once
#include "Numero.h"
#include <string>

using namespace std;

class Binario : public Numero{
public:
  Binario(string);
  Binario(double);
  void calcularValor();

  Numero* operator+();
  Numero* operator-();
  Numero* operator*();
};
