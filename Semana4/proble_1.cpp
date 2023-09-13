#include <iostream>
using namespace std;

int main(){

    int numero, primo;

    cout << "Ingrese un numero: ";
    cin >> numero;

    if (numero % numero == 0 && numero % 1 == 00){

        cout << "El numero es primo." << endl;
    }else{
        cout <<  "El numero no es primo.";
    }
    
    /*
    while (primo < numero)
    {
        cout << primo;

        break;
    }
    */
    
    return 0;
}