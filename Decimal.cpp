#include "Decimal.h"

Decimal::Decimal(){}
Decimal::~Decimal(){}

Decimal::Decimal(string nString){
  numeroString = nString;
  calcularValor();
}

Decimal::Decimal(int nValor){
  valor = nValor;
  string numStr = "";
  numStr += to_string(valor);
  numeroString = numStr;
}

void Decimal::calcularValor(){
  valor = atoi(numeroString.c_str());
  std::cout << "Valor decimal: " << valor << '\n';
}
