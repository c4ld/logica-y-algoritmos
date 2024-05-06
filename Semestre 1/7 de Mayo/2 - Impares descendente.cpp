#include <iostream>
using namespace std;

int main() {
    // Se crea un contador para los números impares
    int c = 0;
    // Se itera del 99 al 1 de 2 en 2 para evitar pares
    for (int n = 99; n > 0; n -= 2) {
        // El contador aumenta en 1
        c++;
        // Se imprime el número impar
        cout << c << ". " << n << endl;
        }
    // Se imprime la cantidad de números impares
    cout << "Hay " << c << " números impares entre 1 y 100." << endl;
    // Fin
    return 0;
}