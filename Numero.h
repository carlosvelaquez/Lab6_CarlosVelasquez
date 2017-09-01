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
  Numero();
  string getNumeroString();
  double getValor();
  virtual void calcularValor();

  int operator+(Numero& num){
    Numero* resultados = new Numero[4];
    return this->getValor() + num.getValor();
  }

  int operator-(Numero& num){
    Numero* resultados = new Numero[4];
    return this->getValor() - num.getValor();
  }

  int operator*(Numero& num){
    Numero* resultados = new Numero[4];
    return this->getValor() * num.getValor();
  }
  //Numero* operator-(&Numero);
  //Numero* operator*(&Numero);
};
