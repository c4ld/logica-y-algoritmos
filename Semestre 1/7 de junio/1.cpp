#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Registro {
    string nombre;
    int edad;
    string ciudad;
    string direccion;
    string telefono;
};

int main() {
    const int MAX_REGISTROS = 50;
    Registro registros[MAX_REGISTROS];
    int numRegistros = 0;

    ofstream archivo("agenda.dat", ios::out | ios::binary);

    if (!archivo) {
        cerr << "Error al crear o abrir el archivo." << endl;
        return 1;
    }

    cout << "Introduce los datos de las personas (nombre vacío para terminar):" << endl;

    while (numRegistros < MAX_REGISTROS) {
        cout << "Nombre: ";
        getline(cin, registros[numRegistros].nombre);

        if (registros[numRegistros].nombre.empty()) {
            break;
        }

        cout << "Edad: ";
        cin >> registros[numRegistros].edad;
        cin.ignore(); // Clear newline character from input buffer

        cout << "Ciudad: ";
        cin.ignore(); // Clear newline character
        getline(cin, registros[numRegistros].ciudad);

        cout << "Dirección: ";
        getline(cin, registros[numRegistros].direccion);

        cout << "Teléfono: ";
        getline(cin, registros[numRegistros].telefono);

        // Escribir los campos individuales en el archivo
        archivo << registros[numRegistros].nombre << "\n";
        archivo << registros[numRegistros].edad << "\n";
        archivo << registros[numRegistros].ciudad << "\n";
        archivo << registros[numRegistros].direccion << "\n";
        archivo << registros[numRegistros].telefono << "\n";

        numRegistros++;
    }

    archivo.close();

    cout << "Se han guardado " << numRegistros << " registros en agenda.dat." << endl;

    return 0;
}
