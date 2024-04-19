#include <iostream>

double kilometros;

// Función para convertir kilómetros a metros
double kilometrosAMetros(double kilometros) {
    return kilometros * 1000;
}

int main() {
    // Solicitar la distancia en kilómetros
    std::cout << "Ingrese la distancia en kilometros: ";
    std::cin >> kilometros;

    // Convertir la distancia a metros
    double metros = kilometrosAMetros(kilometros);
    // Mostrar el resultado
    std::cout << "La distancia en metros es: " << metros << "m" << std::endl;
    return 0;
}
