#include <iostream>
using namespace std;

double cm;
double inch;

double centimetrosApulgadas (double cm){
    inch = cm / 2.54;
    return inch;
}

int main(){
    cout << "Introduzca una longitud en centimetros" << endl;
    cin >> cm;
    cout << "Una pulgada es equivalente a:" << endl;
    cout << 2.54 << "cm" << endl;

    inch = centimetrosApulgadas (cm);
    
    cout << "Por lo cual, la longitud en pulgadas seria de:" << endl << inch << "in";

    return 0;
}
