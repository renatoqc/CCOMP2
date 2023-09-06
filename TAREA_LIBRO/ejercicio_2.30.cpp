#include <iostream>
using namespace std;

int main() {

    float peso, altura;

    cout << "Introduzca su Peso: " << endl;
    cin >> peso;
    cout << "Introduzca su Altura: " << endl;
    cin >> altura;

    float imc = peso / (altura * altura);

    cout << "Tu imc es: " << imc << endl;

    cout << "VALORES DE IMC" << endl;
    cout << "Bajo peso: " << "Menos de 18.5" << endl;
    cout << "Normal: " << "Entre 18,5 y 24,9" << endl;
    cout << "Exceso de pe: " << "Entre 25 y 29,9" << endl;
    cout << "Obesidad: " << "30 o más" << endl;

    return 0;
}