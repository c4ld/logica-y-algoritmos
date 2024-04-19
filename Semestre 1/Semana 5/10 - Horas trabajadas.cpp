#include <iostream>

int horasTrabajadas;

// Declaración de la función para calcular el pago
double calcularPago(int horas) {
    //Definimos el pago por las primeras 160 horas
    const double tarifaAntes = 6.5;
    // Definimos el pago por el resto de tiempo
    const double tarifaDespues = 7.5;
    const int primerasHoras = 160;
    double pago;

    if (horas <= primerasHoras) {
        pago = horas * tarifaAntes;
    } else {
        pago = (primerasHoras * tarifaAntes) + ((horas - primerasHoras) * tarifaDespues);
    }

    return pago;
}

int main() {
    std::cout << "Ingrese el número de horas trabajadas: ";
    std::cin >> horasTrabajadas;

    // Llamada a la función y muestra del resultado
    double pago = calcularPago(horasTrabajadas);
    std::cout << "El valor a pagar es: $" << pago << std::endl;

    return 0;
}
