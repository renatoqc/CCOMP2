#include <iostream>
using namespace std;

/*Cuál es el número positivo más pequeño que es*/

int main() {
    int multiploPeque = 40;
    int i = 10;

    while (i < 20) {
        if (multiploPeque % i == 0) {
            i++;
            
        }
        else {
            i = 10;
            multiploPeque += 20;
        }
    }
    cout << multiploPeque;
}