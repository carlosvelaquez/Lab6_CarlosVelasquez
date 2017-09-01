#include "Decimal.h"

Decimal::Decimal(string nString){
  numeroString = nString;
  calcularValor();
}

Decimal::Decimal(int nValor){
  valor = nValor;
  numeroString = valor;
}

void Decimal::calcularValor(){
  return atoi(numeroString.c_str());
}
