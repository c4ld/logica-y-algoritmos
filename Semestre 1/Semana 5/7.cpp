#include <iostream>
using namespace std;

double base;
double altura;
double area;
double perimetro;

double AREArectangulo(double base, double altura){
    area = base*altura;
    return area;
}

double PERIMETROrectangulo(double base, double altura){
    double perimetro = (2*base)+(2*altura);
    return perimetro;
}

int main(){
    cout << "Introduzca la base y la altura del rectangulo" << endl;
    cin >> altura;
    cin >> base;
    area = AREArectangulo(base, altura);
    cout << "El area del rectangulo es de:" << endl << area << endl;
    perimetro = PERIMETROrectangulo(base, altura);
    cout << "Y su perimetro es de:" << endl << perimetro << endl;

    return 0;
}
