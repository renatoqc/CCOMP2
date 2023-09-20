#include <iostream>

using namespace std;

/*¿Cuál es el mayor factor primo del número?*/

int main() {
    long long x;
    x = 600851475143;
    int div;
    div = 2;
    while ((div * div) < x) {
        if ((x % div) == 0) {
            x /= div;
            continue;
        }
        div++;

    }
    cout << x;


    return 0;
}