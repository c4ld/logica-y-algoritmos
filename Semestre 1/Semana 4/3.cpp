#include "iostream"
using namespace std;

int main()
{
    double p = 1;
    double s = 1; //Definimos los 2 primeros números de la sucesión
    int max; 
    int n = 2;
    cout << "Cuantos numeros quiere que se muestren?" << endl;
    cin >> max; //Introduzcamos cuántos números quieren que se muestren
    if (max<=0){
        cout << "No puedes poner 0 o un numero negativo"; //Si 'max' es menor que 0
    }
    else{
    cout << "El primer numero de la sucesion es:" << endl;
    cout << p << endl;
    if(max==1){
        cout << "Fin de la sucesion" << endl; //Si 'max' es igual a 1
    }
    else{
    cout << "El segundo numero de la sucesion es:" << endl;
    cout << s << endl;
    if (max==2){
        cout << "Fin de la sucesion" << endl; //Si 'max' es igual a 2
    }
    else{
        cout << "El resto de los numeros son:" << endl;
    while (n<max){ //Este ciclo se repetirá hasta que el contador 'n' tenga el mismo valor que 'max'
        cout << p+s << ", ";
        s=p+s; //La suma que se hizo anteriormente será el nuevo valor para 's'
        n++;
        if(n==max){
            cout << endl << "Fin de la sucesion";
        }
        else{
        cout << s+p << ", ";
        p=s+p; //La suma que se hizo anteriormente será el nuevo valor para 'p'
        n++;
        }
        if(n==max){
            cout << endl << "Fin de la sucesion";
        }
    }
    }
    }
    }
    return 0;
}