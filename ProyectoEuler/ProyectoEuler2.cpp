#include <iostream>

using namespace std;

int main() {
    int n1 = 1, n2 = 2, fib = 0, suma = 0;

    while (n2 <= 4000000) {
        if (n2 % 2 == 0) {
            suma += n2;
        }
        fib = n1 + n2;
        n1 = n2;
        n2 = fib;
    }

    cout << suma << endl;

    return 0;
}