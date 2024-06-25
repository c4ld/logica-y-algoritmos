#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

float saldo;

// Estructura para representar un ingrediente
struct Ingrediente {
    int ID;
    string nombre;
    string unidad; // Unidad de medida (por ejemplo, "Peso" o "Unidad")
    float costo; // Costo del ingrediente
    float min;
    float cantidad;
};

vector<Ingrediente> inventario = {
    {1, "Masa", "kg", 1.0, 50, 0.0},
    {2, "Pepperoni", "unidad(es)", 1.0, 20, 0.0},
    {3, "Queso", "kg", 1.0, 50, 0.0},
    {4, "Aceitunas", "unidad(es)", 1.0, 20, 0.0},
    {5, "Jamón", "unidad(es)", 1.0, 30, 0.0},
    {6, "Piña", "unidad(es)", 1.0, 10, 0.0},
    {7, "Hongos", "unidad(es)", 1.0, 15, 0.0},
    {8, "Pimiento verde", "unidad(es)", 1.0, 10, 0.0},
    {9, "Salchicha", "unidad(es)", 1.0, 15, 0.0}
};

struct Pizza {
    string nombre;
    string tamaño;
    vector<pair<int, float>> ingredientes; // Lista de pares (ID del ingrediente, cantidad necesaria)
    float costo;
};

