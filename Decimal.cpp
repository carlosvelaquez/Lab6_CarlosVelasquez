#include "Decimal.h"

Decimal::Decimal(string nString){
  numeroString = nString;
  calcularValor();
}

void Decimal::calcularValor(){
  return atoi(numeroString.c_str());
}
