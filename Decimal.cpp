#include "Decimal.h"

Decimal::Decimal(){}
Decimal::~Decimal(){}

Decimal::Decimal(string nString){
  numeroString = nString;
  calcularValor();
}

Decimal::Decimal(int nValor){
  valor = nValor;
  numeroString = valor;
}

void Decimal::calcularValor(){
  valor = atoi(numeroString.c_str());
}
