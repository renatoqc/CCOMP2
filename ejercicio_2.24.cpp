#include <iostream>
using namespace std;

int main() {

    int x, z, suma;

    cout << "Ingrese un numero para x: " << endl;
    cin >> x;

    cout << "Ingrese un numero para z: " << endl;
    cin >> z;

    suma = x + z;

    if (suma % 2 == 0) {
        cout << "La suma es par." << endl;
    }
    else
    {
        cout << "La suma es impar.";
    }

    return 0;
}
