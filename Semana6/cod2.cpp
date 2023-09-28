#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

void imprimir(const int arr[], const int tam){
    cout << "Los elementos del arreglo son: {";
    for(int i = 0; i < tam; i++){
        cout <<" "<< arr[i];
    }
    cout << " }"<< endl;
}

void imprimirRe(int arr[], const int tam, int i = 0){
    if(tam == 0)
        return;
    cout << arr[i] <<" ";
    imprimirRe(arr, tam, ++i);
}

void invertir(int arr[], const int tam){
    for(int i = 0; i < tam/2; i++){
        int tmp = arr[i];
        arr[i] = arr[tam - i - 1];
        arr[tam - i - 1] = tmp;
    }
}

void cambio(int &a, int &b){
    int tmp = a;
    a =b;
    b = tmp;
}

void inver(int arr[], const int tam){
    for(int i = 0; i < tam/2; i++){
        cambio(arr[i], arr[tam-i-1]);
    }
}

void inverRec(int arr[], const int tam, int i = 0){
    if(i > tam/2)
        return;
    cambio (arr[i], arr[tam-i-1]);
    inverRec(arr, tam, i + 1);
}

int main(){
    const int tam = 5;
    int arr[tam] = {5,8,10,27,30};

    imprimir(arr, tam);

    cout << "El arreglo invertido es: ";
    invertir(arr, tam);
    imprimir(arr, tam);

}