/*Desarrolla un programa que solicite al usuario ingresar dos vectores
de igual longitud y luego calcule la suma de ambos vectores. El
resultado debe mostrarse en un tercer vector.*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int longitud;
    cout << "Ingrese la longitud de los vectores: ";
    cin >> longitud;

    vector<int> vector1(longitud), vector2(longitud), suma(longitud);

    cout << "Ingrese los elementos del primer vector:" << endl;
    for(int i = 0; i < longitud; ++i) {
        cin >> vector1[i];
    }

    cout << "Ingrese los elementos del segundo vector:" << endl;
    for(int i = 0; i < longitud; ++i) {
        cin >> vector2[i];
    }

    // Calculando la suma de los vectores
    for(int i = 0; i < longitud; ++i) {
        suma[i] = vector1[i] + vector2[i];
    }

    cout << "La suma de ambos vectores es:" << endl;
    for(int i = 0; i < longitud; ++i) {
        cout << suma[i] << ' ';
    }
    cout << endl;

    return 0;
}
