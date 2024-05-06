#include <iostream>
using namespace std;

int main()
{
    int c;
    int a = 0;
    int b = 0;
    
    cout << "Este programa calcula los 100 primeros numeros cuadrados:" << endl;
    for(int n = 1; n <= 100; n++)
    {
        c++;
        cout << c*c << endl;
        a=c*c;
        b=a+b;
    }
    cout << "Y la suma total de esos numeros es de:" << endl;
    cout << b;
    
    return 0;
}