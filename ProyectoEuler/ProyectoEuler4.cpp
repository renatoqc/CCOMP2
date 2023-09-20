#include <iostream>

using namespace std;

/*Encuentra el palíndromo más grande hecho del producto de dos 3-números de dígitos.*/

bool esPalindromo(int n) {
    int original = n;
    int reverso = 0;

    while (n > 0) {
        int digito = n % 10;
        reverso = reverso * 10 + digito;
        n /= 10;
    }

    return original == reverso;
}

int main() {
    int maxPalindromo = 0;

    for (int i = 100; i <= 999; i++) {
        for (int j = 100; j <= 999; j++) {
            int producto = i * j;
            if (esPalindromo(producto) && producto > maxPalindromo) {
                maxPalindromo = producto;
            }
        }
    }

    cout << "El pal�ndromo m�s grande hecho del producto de dos n�meros de 3 d�gitos es: " << maxPalindromo << endl;

    return 0;
}