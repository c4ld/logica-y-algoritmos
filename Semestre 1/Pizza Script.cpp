#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

float saldo;

struct Ingrediente {
    int ID;
    string nombre;
    string unidad; // Unidad de medida (por ejemplo, "Peso" o "Unidad")
    float costo; // Costo del ingrediente
    float min; // Si la cantidad es menor a 'min', se considera stock bajo
    float max; // Si la cantidad es mayor a 'max', se considera sobrestock
    float cantidad;
};

// Estructura para representar un ingrediente
struct Pizza {
    string nombre;
    string tamaño;
    vector<pair<int, float>> ingredientes; // Lista de pares (ID del ingrediente, cantidad necesaria)
    float costo;
};

// Inventario de ingredientes
vector<Ingrediente> inventario = {
    {1, "Masa", "kg", 2.0, 10, 40, 0.0},
    {2, "Tomate", "kg", 1.5, 5, 20, 0.0},
    {3, "Queso", "kg", 3.0, 8, 16, 0.0},
    {4, "Pepperoni", "unidad(es)", 0.8, 3, 30, 0.0},
    {5, "Aceitunas", "unidad(es)", 0.5, 2, 20, 0.0},
    {6, "Jamón", "unidad(es)", 1.2, 4, 40, 0.0},
    {7, "Piña", "unidad(es)", 1.0, 3, 30, 0.0},
    {8, "Hongos", "unidad(es)", 0.7, 2, 20, 0.0},
    {9, "Pimiento verde", "unidad(es)", 0.8, 2, 20, 0.0},
    {10, "Salchicha", "unidad(es)", 1.0, 3, 20, 0.0}
};

