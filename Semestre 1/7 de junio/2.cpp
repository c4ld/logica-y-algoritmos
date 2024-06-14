#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Contacto {
    string nombre;
    int edad;
    string direccion;
    string ciudad;
    string telefono;
};

int main() {
    Contacto contactos[5];

    cout << "Por favor ingrese la siguiente información para cada contacto:\n";
    for (int i = 0; i < 5; i++) {
        cout << "¿Cómo se llama el contacto n°" << i + 1 << "?\n";
        getline(cin, contactos[i].nombre);
        cout << "¿Cuántos años tiene " << contactos[i].nombre << "?\n";
        cin >> contactos[i].edad; // Leer la edad como un entero
        cin.ignore(); // Limpiar el buffer después de leer la edad
        cout << "¿Cuál es su dirección?\n";
        getline(cin, contactos[i].direccion);
        cout << "¿En qué ciudad vive?\n";
        getline(cin, contactos[i].ciudad);
        cout << "¿Cuál es su número de teléfono?\n";
        getline(cin, contactos[i].telefono);
    }

    // Guardar los contactos en el archivo agenda.dat
    ofstream archivo("agenda.dat");
    if (archivo.is_open()) {
        for (const auto& contacto : contactos) {
            archivo << contacto.nombre << endl;
            archivo << contacto.edad << endl;
            archivo << contacto.direccion << endl;
            archivo << contacto.ciudad << endl;
            archivo << contacto.telefono << endl;
        }
        archivo.close();
        cout << "Registros guardados en agenda.dat correctamente.\n";
    } else {
        cout << "Error al abrir el archivo para escritura.\n";
    }

    // Leer los contactos desde el archivo y mostrarlos en pantalla
    ifstream archivoLectura("agenda.dat");
    if (archivoLectura.is_open()) {
        Contacto contactoLeido;
        while (archivoLectura >> contactoLeido.nombre >> contactoLeido.edad >> contactoLeido.direccion >> contactoLeido.ciudad >> contactoLeido.telefono) {
            // Mostrar los datos leídos
            cout << "Nombre: " << contactoLeido.nombre << "\n";
            cout << "Edad: " << contactoLeido.edad << "\n";
            cout << "Dirección: " << contactoLeido.direccion << "\n";
            cout << "Ciudad: " << contactoLeido.ciudad << "\n";
            cout << "Teléfono: " << contactoLeido.telefono << "\n\n";
        }
        archivoLectura.close();
    } else {
        cout << "Error al abrir el archivo para lectura.\n";
    }
    return 0;
}
