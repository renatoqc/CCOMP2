#include <iostream>
using namespace std;

int main() {

    double millas, costo_galon, millas_galon, peajes, tarifa_estacionamiento, dia;
    costo_galon = 23;
    millas_galon = 40 * costo_galon;
    tarifa_estacionamiento = 5 * 3;
    peajes = 1 * 2;

    cout << "Ingrese cuantas millas recorrio hoy: ";
    cin >> millas;

    cout << "El costo por galon de gasolina: " << costo_galon << endl;
    cout << "Millas promedio por galon: " << millas_galon << endl;
    cout << "Tarifa de estacionamiento: " << tarifa_estacionamiento << endl;
    cout << "En peajes: " << peajes << endl;

    return 0;
}