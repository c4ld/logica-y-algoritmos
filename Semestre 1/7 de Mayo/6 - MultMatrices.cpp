/*Diseña un programa que solicite al usuario ingresar dos matrices y 
luego realice la multiplicación de matrices. Asegúrate de que las 
dimensiones de las matrices sean compatibles para la multiplicación y 
muestra la matriz resultante.*/


#include <iostream>
using namespace std;

int main() {
    int filasA, columnasA, filasB, columnasB;

    cout << "Ingrese el número de filas de la matriz A: ";
    cin >> filasA;
    cout << "Ingrese el número de columnas de la matriz A: ";
    cin >> columnasA;

    cout << "Ingrese el número de filas de la matriz B: ";
    cin >> filasB;
    cout << "Ingrese el número de columnas de la matriz B: ";
    cin >> columnasB;

    // Verificar si las dimensiones son compatibles para la multiplicación
    if (columnasA != filasB) {
        cout << "No se pueden multiplicar estas matrices. Las dimensiones no son compatibles.";
        return 1;
    }

    // Declarar las matrices A, B y el resultado
    int matrizA[filasA][columnasA], matrizB[filasB][columnasB], resultado[filasA][columnasB];

    // Leer elementos de la matriz A
    cout << "Ingrese los elementos de la matriz A:\n";
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasA; j++) {
            cout << "Ingrese el elemento A[" << i << "][" << j << "]: ";
            cin >> matrizA[i][j];
        }
    }

    // Leer elementos de la matriz B
    cout << "Ingrese los elementos de la matriz B:\n";
    for (int i = 0; i < filasB; i++) {
        for (int j = 0; j < columnasB; j++) {
            cout << "Ingrese el elemento B[" << i << "][" << j << "]: ";
            cin >> matrizB[i][j];
        }
    }

    // Inicializar la matriz resultado con ceros
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            resultado[i][j] = 0;
        }
    }

    // Realizar la multiplicación de matrices y almacenar el resultado en la matriz resultado
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            for (int k = 0; k < columnasA; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    // Mostrar la matriz resultante como una multiplicación de matrices
    cout << "La multiplicación de la matriz A por la matriz B es:\n";
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            cout << resultado[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
