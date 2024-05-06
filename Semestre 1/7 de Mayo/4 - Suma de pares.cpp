#include <iostream>
using namespace std;

int u;
int c;
int y = 0;

void par(int u, int c)
{
    for(u = 100; u <= 200; u++)
    {
        if(u%2 == 0)
        {
            c++;
        }
    }
    cout << c << endl;
}

int main()
{
    cout << "La suma de los numeros pares del 100 al 200 es de:" << endl;
    for(int u = 100; u <= 200; u++)
    {
        if(u%2 == 0)
        {
            y=y+u;
        }
    }
    cout << y << endl;
    cout << "Y la cantidad de numeros pares del 100 al 200 son:" << endl;
    par(u, c);
    
    return 0;
}