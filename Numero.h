#pragma once
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class Numero{
protected:
  string numeroString;
  string tipo;
  double valor;
public:
  string getNumeroString();
  double getValor();
  virtual void calcularValor();

  virtual Numero* operator+();
  virtual Numero* operator-();
  virtual Numero* operator*();
};
