#include "Hexadecimal.h"

Hexadecimal::Hexadecimal(){}
Hexadecimal::~Hexadecimal(){}

Hexadecimal::Hexadecimal(string nString){
  numeroString = nString;
  calcularValor();
}

Hexadecimal::Hexadecimal(int valorDecimal){
  bool salir = false;
  string hex = "";

  while (!salir) {
    if (valorDecimal%16 > 9) {
      switch (valorDecimal%16) {
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
      hex += (char)((valorDecimal%16)+48);
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
  calcularValor();
}

void Hexadecimal::calcularValor(){
  double calculado;
  int nStringLength = numeroString.length();

  for (int i = 2; i < nStringLength; i++) {
    int digito;

    if (isdigit(numeroString[i])) {
      digito = ((int)numeroString[i]) - 48;
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

      //std::cout << "Digito: " << digito << '\n';

    calculado += (digito * (pow(16, (nStringLength-1-i))));
    //std::cout << "Power: " << (nStringLength-1-i) << '\n';
    //std::cout << calculado << '\n';
  }

  //std::cout << calculado << '\n';
  valor = calculado;
  std::cout << "Valor decimal: " << valor << '\n';
  //string numStr = "";
  //numStr += to_string(valor);
}
