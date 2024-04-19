/*1.Escribe un programa que permita convertir temperaturas Fahrenheit a grados Celsius.  Utilice una función con parámetros.*/

#include <iostream>
using namespace std;

double fahrenheitACelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int main() {
    double fahrenheit;
    cout << "Ingrese la temperatura en grados Fahrenheit: ";
    cin >> fahrenheit;
    double celsius = fahrenheitACelsius(fahrenheit);
    cout << "La temperatura en grados Celsius es: " << celsius << endl;
    return 0;
}
