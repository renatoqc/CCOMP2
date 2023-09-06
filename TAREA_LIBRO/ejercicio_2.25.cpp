#include <iostream>
using namespace std;

int main() {

    int x, z;

    cout << "Ingrese un numero para x: " << endl;
    cin >> x;

    cout << "Ingrese un numero para z: " << endl;
    cin >> z;

    if (x % 2 == 0) {
        cout << "X es par." << endl;
    }
    else
    {
        cout << "X es impar." << endl;
    }

    if (z % 2 == 0) {
        cout << "Z es par." << endl;
    }
    else
    {
        cout << "Z es impar." << endl;
    }

    return 0;
}