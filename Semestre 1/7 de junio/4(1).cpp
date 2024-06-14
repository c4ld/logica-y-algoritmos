#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Articulo {
    string codigo;
    int nivel_minimo;
    int nivel_actual;
    string proveedor;
    double precio;
};

int main() {
    // Datos de los artículos incorporados directamente en el código
    vector<Articulo> articulos = {
        {"A123", 50, 20, "Proveedor1", 1500.00},
        {"B456", 30, 10, "Proveedor2", 750.50},
        {"C789", 20, 5, "Proveedor3", 1200.25},
        {"D012", 60, 25, "Proveedor4", 500.00},
        {"E345", 10, 2, "Proveedor5", 1999.99}
    };

    for (const auto& articulo : articulos) {
        if (articulo.nivel_actual < articulo.nivel_minimo) {
            cout << "Código: " << articulo.codigo << ", Proveedor: " << articulo.proveedor << ", Precio: " << articulo.precio << endl;
            cout << "Nivel Actual: " << articulo.nivel_actual << ", Nivel Mínimo: " << articulo.nivel_minimo << endl;
            cout << "**Alerta: Hacer Pedido**" << endl << endl;
        }
    }

    return 0;
}
