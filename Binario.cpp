#include "Binario.h"

Binario::Binario(){}
Binario::~Binario(){}

Binario::Binario(string nString){
  numeroString = nString;
  calcularValor();
}

Binario::Binario(int valorDecimal){
  bool salir = false;
  string bin = "";

  while (!salir) {
    bin += (char)((valorDecimal%2)+48);
    valorDecimal -= valorDecimal%2;
    valorDecimal /= 2;

    if (valorDecimal <= 1) {
      salir = true;
    }
  }
    string binario = "1";
    for (int i = bin.length() - 1; i >= 0; i--) {
      binario += bin[i];
    }

    binario += "b";

    numeroString = binario;

    calcularValor();
}

void Binario::calcularValor(){
  double calculado = 0;

  for (int i = 0; i < numeroString.length() - 1; i++) {
    int power = (numeroString.length() - 2) - i;
    //std::cout << power << '\n';

    if (numeroString[i] == '1') {
      calculado += pow(2, power);
    }
  }

  //std::cout << calculado << '\n';
  valor = calculado;
  std::cout << "Valor decimal: " << valor << '\n';
  //string numStr = "";
  //numStr += to_string(valor);
  //numeroString = numStr;
}
