#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Alumno {
    string carnet;
    string nombre;
    string apellidos;
    float nota_final;
};

int main() {
    vector<Alumno> alumnos;
    ifstream archivo("calificaciones.dat");
    Alumno temp;
    float suma_notas = 0;
    float nota_maxima = 0;
    vector<Alumno> alumnos_nota_maxima;

    if (!archivo) {
        cerr << "No se pudo abrir el archivo calificaciones.dat" << endl;
        return 1;
    }

    // A. Impresión a pantalla de todos los registros
    cout << "Todos los registros:" << endl;
    while (archivo >> temp.carnet >> temp.nombre >> temp.apellidos >> temp.nota_final) {
        alumnos.push_back(temp);
        suma_notas += temp.nota_final;
        cout << temp.carnet << " " << temp.nombre << " " << temp.apellidos << " " << temp.nota_final << endl;

        // B. La nota más alta y número de identificación del alumno correspondiente
        if (temp.nota_final > nota_maxima) {
            nota_maxima = temp.nota_final;
            alumnos_nota_maxima.clear();
            alumnos_nota_maxima.push_back(temp);
        } else if (temp.nota_final == nota_maxima) {
            alumnos_nota_maxima.push_back(temp);
        }
    }

    // B. Visualización de todos los alumnos con la nota más alta
    cout << "\nAlumnos con la nota más alta:" << endl;
    for (const auto& alumno : alumnos_nota_maxima) {
        cout << "Carnet: " << alumno.carnet << ", Nombre: " << alumno.nombre << " " << alumno.apellidos << ", Nota Final: " << alumno.nota_final << endl;
    }

    // C. Nota promedio del curso
    float promedio = suma_notas / alumnos.size();
    cout << "\nNota promedio del curso: " << fixed << setprecision(2) << promedio << endl;

    archivo.close();
    return 0;
}