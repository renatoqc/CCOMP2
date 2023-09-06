#include <iostream>
using namespace std;


int main()
{
    int radio, diametro, circun, area;
    float pi = 3.14159;

    cout << "Ingrese un numero: ";
    cin >> radio;

    diametro = radio * 2;
    circun = pi * diametro;
    area = pi * (radio * radio);

    cout << "El radio es: " << radio << endl;
    cout << "El diametro es: " << diametro << endl;
    cout << "La circunferencia es: " << circun << endl;
    cout << "El area es: " << area << endl;

    return 0;
}
