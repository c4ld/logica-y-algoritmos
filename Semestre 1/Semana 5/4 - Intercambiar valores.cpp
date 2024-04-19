/*Programa para crear un procedimiento que reciba dos variables reales como argumentos e intercambiar sus valores.
  */

#include <iostream>

// Procedimiento para intercambiar los valores de dos variables reales
void intercambiarValores(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

int main() {
    // Ejemplo de uso del procedimiento
    double x = 5.7;
    double y = 3.2;

    std::cout << "Antes del intercambio: x = " << x << ", y = " << y << std::endl;

    intercambiarValores(x, y);

    std::cout << "Después del intercambio: x = " << x << ", y = " << y << std::endl;

    return 0;
}
