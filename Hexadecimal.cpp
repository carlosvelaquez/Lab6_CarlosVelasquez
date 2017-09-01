#include "Hexadecimal.h"

Hexadecimal::Hexadecimal(string nString){
  numeroString = nString;
  calcularValor();
}

Hexadecimal::Hexadecimal(int valorDecimal){
  bool salir = false;
  string hex = "";

  while (!salir) {
    if (valorDecimal%16 > 9) {
      switch (valorDecimal%16 > 9) {
        case (10): {
        hex += 'A';
        break;
      }
        case (11):{
        hex += 'B';
        break;}
        case (12):{
        hex += 'C';
        break;}
        case (13):{
        hex += 'D';
        break;}
        case (14):{
        hex += 'E';
        break;}
        case (15):{
        hex += 'F';
        break;}
      }
    }else{
      hex += valorDecimal%16;
    }

    valorDecimal /= 16;

    if (valorDecimal <= 0) {
      salir = true;
    }
  }

  string hexadecimal = "0x";

  for (int i = hex.length() - 1; i >= 0; i--) {
    hexadecimal += hex[i];
  }

  numeroString = hexadecimal;
  std::cout << hexadecimal << '\n';
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
