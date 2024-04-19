#include <iostream>
using namespace std;

void cambiarSigno(int &valor) {
    valor = -valor;
}

int main() {
    int numero;
    cout << "Ingrese un número entero para cambiar su signo: ";
    cin >> numero;
    cambiarSigno(numero);
    cout << "El número con el signo cambiado es: " << numero << endl;
    return 0;
}
