#include "Numero.h"

string Numero::getNumeroString(){
  return numeroString;
}

double Numero::getValor(){
  return valor;
}

/*Numero* Numero::operator+(&Numero num){
  Numero* resultados = new Numero[4];
  int valor = this->getValor() + num->getValor();

  Numero[0] = new Decimal(valor);
  Numero[1] = new Binario(valor);
  Numero[2] = new Octal(valor);
  Numero[3] = new Hexadecimal(valor);

  return resultados;
}
*/
