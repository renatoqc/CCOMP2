#include <iostream>
#include "Factura.h"
#include <string>

using namespace std;

int main() {

    Factura persona1{ "tres","grande", 2, 20, 0.20, 10 };
    persona1.display();

    cout << "" << endl;

    double papel = persona1.getnvoiceAmount();
    cout << "El total de la compra es: " << papel;

    return 0;
}
