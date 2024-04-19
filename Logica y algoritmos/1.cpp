#include <iostream>

using namespace std;

int main() {
    int numero;
    int sumaPares = 0;
    long long productoImpares = 1; // Usamos long long para evitar desbordamiento en el producto

    cout << "Ingrese una serie de números (ingrese 0 para terminar):\n";

    while (true) {
        cin >> numero;
        
        if (numero == 0) {
            break; // Salimos del bucle si el usuario ingresa 0
        }
        
        if (numero % 2 == 0) {
            sumaPares += numero;
        } else {
            productoImpares *= numero;
        }
    }

    cout << "La suma de los números pares es: " << sumaPares << endl;
    cout << "El producto de los números impares es: " << productoImpares << endl;

    return 0;
}