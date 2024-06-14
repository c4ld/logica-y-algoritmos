#include <iostream>
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
    // Datos de los alumnos incorporados directamente en el código
    vector<Alumno> alumnos = {
        {"23020134", "Roderick", "Caldera", 8.5},
        {"23020135", "Stalin", "Cordoba", 9.0},
        {"23020136", "Yasser", "Detal", 7.5},
        {"23020137", "Camilo", "Galeano", 9.0},
    };

    float suma_notas = 0;
    float nota_maxima = 0;
    vector<Alumno> alumnos_nota_maxima;

    // A. Impresión a pantalla de todos los registros
    cout << "Todos los registros:" << endl;
    for (const auto& alumno : alumnos) {
        suma_notas += alumno.nota_final;
        cout << alumno.carnet << " " << alumno.nombre << " " << alumno.apellidos << " " << alumno.nota_final << endl;

        // B. La nota más alta y número de identificación del alumno correspondiente
        if (alumno.nota_final > nota_maxima) {
            nota_maxima = alumno.nota_final;
            alumnos_nota_maxima.clear();
            alumnos_nota_maxima.push_back(alumno);
        } else if (alumno.nota_final == nota_maxima) {
            alumnos_nota_maxima.push_back(alumno);
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

    return 0;
}