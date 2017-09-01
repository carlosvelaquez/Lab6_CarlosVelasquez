#pragma once
#include <string>

class Numero{
private:
  string numeroString;
  string tipo;
  double valor;
public:
  string getNumeroString();
  double getValor();
  virtual void calcularValor();
};
