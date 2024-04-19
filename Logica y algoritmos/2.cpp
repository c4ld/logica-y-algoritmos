#include <iostream>

// Definimos N y D como enteros
int N, D;

int main() {
    // Consultamos el valor de N
    std::cout << "Ingrese el valor de N: ";
    std::cin >> N;

    // Iniciamos la suma de los divisores en 0
    int sumaDivisores = 0;

    // Almacenamos los divisores en una cadena para ser mostrados en la salida
    std::string cadenaDivisores = "";

    // Calculamos los divisores de N
    /*
    El  bucle empieza con 1 porque es divisor de todos los numeros.
    El bucle se seguirá ejecutando mientras D sea menor que N porque un divisor de N tiene que ser menor que si mismo
    Incrementamos D en 1 en cada iteracion para que el bucle no sea infinito
    */
    for (D = 1; D < N; D++) {
        // Verificamos si D es un divisor de N, es decir, si N dividido por D no deja residuo
        if (N % D == 0) {
            // Si es divisor, lo sumamos a la suma de los divisores
            sumaDivisores += D;
            // Y lo agregamos a la cadena de divisores, seguido de una coma y un espacio
            cadenaDivisores += std::to_string(D) + ", ";
        }
    }

    // Verificamos si N es un número perfecto, es decir, si la suma de sus divisores es N

    if (sumaDivisores == N) {
        // Si son iguales, N es un número perfecto
        std::cout << N << " es un número perfecto." << std::endl;
    } else {
        // Si no, N no es un número perfecto
        std::cout << N << " no es un número perfecto." << std::endl;
    }

    // Antes de imprimir los divisores, verificamos si la cadena no está vacía

    if (!cadenaDivisores.empty()) {
        // Si no está vacía, eliminamos la última coma y espacio
        cadenaDivisores.erase(cadenaDivisores.length() - 2);
    }

    // Imprimimos los divisores de N

    std::cout << "Pues sus divisores son: " << cadenaDivisores << ". ";

    // Imprimimos la suma de ellos

    std::cout << "Que sumados dan " << sumaDivisores << "." << std::endl;

return 0;
}