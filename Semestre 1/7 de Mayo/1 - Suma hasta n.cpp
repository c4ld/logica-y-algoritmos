#include <iostream>

int main() {
    int n, suma;
    
    std::cout << "Ingrese el valor de n: ";
    std::cin >> n;
    
    for(int i = 1; i <= n; ++i) {
        std::cout << i << std::endl;
        suma += i;
    }
    
    std::cout << "La suma de los numeros naturales del 1 hasta " << n << " es: " << suma << std::endl;
    
    return 0;
}
