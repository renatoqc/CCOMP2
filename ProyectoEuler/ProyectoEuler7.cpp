#include <iostream>
using namespace std;

bool esPrimo(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 0;
    int contador = 0;
    while (contador < 10001) {
        n++;
        if (esPrimo(n)) {
            contador++;
        }
    }
    cout << "El número primo 10 001 es: " << n << endl;
    return 0;
}