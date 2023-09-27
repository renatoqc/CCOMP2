#include <iostream>
using namespace std;

int main(){
    int arr[4];
    cout << "Ingrese 4 valores enteros: " << endl;
    for(int i = 0; i < 4; i++ ){
        cin >> arr[i];
    }

    cout << "Los valores del arreglo son: "<< endl;
    for(int i = 0; i < 4; i++ ){
        cout << " " << arr[i];
    }

    cout << endl;
}