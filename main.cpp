#include <vector>
#include <iostream>
#include "Numero.h"
#include "Decimal.h"
#include "Binario.h"
#include "Hexadecimal.h"
#include "Octal.h"

using namespace std;

int menu();
Numero anadirNumero();
void realizarOperacion(vector<Numero>);
//void limpiarCache(vector<Numero>);
int identificarTipo(string);
void mostrarResultados(int);

int main(){
  vector<Numero> numeros;
  bool salir = false;
  int opcion;

  while (!salir) {
    opcion = menu();

    switch (opcion) {
      case 1:{
        numeros.push_back(anadirNumero());
        cout << endl << "Número añadido exitosamente" << endl;
      }break;
      case 2:{
        if (numeros.size() > 0) {
          realizarOperacion(numeros);
        }else{
          cout << "Aún no tiene números en el caché" << endl;
        }
      }break;
      case 3:{
        numeros.clear();
        cout << "Caché limpiado exitosamente" << endl;
      }break;
      case 4:{
        salir = true;
        cout << "Saliendo..." << endl;
        cout << "-------------------------------" << endl;
      }break;
      default:{
        cout << "Opción inválida, por favor intente de nuevo." << endl;
      }break;
    }
  }

  return 0;
}

int menu(){
  int opcion;
  cout << "-------------------------------" << endl
  << "Calculadora (*jazz hands*)" << endl << endl
  << "1. Añadir Número" << endl
  << "2. Realizar Operación" << endl
  << "3. Limpiar Caché de Números" << endl
  << "4. Salir del Programa" << endl
  << endl << "Ingrese el número de la opción que desea - ";
  cin >> opcion;
  cout << "-------------------------------" << endl;
  return opcion;
}

Numero anadirNumero(){
  string numeroNuevo;
  bool continuar = false;
  cout << "Añadir Número" << endl;

  while (!continuar) {
    continuar = true;
    cout << "Ingrese el número a añadir: ";
    cin >> numeroNuevo;

    switch (identificarTipo(numeroNuevo)) {
      case 1:{
        Binario num(numeroNuevo);
        return num;
      }break;
      case 2:{
        Hexadecimal num(numeroNuevo);
        return num;
      }break;
      case 3:{
        Octal num(numeroNuevo);
        return num;
      }break;
      case 4:{
        Decimal num(numeroNuevo);
        return num;
      }break;
      default:{
        cout << "Notación no válida, por favor intente de nuevo." << endl;
      }break;
    }

    return Decimal("0");
  }
}

int identificarTipo(string numeroString){
    if (numeroString[numeroString.length()-1] == 'b') {
      for (int i = 0; i < numeroString.length()-1; i++) {
        if (isdigit(numeroString[i])) {}
        else{
          return 5;
        }
      }
      return 1;
    }else if(numeroString[0] == '0' && numeroString[1] == 'x'){
      for (int i = 2; i < numeroString.length(); i++) {
        if (isdigit(numeroString[i]) == false && numeroString[i] != 'A' && numeroString[i] != 'B' && numeroString[i] != 'C' && numeroString[i] != 'D' && numeroString[i] != 'E' && numeroString[i] != 'F') {
          return 5;
        }
      }
      return 2;
    }else if(numeroString[0] == '0' && numeroString[1] == 'c'){
      //std::cout << numeroString << '\n';
      for (int i = 2; i < numeroString.length(); i++) {
        if (isdigit(numeroString[i])) {
          if (((int)(numeroString[i]) - 48) > 7) {
            return 5;
          }
        }else{
          return 5;
        }
      }

      return 3;
    }else{
      for (int i = 0; i < numeroString.length(); i++) {
        if (isdigit(numeroString[i]) == false) {
          return 5;
        }
      }
    }

    return 4;
}

void realizarOperacion(vector<Numero> numeros){
  int op1, op2;
  Numero n1, n2;
  bool continuar = true;

  cout << "Realizar Operación" << endl << endl;

  cout << "Seleccione el numero al que operar" << endl;

  for (int i = 0; i < numeros.size(); i++) {
    cout << i << ". " << numeros.at(i).getNumeroString() << endl;
  }

  cout << "Ingrese su selección -  ";
  cin >> op1;

  if (op1 > numeros.size() - 1) {
    cout << "[ERROR] No existe un número con ese índice" << endl;
    continuar = false;
  }
  if (continuar) {
    n1 = (numeros.at(op1));

    cout << endl << "Seleccione el numero con el cual operar" << endl;
    for (int i = 0; i < numeros.size(); i++) {
      cout << i << ". " << numeros.at(i).getNumeroString() << endl;
    }
    cout << "Ingrese su selección -  ";
    cin >> op2;
    if (op2 > numeros.size() - 1) {
      cout << "[ERROR] No existe un número con ese índice" << endl;
      continuar = false;
    }

    if (continuar) {
      n2 = (numeros.at(op2));

      int oper;
      cout << "-------------------------------" << endl;

      cout << "Seleccione el tipo de operación" << endl
      << "1. Suma" << endl
      << "2. Resta" << endl
      << "3. Multiplicar" << endl << endl
      << "Ingrese el número de la opción que desea - ";

      cin >> oper;

      switch (oper) {
        case 1:{
          //mostrarResultados((*n1)+(*n2));
          mostrarResultados(n1+n2);
        }break;
        case 2:{
          //mostrarResultados((*n1)-(*n2));
          mostrarResultados(n1-n2);
        }break;
        case 3:{
          //mostrarResultados((*n1)*(*n2));
          mostrarResultados(n1*n2);
        }break;
      }
    }

  }


}

void mostrarResultados(int valor){
  cout << "-------------------------------" << endl;
  Decimal dec(valor);
  Binario bin(valor);
  Octal oct(valor);
  Hexadecimal hex(valor);
  cout << "Resultados" << endl << endl;

  cout << "Decimal: " << dec.getNumeroString() << endl;
  cout << "Binario: " << bin.getNumeroString() << endl;
  cout << "Octal: " << oct.getNumeroString() << endl;
  cout << "Hexadecimal: " << hex.getNumeroString() << endl;
}

/*Numero* resultados = new Numero[4];
int valor = this->getValor() + num.getValor();

Decimal dec(valor);
Binario bin(valor);
Octal oct(valor);
Hexadecimal hex(valor);

resultados[0] = dec;
resultados[1] = bin;
resultados[2] = oct;
resultados[3] = hex;

return resultados;
}*/
