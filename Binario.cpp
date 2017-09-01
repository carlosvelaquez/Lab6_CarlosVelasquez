#include "Binario.h"

Binario::Binario(string nString){
  numeroString = nString;
  calcularValor();
}

void Binario::calcularValor(){
  double calculado = 0;

  for (int i = 0; i < numeroString.length() - 1; i++) {
    power = (numeroString.length() - 2) - i;
    std::cout << power << '\n';

    if (numeroString[i] == '1') {
      calculado += pow(2, power);
    }
  }

  std::cout << calculado << '\n';
  valor = calculado;
}
