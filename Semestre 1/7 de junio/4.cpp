#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Articulo {
    string codigo;
    int nivel_minimo;
    int nivel_actual;
    string proveedor;
    double precio;
};

int main() {
    vector<Articulo> articulos;
    string nombreArchivo = "stock.dat";
    ifstream archivo(nombreArchivo);

    if (!archivo) {
        cerr << "Error al abrir el archivo: " << nombreArchivo <<endl;
        return 1; // Retorna un código de error
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        Articulo articulo;
        getline(ss, articulo.codigo, ' ');
        ss >> articulo.nivel_minimo;
        ss >> articulo.nivel_actual;
        ss.ignore(); // Ignora el espacio entre nivel_actual y proveedor
        getline(ss, articulo.proveedor, ' ');
        ss >> articulo.precio;
        articulos.push_back(articulo);
    }

    archivo.close();

    for (const auto& articulo : articulos) {
        if (articulo.nivel_actual < articulo.nivel_minimo) {
            cout << "Código: " << articulo.codigo << ", Proveedor: " << articulo.proveedor << ", Precio: " << articulo.precio << endl;
            cout << "Nivel Actual: " << articulo.nivel_actual << ", Nivel Mínimo: " << articulo.nivel_minimo << endl;
            cout << "Alerta: Hacer Pedido" << endl << endl;
        }
    }

    return 0;
}
