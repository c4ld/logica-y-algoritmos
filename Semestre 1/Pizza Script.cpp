#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Estructura para representar un ingrediente
struct Ingrediente {
    string nombre;
    string unidad; // Unidad de medida (por ejemplo, "Peso" o "Unidad")
    double costo; // Costo del ingrediente
    int cantidad; // Cantidad en inventario
};

// Función para agregar unidades de un ingrediente
void agregarUnidades(vector<Ingrediente>& inventario, size_t indice, int cantidad) {
    if (indice < inventario.size()) {
        inventario[indice].cantidad += cantidad;
        cout << "Se agregaron " << cantidad << " " << inventario[indice].unidad << " de " << inventario[indice].nombre << " al inventario.\n";
    } else {
        cout << "Índice de ingrediente no válido.\n";
    }
}

// Función para mostrar el inventario completo
void mostrarInventario(const vector<Ingrediente>& inventario) {
    cout << "Inventario de ingredientes:\n";
    for (const auto& ingrediente : inventario) {
        cout << ingrediente.nombre << ": " << ingrediente.cantidad << " " << ingrediente.unidad << "\n";
    }
}

int main() {
    vector<Ingrediente> inventario = {
        {"Masa", "kg", 0.0, 0},
        {"Pepperoni", "unidad", 0.0, 0},
        {"Queso", "kg", 0.0, 0},
        {"Aceitunas", "unidad", 0.0, 0},
        {"Jamón", "unidad", 0.0, 0},
        {"Piña", "unidad", 0.0, 0},
        {"Hongos", "unidad", 0.0, 0},
        {"Pimiento verde", "unidad", 0.0, 0},
        {"Salchicha", "unidad", 0.0, 0}
        // Agrega más ingredientes aquí según la lista
    };

    int opcion;
    do {
        cout << "Bienvenido a Pizza Script\n";
        cout << "Comandos:\n";
        cout << "1. Agregar a inventario\n";
        cout << "2. Revisar inventario\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                {
                    cout << "Seleccione el ingrediente a agregar:\n";
                    for (size_t i = 0; i < inventario.size(); ++i) {
                        cout << i + 1 << ". " << inventario[i].nombre << "\n";
                    }

                    size_t seleccion;
                    cin >> seleccion;

                    int cantidad;
                    cout << "Cuántas " << inventario[seleccion - 1].unidad << " desea agregar? ";
                    cin >> cantidad;

                    agregarUnidades(inventario, seleccion - 1, cantidad);
                }
                break;
            case 2:
                mostrarInventario(inventario);
                break;
            case 0:
                cout << "¡Hasta luego!\n";
                break;
            default:
                cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcion != 0);

    return 0;
}