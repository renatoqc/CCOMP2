#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

int sumar(const int array[], const int tam){
    long sum = 0;
    for(int i = 0; i < tam; sum += array[i++]);
    return sum;

}

void imprimir(const int arr[], const int tam){
    cout << "Los elementos del arreglo son: {";
    for(int i = 0; i < tam; i++){
        cout <<" "<< arr[i];
    }
    cout << " }"<< endl;
}

void imprimirRe(const int arr[], const int tam, int i = 0){
    if(tam == 0)
        return;
    cout << arr[i] <<" ";
    imprimirRe(arr, tam, ++i);
}

    

int main(){
    const int tam = 4;
    int arr[tam] = {5,8,10,27};

    cout << "La suma es: " << sumar(arr, tam) << endl;
}