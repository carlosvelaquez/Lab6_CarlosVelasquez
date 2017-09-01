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
void limpiarCache(vector<Numero>);
int identificarTipo(string);

int main(){
  vector<Numero> numeros;
  bool salir = false;
  int opcion;

  while (!salir) {
    opcion = menu();

    switch (opcion) {
      case 1:{
        numeros.push_back(anadirNumero());
      }break;
      case 2:{
        realizarOperacion(numeros);
      }break;
      case 3:{
        limpiarCache(numeros);
      }break;
      case 4:{
        salir = true;
        cout << "Saliendo..." << endl;
        cout << "-------------------------------" << endl;
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
      case 5:{
        Decimal num(numeroNuevo);
        return num;
      }break;
      default:{
        cout << "Notación no válida, por favor intente de nuevo." << endl << endl;
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
      for (int i = 2; i < numeroString.length(); i++) {
        if (isdigit(numeroString[i])) {
          if ((int)numeroString[i] > 7) {
            return 5;
          }
        }else{
          return 5;
        }
      }

      return 3;
    }

    return 5;
}