vector<Pizza> pizzas = {
    {"Pepperoni", "Personal", {{1, /*Masa*/ 0.25}, {2, /*Pepperoni*/ 8}}, 50.0},
    {"Pepperoni", "Estandar", {{1, /*Masa*/ 0.5}, {2, /*Pepperoni*/ 8}}, 75.0},
    {"Pepperoni", "Familiar", {{1, /*Masa*/ 1.0}, {2, /*Pepperoni*/ 8}}, 100.0},
    {"Hawaiana", "Personal", {{1 /*Masa*/, 0.25}, {5 /*Jamón*/, 3}, {6 /*Piña*/, 3}}, 60.0},
    {"Hawaiana", "Estandar", {{1 /*Masa*/, 0.5}, {5 /*Jamón*/, 6}, {6 /*Piña*/, 6}}, 90.0},
    {"Hawaiana", "Familiar", {{1 /*Masa*/, 1.0}, {5 /*Jamón*/, 9}, {6 /*Piña*/, 9}}, 120.0},
    {"Carnívora", "Personal", {{1 /*Masa*/, 0.25}, {2 /*Pepperoni*/, 8}, {9 /*Salchicha*/, 3}, {5 /*Jamón*/, 3}}, 65.0},
    {"Carnívora", "Estandar", {{1 /*Masa*/, 0.5}, {2 /*Pepperoni*/, 16}, {9 /*Salchicha*/, 6}, {5 /*Jamón*/, 6}}, 95.0},
    {"Carnívora", "Familiar", {{1 /*Masa*/, 1.0}, {2 /*Pepperoni*/, 24}, {9 /*Salchicha*/, 9}, {5 /*Jamón*/, 9}}, 125.0},
    {"Vegetariana", "Personal", {{1 /*Masa*/, 0.25}, {7 /*Hongos*/, 5}, {8 /*Pimiento verde*/, 3}, {4 /*Aceitunas*/, 10}}, 55.0},
    {"Vegetariana", "Estandar", {{1 /*Masa*/, 0.5}, {7 /*Hongos*/, 10}, {8 /*Pimiento verde*/, 6}, {4 /*Aceitunas*/, 20}}, 85.0},
    {"Vegetariana", "Familiar", {{1 /*Masa*/, 1.0}, {7 /*Hongos*/, 15}, {8 /*Pimiento verde*/, 9}, {4 /*Aceitunas*/, 30}}, 115.0}
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

int buscarIngrediente(const string& nombre) {
    for (size_t i = 0; i < inventario.size(); ++i) {
        if (inventario[i].nombre == nombre) {
            return static_cast<int>(i); // Devolvemos el índice del ingrediente encontrado
        }
    }
    return -1; // Si no se encuentra, devolvemos -1
}

struct Accion {
    string descripcion;
    chrono::system_clock::time_point tiempo;
};

vector<Accion> historial;

int main() {
    

    int opcion;
    do {
        cout << "\n-----------------------------\n";
        cout << "Menu principal\n";
        cout << "-----------------------------\n";
        cout << "Saldo: "<< saldo <<"\n";
        cout << "1.\tAgregar saldo\n";
        cout << "2.\tRestar saldo\n\n";

        cout << "3.\tRevisar stock\n";
        cout << "4.\tComprar ingredientes\n";
        cout << "5.\tCocinar\n";
        cout << "6.\tGestionar caducidad\n\n";

        cout << "7.\tHistorial\n";
        cout << "8.\tBuscar\n\n";

        cout << "0.\tSalir\n";
        cout << "-----------------------------\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1: { // Agregar saldo
                float agregar;
                cout << "Ingrese la cantidad a agregar: ";
                cin >> agregar;
                saldo += agregar;
                string descripcionHistorial = "Se agrego " + to_string(agregar) + " al saldo.";
                historial.push_back({descripcionHistorial, chrono::system_clock::now()});
                break;
            }
            case 2: { // Restar saldo
                float restar;
                cout << "Ingrese la cantidad a restar: ";
                cin >> restar;
                saldo -= restar;
                string descripcionHistorial = "Se resto " + to_string(restar) + " al saldo.";
                historial.push_back({descripcionHistorial, chrono::system_clock::now()});
                break;
            }
            case 3: { // Revisar inventario
                    cout << "\n----------------------------------------------------------\n";
                    cout << "Inventario\n";
                    cout << "----------------------------------------------------------\n";
                    cout << setw(14) << "Ingrediente" << setw(10) << "Cantidad" << setw(15) << "Unidad" << setw(10) << "Stock" << setw(10) << "Costo\n";
                    cout << "------------------------------------------\n";
                    float costoTotal = 0.0;
                    for (const auto& ingrediente : inventario) {
                        cout << setw(14) << ingrediente.nombre << setw(10) << ingrediente.cantidad << setw(15) << ingrediente.unidad;
                        if (ingrediente.cantidad < ingrediente.min) {
                            cout << setw(12) << "BAJO!" << setw(10) << "$0.00\n";
                        } else {
                            float costoIngrediente = ingrediente.costo * ingrediente.cantidad;
                            costoTotal += costoIngrediente; // Agregar al costo total
                            cout << setw(12) << "Bien" << setw(10) << "$" << fixed << setprecision(2) << costoIngrediente << "\n";
                        }
                    }
                    cout << "------------------------------------------\n";
                    cout << "Costo total: $" << fixed << setprecision(2) << costoTotal << "\n"; // Mostrar el costo total
                break;
            }
            case 4: { // Agregar ingredientes
                    cout << "\n------------------------------------------\nQue ingredientes quieres agregar?\n------------------------------------------\n";
                    for (size_t i = 0; i < inventario.size(); ++i) {
                        cout << i + 1 << ".\t" << inventario[i].nombre << "\n";
                    }
                    cout << "------------------------------------------\n";
                    size_t seleccion;
                    cout << "Selecciona el numero del ingrediente: ";
                    cin >> seleccion;
                    if(seleccion < 1 || seleccion > inventario.size()) {
                        cout << "\tOpción no válida. Intente nuevamente.\n";
                        break;
                    }
                    int cantidad;
                    cout << "Cuántos(as) " << inventario[seleccion - 1].unidad << " deseas agregar? ";
                    cin >> cantidad;
                    agregarUnidades(inventario, seleccion - 1, cantidad);
                    // Restar el capital
                    float costoIngrediente = inventario[seleccion - 1].costo * cantidad;
                    saldo -= costoIngrediente;
                    cout << "Se restaron $" << costoIngrediente << " del capital.\n";
                break;
            }
            case 5: { // Cocinar
                cout << "\n-----------------------------\n";
                cout << "Menu\n";
                cout << "-----------------------------\n";
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
                saldo += pizzas[seleccionPizza - 1].costo;
                cout << "La pizza " << pizzas[seleccionPizza - 1].nombre << " está en el horno.\n";
                cout << "Se agregaron $" << pizzas[seleccionPizza - 1].costo << " al saldo.\n";
                string descripcionHistorial = "Se cocinó " + pizzas[seleccionPizza - 1].nombre + " " + pizzas[seleccionPizza - 1].tamaño + ". Se agregaron $" + to_string(pizzas[seleccionPizza - 1].costo) + " al capital.";
                historial.push_back({descripcionHistorial, chrono::system_clock::now()});
                }
                else {
                    cout << "No se puede cocinar la pizza por falta de ingredientes.\n";
                }
                break;
            }
            case 6: { // Gestionar caducidad
                break;
            }
            case 7: { // Historial
                cout << "\n-----------------------------\n";
                cout << "Historial\n";
                cout << "-----------------------------\n";
                for (const auto& accion : historial) {
                    std::time_t tiempo = std::chrono::system_clock::to_time_t(accion.tiempo);
                    cout << accion.descripcion << " " << std::put_time(std::localtime(&tiempo), "%Y-%m-%d %H:%M:%S") << ")\n";
                }
                cout << "------------------------------------------\n";
                break;
            }
            case 8: { // Buscar
                break;
            }
            default:
                cout << "\tOpción no válida. Intente nuevamente.\n";
        }
    } while (opcion != 0);
    cout << "Hasta pronto!";
    return 0;
}
