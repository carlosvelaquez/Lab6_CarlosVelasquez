#include "Octal.h"

Octal::Octal(string nString){
  numeroString = nString;
  calcularValor();
}

Octal::Octal(int valorDecimal){
  bool salir = false;
  string oct = "";

  while (!salir) {
    oct += valorDecimal%8;
    valorDecimal /= 8;

    if (valorDecimal <= 0) {
      salir = true;
    }
  }

  string octal = "0c";

  for (int i = oct.length() - 1; i >= 0; i--) {
    octal += oct[i];
  }

  numeroString = octal;
  std::cout << octal << '\n';
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