// Lista de pizzas disponibles
vector<Pizza> pizzas = {
    {"Pepperoni", "Personal", {{1 /*Masa*/, 0.25}, {2 /*Tomate*/, 0.1}, {3 /*Queso*/, 0.2}, {4 /*Pepperoni*/, 8}}, 50.0},
    {"Pepperoni", "Estandar", {{1 /*Masa*/, 0.5}, {2 /*Tomate*/, 0.2}, {3 /*Queso*/, 0.4}, {4 /*Pepperoni*/, 8}}, 75.0},
    {"Pepperoni", "Familiar", {{1 /*Masa*/, 1.0}, {2 /*Tomate*/, 0.4}, {3 /*Queso*/, 0.8}, {4 /*Pepperoni*/, 8}}, 100.0},
    {"Hawaiana", "Personal", {{1 /*Masa*/, 0.25}, {2 /*Tomate*/, 0.1}, {3 /*Queso*/, 0.2}, {6 /*Jamón*/, 3}, {7 /*Piña*/, 3}}, 60.0},
    {"Hawaiana", "Estandar", {{1 /*Masa*/, 0.5}, {2 /*Tomate*/, 0.2}, {3 /*Queso*/, 0.4}, {6 /*Jamón*/, 6}, {7 /*Piña*/, 6}}, 90.0},
    {"Hawaiana", "Familiar", {{1 /*Masa*/, 1.0}, {2 /*Tomate*/, 0.4}, {3 /*Queso*/, 0.8}, {6 /*Jamón*/, 9}, {7 /*Piña*/, 9}}, 120.0},
    {"Carnívora", "Personal", {{1 /*Masa*/, 0.25}, {2 /*Tomate*/, 0.1}, {3 /*Queso*/, 0.2}, {4 /*Pepperoni*/, 8}, {9 /*Salchicha*/, 3}, {6 /*Jamón*/, 3}}, 65.0},
    {"Carnívora", "Estandar", {{1 /*Masa*/, 0.5}, {2 /*Tomate*/, 0.2}, {3 /*Queso*/, 0.4}, {4 /*Pepperoni*/, 16}, {9 /*Salchicha*/, 6}, {6 /*Jamón*/, 6}}, 95.0},
    {"Carnívora", "Familiar", {{1 /*Masa*/, 1.0}, {2 /*Tomate*/, 0.4}, {3 /*Queso*/, 0.8}, {4 /*Pepperoni*/, 24}, {9 /*Salchicha*/, 9}, {6 /*Jamón*/, 9}}, 125.0},
    {"Vegetariana", "Personal", {{1 /*Masa*/, 0.25}, {2 /*Tomate*/, 0.1}, {3 /*Queso*/, 0.2}, {7 /*Hongos*/, 5}, {8 /*Pimiento verde*/, 3}, {5 /*Aceitunas*/, 10}}, 55.0},
    {"Vegetariana", "Estandar", {{1 /*Masa*/, 0.5}, {2 /*Tomate*/, 0.2}, {3 /*Queso*/, 0.4}, {7 /*Hongos*/, 10}, {8 /*Pimiento verde*/, 6}, {5 /*Aceitunas*/, 20}}, 85.0},
    {"Vegetariana", "Familiar", {{1 /*Masa*/, 1.0}, {2 /*Tomate*/, 0.4}, {3 /*Queso*/, 0.8}, {7 /*Hongos*/, 15}, {8 /*Pimiento verde*/, 9}, {5 /*Aceitunas*/, 30}}, 115.0}
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

// Función para imprimir una acción
void imprimirAccion(const Accion& accion) {
    time_t tiempo = chrono::system_clock::to_time_t(accion.tiempo);
    cout << "[" << put_time(localtime(&tiempo), "%Y-%m-%d %H:%M:%S") << "] " << accion.descripcion << endl;
}

// Función para buscar y mostrar acciones en un rango de fechas
void buscarEnHistorial(const chrono::system_clock::time_point& desde, const chrono::system_clock::time_point& hasta) {
    cout << "Acciones realizadas entre ";
    auto desde_time_t = chrono::system_clock::to_time_t(desde);
    auto hasta_time_t = chrono::system_clock::to_time_t(hasta);

    cout << put_time(localtime(&desde_time_t), "%Y-%m-%d %H:%M:%S") << " y ";
    cout << put_time(localtime(&hasta_time_t), "%Y-%m-%d %H:%M:%S") << ":\n";

    bool encontrado = false;
    for (const auto& accion : historial) {
        auto accion_time_t = chrono::system_clock::to_time_t(accion.tiempo);
        if (accion_time_t >= desde_time_t && accion_time_t <= hasta_time_t) {
            imprimirAccion(accion);
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron acciones en el rango especificado.\n";
    }
}

// Función para obtener y validar una fecha del usuario
chrono::system_clock::time_point obtenerFechaUsuario(const string& mensaje) {
    string inputFecha;
    chrono::system_clock::time_point fecha;
    while (true) {
        cout << mensaje << " (YYYY-MM-DD HH:MM:SS): ";
        getline(cin, inputFecha);
        stringstream ss(inputFecha);
        tm tmFecha = {};
        ss >> get_time(&tmFecha, "%Y-%m-%d %H:%M:%S");
        if (ss.fail()) {
            cout << "Formato de fecha incorrecto. Inténtelo de nuevo.\n";
            continue;
        }
        time_t tiempo = mktime(&tmFecha);
        fecha = chrono::system_clock::from_time_t(tiempo);
        break;
    }
    return fecha;
}

int main() {
    

    int opcion;
    do {
        cout << "\n-----------------------------\n";
        cout << "Menu principal\n";
        cout << "-----------------------------\n";
        cout << "Saldo: "<< saldo <<"\n";
        cout << "\n-------Modificar Saldo-------\n";
        cout << "1.\tAgregar saldo\n";
        cout << "2.\tRestar saldo\n";
        cout << "\n----------Inventario----------\n";
        cout << "3.\tRevisar stock\n";
        cout << "4.\tComprar ingredientes\n";
        cout << "5.\tCocinar\n";
        cout << "\n-----------Historial-----------\n";
        cout << "6.\tHistorial\n";
        cout << "7.\tBuscar\n";

        cout << "0.\tSalir\n";
        cout << "-----------------------------\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1: { // Agregar saldo
                float agregar;
                cout << "Ingrese la cantidad a agregar: ";
                cin >> agregar;
                if(agregar <= 0)
                {
                    cout << "Introduzca una cantidad valida" << endl;
                    break;
                }
                else
                {
                    saldo += agregar;
                    string descripcionHistorial = "Se agrego " + to_string(agregar) + " al saldo.";
                    historial.push_back({descripcionHistorial, chrono::system_clock::now()});
                    break;
                }
            }
            case 2: { // Restar saldo
                float restar;
                cout << "Ingrese la cantidad a restar: ";
                cin >> restar;
                if(restar <= 0)
                {
                    cout << "Introduzca una cantidad valida" << endl;
                    break;
                }
                else
                {
                    if(restar > saldo)
                    {
                        cout << "Se esta retirando mas saldo de lo que se tiene!" << endl;
                        break;
                    }
                    else
                    {
                        saldo -= restar;
                        string descripcionHistorial = "Se resto " + to_string(restar) + " al saldo.";
                        historial.push_back({descripcionHistorial, chrono::system_clock::now()});
                        break;
                    }
                }
            }
            case 3: { // Revisar inventario
    cout << "\n----------------------------------------------------------\n";
    cout << "Inventario\n";
    cout << "----------------------------------------------------------\n";
    cout << setw(14) << "Ingrediente" << setw(10) << "Cantidad" << setw(15) << "Unidad" << setw(10) << "Stock" << setw(10) << "Costo\n";
    cout << "------------------------------------------\n";
    float costoTotal = 0.0;
    float inversionTotalNecesaria = 0.0; // Variable para acumular la inversión total necesaria
    for (const auto& ingrediente : inventario) {
        cout << setw(14) << ingrediente.nombre << setw(10) << ingrediente.cantidad << setw(15) << ingrediente.unidad;
        if (ingrediente.cantidad < ingrediente.min) {
            float cantidadNecesaria = ingrediente.min - ingrediente.cantidad;
            float inversionNecesaria = cantidadNecesaria * ingrediente.costo;
            inversionTotalNecesaria += inversionNecesaria; // Acumular la inversión necesaria
            cout << setw(12) << "BAJO!" << setw(10) << "$" << fixed << setprecision(2) << inversionNecesaria << "\n";
        } else if (ingrediente.cantidad > ingrediente.max) {
            cout << setw(12) << "SOBRESTOCK!" << setw(10) << "$0.00\n";
        } else {
            float costoIngrediente = ingrediente.costo * ingrediente.cantidad;
            costoTotal += costoIngrediente; // Agregar al costo total
            cout << setw(12) << "Bien" << setw(10) << "$" << fixed << setprecision(2) << costoIngrediente << "\n";
        }
    }
    cout << "------------------------------------------\n";
    cout << "Costo total: $" << fixed << setprecision(2) << costoTotal << "\n"; // Mostrar el costo total
    cout << "Inversión total necesaria para superar el stock mínimo: $" << fixed << setprecision(2) << inversionTotalNecesaria << "\n"; // Mostrar la inversión total necesaria
    break;
}

            case 4: { // Agregar ingredientes
    cout << "\n------------------------------------------\nQue ingredientes quieres agregar?\n------------------------------------------\n";
    cout << setw(3) << "ID"
         << setw(20) << "Nombre"
         << setw(20) << "Costo\n";
    for (size_t i = 0; i < inventario.size(); ++i) {
        cout << setw(3) << i + 1 << ". "
             << setw(20) << inventario[i].nombre 
             << setw(10) << inventario[i].costo
             << setw (10) << "por"
             << setw (10) << inventario[i].unidad << "\n";
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
    
    // Calcular el costo total del ingrediente
    float costoIngrediente = inventario[seleccion - 1].costo * cantidad;
    
    // Validar si hay suficiente capital
    if (saldo < costoIngrediente) {
        cout << "No tienes suficiente saldo para realizar esta compra. Necesitas $" << costoIngrediente << " pero solo tienes $" << saldo << ".\n";
        break;
    }
    
    // Si hay suficiente capital, realizar la compra
    agregarUnidades(inventario, seleccion - 1, cantidad);
    
    // Restar el capital
    saldo -= costoIngrediente;
    cout << "Se restaron $" << costoIngrediente << " del capital. Capital restante: $" << saldo << ".\n";
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
                float costoTotalIngredientes = 0.0;

                // Verificar disponibilidad de ingredientes y calcular el costo total necesario
                for (const auto& ing : pizzas[seleccionPizza - 1].ingredientes) {
                    float cantidadNecesaria = ing.second;
                    float cantidadActual = inventario[ing.first - 1].cantidad;
                if (cantidadActual < cantidadNecesaria) {
                        cout << "Faltan " << cantidadNecesaria - cantidadActual << " " << inventario[ing.first - 1].unidad << " de " << inventario[ing.first - 1].nombre << ".\n";
                        ingredientesDisponibles = false;
                        costoTotalIngredientes += (cantidadNecesaria - cantidadActual) * inventario[ing.first - 1].costo;
                    }
                }

    if (ingredientesDisponibles) {
        // Cocinar la pizza si todos los ingredientes están disponibles
        for (const auto& ing : pizzas[seleccionPizza - 1].ingredientes) {
            inventario[ing.first - 1].cantidad -= ing.second;
        }
        saldo += pizzas[seleccionPizza - 1].costo;
        cout << "La pizza " << pizzas[seleccionPizza - 1].nombre << " está en el horno.\n";
        cout << "Se agregaron $" << pizzas[seleccionPizza - 1].costo << " al saldo.\n";
        string descripcionHistorial = "Se cocinó " + pizzas[seleccionPizza - 1].nombre + " " + pizzas[seleccionPizza - 1].tamaño + ". Se agregaron $" + to_string(pizzas[seleccionPizza - 1].costo) + " al capital.";
        historial.push_back({descripcionHistorial, chrono::system_clock::now()});
    } else {
        // Mostrar el costo total para comprar los ingredientes faltantes
        cout << "No se puede cocinar la pizza por falta de ingredientes.\n";
        cout << "Se necesita invertir $" << costoTotalIngredientes << " para comprar los ingredientes faltantes.\n";
    }
    break;
}
            case 6: { // Historial
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
            case 7: { // Buscar
                cin.ignore(); // Limpiar el buffer de entrada
                // Obtener fechas desde y hasta el usuario
                chrono::system_clock::time_point desde = obtenerFechaUsuario("Ingrese la fecha desde");
                chrono::system_clock::time_point hasta = obtenerFechaUsuario("Ingrese la fecha hasta");

                // Búsqueda en el historial por rango de fechas
                buscarEnHistorial(desde, hasta);
                break;
            }
            default:
                cout << "\tOpción no válida. Intente nuevamente.\n";
        }
    } while (opcion != 0);
    cout << "Hasta pronto!";
    return 0;
}
