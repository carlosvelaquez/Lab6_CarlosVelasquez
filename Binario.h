#pragma once
#include "Numero.h"
#include <string>

using namespace std;

class Binario : public Numero{
public:
  Binario();
  ~Binario();
  Binario(string);
  Binario(int);
  void calcularValor();
};
