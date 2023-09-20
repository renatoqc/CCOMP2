#include <iostream>
using namespace std;

/*Encuentra la diferencia entre la suma de los cuadrados de los primeros cien números naturales y el cuadrado de la suma.*/

int main() {
    unsigned long long x;
    unsigned long long suma1 = 0;
    unsigned long long suma2 = 0;
    unsigned long long sumafinal1 = 0;
    cout << "Ingrese el n�mero de veces que se sumar�n : ";
    cin >> x;
    for (unsigned long long i = 1; i <= x; i++) {
        suma1 += i;
        suma2 = (suma2 + (i * i));
    }
    sumafinal1 = suma1 * suma1;
    cout << (sumafinal1 - suma2) << endl;

    return 0;
}