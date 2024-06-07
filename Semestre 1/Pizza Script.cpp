#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// Estructura para representar un ingrediente
struct Ingrediente {
    int ID;
    string nombre;
    string unidad; // Unidad de medida (por ejemplo, "Peso" o "Unidad")
    float cantidad; // Costo del ingrediente
};

vector<Ingrediente> inventario = {
    {1, "Masa", "kg", 0.0},
    {2, "Pepperoni", "unidad(es)", 0.0},
    {3, "Queso", "kg", 0.0},
    {4, "Aceitunas", "unidad(es)", 0.0},
    {5, "Jamón", "unidad(es)", 0.0},
    {6, "Piña", "unidad(es)", 0.0},
    {7, "Hongos", "unidad(es)", 0.0},
    {8, "Pimiento verde", "unidad(es)", 0.0},
    {9, "Salchicha", "unidad(es)", 0.0}
};

struct Pizza {
    string nombre;
    string tamaño;
    vector<pair<int, float>> ingredientes; // Lista de pares (ID del ingrediente, cantidad necesaria)
};

vector<Pizza> pizzas = {
    {"Pepperoni", "Personal", {{1, /*Masa*/ 0.25}, {2, /*Pepperoni*/ 8}}},
    {"Pepperoni", "Estandar", {{1, /*Masa*/ 0.5}, {2, /*Pepperoni*/ 8}}},
    {"Pepperoni", "Familiar", {{1, /*Masa*/1.0}, {2, /*Pepperoni*/ 8}}},
    {"Hawaiana", "Personal", {{1 /*Masa*/, 0.25}, {5 /*Jamón*/, 3}, {6 /*Piña*/, 3}}},
    {"Hawaiana", "Estandar", {{1 /*Masa*/, 0.5}, {5 /*Jamón*/, 6}, {6 /*Piña*/, 6}}},
    {"Hawaiana", "Familiar", {{1 /*Masa*/, 1.0}, {5 /*Jamón*/, 9}, {6 /*Piña*/, 9}}},
    {"Carnívora", "Personal", {{1 /*Masa*/, 0.25}, {2 /*Pepperoni*/, 8}, {9 /*Salchicha*/, 3}, {5 /*Jamón*/, 3}}},
    {"Carnívora", "Estandar", {{1 /*Masa*/, 0.5}, {2 /*Pepperoni*/, 16}, {9 /*Salchicha*/, 6}, {5 /*Jamón*/, 6}}},
    {"Carnívora", "Familiar", {{1 /*Masa*/, 1.0}, {2 /*Pepperoni*/, 24}, {9 /*Salchicha*/, 9}, {5 /*Jamón*/, 9}}},
    {"Vegetariana", "Personal", {{1 /*Masa*/, 0.25}, {7 /*Hongos*/, 5}, {8 /*Pimiento verde*/, 3}, {4 /*Aceitunas*/, 10}}},
    {"Vegetariana", "Estandar", {{1 /*Masa*/, 0.5}, {7 /*Hongos*/, 10}, {8 /*Pimiento verde*/, 6}, {4 /*Aceitunas*/, 20}}},
    {"Vegetariana", "Familiar", {{1 /*Masa*/, 1.0}, {7 /*Hongos*/, 15}, {8 /*Pimiento verde*/, 9}, {4 /*Aceitunas*/, 30}}}
};

// Función para agregar unidades de un ingrediente
void agregarUnidades(vector<Ingrediente>& inventario, size_t indice, int cantidad) {
    if (indice < inventario.size()) {
        inventario[indice].cantidad += cantidad;
        cout << "\nSe agregaron " << cantidad << " " << inventario[indice].unidad << " de " << inventario[indice].nombre << "!\n";
    } else {
        cout << "\n\tÍndice de ingrediente no válido.\n";
    }
}

int main() {
    

    int opcion;
    do {
        cout << "\n-----------------------------\n";
        cout << "Comandos\n";
        cout << "-----------------------------\n";
        cout << "1.\tAgregar ingredientes\n";
        cout << "2.\tRevisar inventario\n";
        cout << "3.\tGestionar caducidad\n";
        cout << "4.\tCocinar\n";
        cout << "0.\tSalir\n";
        cout << "-----------------------------\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            // Agregar ingredientes
            case 1:
                {
                    cout << "\n------------------------------------------\nQue ingredientes quieres agregar?\n------------------------------------------\n";
                    for (size_t i = 0; i < inventario.size(); ++i) {
                        cout << i + 1 << ".\t" << inventario[i].nombre << "\n";
                    }
                    cout << "------------------------------------------\n";
                    size_t seleccion;
                    cout << "Selecciona el numero del ingrediente: 2";
                    cin >> seleccion;
                    if(seleccion < 1 || seleccion > inventario.size()) {
                        cout << "\tOpción no válida. Intente nuevamente.\n";
                        break;
                    }
                    int cantidad;
                    cout << "Cuántos(as) " << inventario[seleccion - 1].unidad << " deseas agregar? ";
                    cin >> cantidad;
                    agregarUnidades(inventario, seleccion - 1, cantidad);
                }
                break;
            // Revisar inventario
            case 2:
                {
                cout << "\n------------------------------------------\nInventario de ingredientes\n------------------------------------------\n";
                cout << setw(14) << "Ingrediente" << setw(10) << "Cantidad" << setw(15) << "Unidad" << "\n";
                cout << "------------------------------------------\n";
                for (const auto& ingrediente : inventario) {
                    cout << setw(14) << ingrediente.nombre << setw(10) << ingrediente.cantidad << setw(15) << ingrediente.unidad <<"\n";
                }
                cout << "------------------------------------------\n";
                }
                break;
            // Gestionr caducidad
            case 3:
                break;
            // Cocinar
           case 4:
                {
                cout << "\n------------------------------------------\nMenu de pizzas\n------------------------------------------\n";
                for (size_t i = 0; i < pizzas.size(); ++i) {
                cout << i + 1 << ".\t" << pizzas[i].nombre << "\t" << pizzas[i].tamaño << "\n";
                }
                size_t seleccionPizza;
                cout << "Número de pizza: ";
                cin >> seleccionPizza;
                if(seleccionPizza < 1 || seleccionPizza > pizzas.size()) {
                cout << "Opción no válida.\n";
                break;
                }
                bool ingredientesDisponibles = true;
                for (const auto& ing : pizzas[seleccionPizza - 1].ingredientes) {
                    if (inventario[ing.first - 1].cantidad < ing.second) {
                    cout << "Faltan " << ing.second - inventario[ing.first - 1].cantidad << " " << inventario[ing.first - 1].unidad << " de " << inventario[ing.first - 1].nombre << ".\n";
                    ingredientesDisponibles = false;
                    }
                }
                if (ingredientesDisponibles) {
                    for (const auto& ing : pizzas[seleccionPizza - 1].ingredientes) {
                    inventario[ing.first - 1].cantidad -= ing.second;
                    }
                    cout << "La pizza " << pizzas[seleccionPizza - 1].nombre << " está en el horno.\n";
                } else {
                    cout << "No se puede cocinar la pizza por falta de ingredientes.\n";
                }
                }
                break;
            // Validacion
            default:
                cout << "\tOpción no válida. Intente nuevamente.\n";
        }
    } while (opcion != 0);
    return 0;
}
