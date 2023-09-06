#include <iostream>
using namespace std;

int main() {

    int num1, num2, num3, num4, num5;
    cout << "Ingrese 5 n�meros enteros: ";
    cin >> num1 >> num2 >> num3 >> num4 >> num5;

    int menor;
    int mayor;

    mayor = num1;
    menor = num1;
    if (num2 > mayor) {
        mayor = num2;
    }
    else if (num2 < menor) {
        menor = num2;
    }
    if (num3 > mayor) {
        mayor = num3;
    }
    else if (num3 < menor) {
        menor = num3;
    }
    if (num4 > mayor) {
        mayor = num4;
    }
    else if (num4 < menor) {
        menor = num4;
    }
    if (num5 > mayor) {
        mayor = num5;
    }
    else if (num5 < menor) {
        menor = num5;
    }
    cout << "El numero mayor es " << mayor << endl;
    cout << "El numero menor es " << menor << endl;

    return 0;
}