/*2.	Escriba el programa que realice las operaciones básicas (suma, resta, multiplicación y división),
 a partir de dos números enteros desconocidos. Utilizar una función diferente por cada operación.  Utilizar función sin parámetros.*/

#include <iostream>


using namespace std;


// Funcion para sumar dos numeros enteros
int suma() {
    int num1, num2;
    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;
    return num1 + num2;
}

// Funcion para restar dos numeros enteros
int resta() {
    int num1, num2;
    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;
    return num1 - num2;
}

// Funcion para multiplicar dos numeros enteros
int multiplicacion() {
    int num1, num2;
    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;
    return num1 * num2;
}

// Funcion para dividir dos numeros enteros
double division() {
    int num1, num2;
    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;
    if (num2 != 0) {
        return static_cast<double>(num1) / num2;
    } else {
        cout << "Error: No se puede dividir entre cero." << endl;
        return 0.0;
    }
}

int main() {
    cout << "Operaciones basicas con dos numeros enteros:" << endl;
    cout << "Suma: " << suma() << endl;
    cout << "Resta: " << resta() << endl;
    cout << "Multiplicacion: " << multiplicacion() << endl;
    cout << "Division: " << division() << endl;

    return 0;
}
