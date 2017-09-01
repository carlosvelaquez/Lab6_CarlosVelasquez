#include "Hexadecimal.h"

Hexadecimal::Hexadecimal(string nString){
  numeroString = nString;
  calcularValor();
}

void Hexadecimal::calcularValor(){
  double calculado;

  for (int i = 2; i < numeroString.length(); i++) {
    int digito;

    if (isdigit(numeroString[i])) {
      digito = (int)numeroString[i];
    }else{
      switch (numeroString[i]) {
        case 'A':
        digito = 10;
        break;
        case 'B':
        digito = 11;
        break;
        case 'C':
        digito = 12;
        break;
        case 'D':
        digito = 13;
        break;
        case 'E':
        digito = 14;
        break;
        case 'F':
        digito = 15;
        break;
      }
    }

    calculado += (digito * (pow(16, (numeroString.length()-3-i))));
  }

  std::cout << calculado << '\n';
  valor = calculado;
}
