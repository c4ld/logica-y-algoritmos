#include <iostream>
using namespace std;

double milla;
double metro;

double conversion(){
    metro=milla*1852;
    return metro;
    return milla*1852;
}

int main(){
    cout << "Escriba una longitud expresada en millas marinas" << endl;
    cin >> milla;
    cout << "Sabiendo que una milla marina es equivalente a: 1852 metros" << endl;
    metro = conversion();
    cout << "La longitud expresada en metros seria de:" << endl << metro << "m" << endl;

    return 0;
}
