#include <iostream>
using namespace std;

int main () {
    int n1, n2, n3;
      cout << "Ingrese tres enteros: ";
    cin >> n1 >> n2 >> n3;
        if (n3 % n1 == 0 && n3 % n2 == 0) {
    cout << n1 << " y " << n2 << " son factores de " << n3 << endl;
  } else {
    cout << n1 << " y " << n2 << " no son factores de " << n3 << endl;
  }

    return 0;
}