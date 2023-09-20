#include <iostream>

using namespace std;

/*Encuentra la suma de todos los números primos menores de dos millones.*/


bool primo(int n) {
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
    int n = 2000000;
    long long sum = 0;

    for (int i = 2; i < n; i++) {
        if (primo(i)) {
            sum += i;
        }
    }

    cout << sum << endl;

    return 0;
}