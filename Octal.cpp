#include "Octal.h"

Octal::Octal(){}
Octal::~Octal(){}

Octal::Octal(string nString){
  numeroString = nString;
  calcularValor();
}

Octal::Octal(int valorDecimal){
  bool salir = false;
  string oct = "";

  while (!salir) {
    oct += (char)((valorDecimal%8) + 48);
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
    calculado += ((int)numeroString[i]) - 48;
    if (i < numeroString.length() - 1) {
      calculado *= 8;
    }
  }

  valor = calculado;
  //string numStr = "";
  //numStr += to_string(valor);
  //numeroString = numStr;
}
