#pragma once
#include "Numero.h"
#include <string>

using namespace std;

class Hexadecimal : public Numero{
public:
  Hexadecimal(string);
  void calcularValor();
};
