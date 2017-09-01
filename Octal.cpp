#include "Octal.h"

Octal::Octal(string nString){
  numeroString = nString;
  calcularValor();
}

void Octal::calcularValor(){
  double calculado = 0;

  for (int i = 2; i < numeroString.length(); i++) {
    calculado += ((int)numeroString[i]);
    if (i < numeroString.length() - 1) {
      calculado *= 8;
    }
  }

  std::cout << calculado << '\n';
  valor = calculado;
}
