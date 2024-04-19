#include <iostream>

// Función para calcular el salario
double calcularSalario(double horasTrabajadas, double valorPorHora) {
    return horasTrabajadas * valorPorHora;
}

int main() {
    double horasTrabajadas;
    double valorPorHora;

    // Solicitar al usuario las horas trabajadas y el valor por hora
    std::cout << "Ingrese las horas trabajadas: ";
    std::cin >> horasTrabajadas;

    std::cout << "Ingrese el valor por hora: ";
    std::cin >> valorPorHora;

    // Calcular el salario utilizando la función calcularSalario
    double salario = calcularSalario(horasTrabajadas, valorPorHora);

    // Mostrar el salario
    std::cout << "El salario es: " << salario << std::endl;

    return 0;
}
