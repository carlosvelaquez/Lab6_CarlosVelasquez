#pragma once
#include "Numero.h"
#include <string>

using namespace std;

class Binario : public Numero{
public:
  Binario(string);
  void calcularValor();
};
