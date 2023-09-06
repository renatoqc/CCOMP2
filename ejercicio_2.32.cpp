#include<iostream>
using namespace std;

int main()
{

    int tam;
    cout << "Ingrese el número de personas a calificar\n";
    cin >> tam;
    for (int i = 1; i <= tam; i++) {

        int edad;
        cout << "Ingrese su edad: ";
        cin >> edad;
        cout << " " << endl;

        int MHR = 220 - edad;
        int MHR1 = 208 - 0.7 * edad;
        int MHR1_2 = 207 - 0.7 * edad;
        int MHR1_3 = 211 - 0.64 * edad;

        cout << "Segun la formula base tu MHR es: " << MHR << endl;
        cout << "Segun TANAKA tu MHR es: " << MHR1 << endl;
        cout << "Segun GELLISH tu MHR es: " << MHR1_2 << endl;
        cout << "Segun NEST ET tu MHR es: " << MHR1_3 << endl;

        int menor;
        int mayor;

        menor = MHR;
        mayor = MHR;
        if (MHR1 > mayor) {
            mayor = MHR1;
        }
        else if (MHR1 < menor) {
            menor = MHR1;
        }
        if (MHR1_2 > mayor) {
            mayor = MHR1_2;
        }
        else if (MHR1_2 < menor) {
            menor = MHR1_2;
        }
        if (MHR1_3 > mayor) {
            mayor = MHR1_3;
        }
        else if (MHR1_3 < menor) {
            menor = MHR1_3;
        }
        cout << " " << endl;
        cout << "El MHR menor es: " << menor << endl;
        cout << "El MHR mayor es: " << mayor << endl;
    }
    return 0;
}