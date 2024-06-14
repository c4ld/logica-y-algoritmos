#include <iostream>
#include <fstream> // Para flujo de archivos (ofstream, ifstream)

using namespace std;

// Estructura para almacenar la información de un contacto
struct Contacto {
    string nombre;
    int edad;
    string direccion;
    string ciudad;
    string telefono;
};

int main() {
    // Crear un arreglo de 5 contactos
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
    ofstream archivo("agenda.dat", ios::binary); // Abrir archivo para escritura binaria
    if (archivo.is_open()) {
        archivo.write(reinterpret_cast<char*>(&contactos), sizeof(contactos)); // Escribe los datos en el archivo
        archivo.close();
        cout << "Registros guardados en agenda.dat correctamente.\n";
    } else {
        cout << "Error al abrir el archivo para escritura.\n";
    }

    // Leer los contactos desde el archivo y mostrarlos en pantalla
    ifstream archivoLectura("agenda.dat", ios::binary); // Abrir archivo para lectura binaria
    if (archivoLectura.is_open()) {
        Contacto contactosLeidos[5];
        archivoLectura.read(reinterpret_cast<char*>(&contactosLeidos), sizeof(contactosLeidos)); // Leer los datos
        archivoLectura.close();

        cout << "\nRegistros almacenados en agenda.dat:\n";
        for (int i = 0; i < 5; i++) {
            cout << "Contacto n°" << i + 1 << "\n";
            cout << "Nombre: " << contactosLeidos[i].nombre << "\n";
            cout << "Edad: " << contactosLeidos[i].edad << "\n";
            cout << "Dirección: " << contactosLeidos[i].direccion << "\n";
            cout << "Ciudad: " << contactosLeidos[i].ciudad << "\n";
            cout << "Teléfono: " << contactosLeidos[i].telefono << "\n\n";
        }
    } else {
        cout << "Error al abrir el archivo para lectura.\n";
    }
    return 0;
}