#include <iostream>
using namespace std;

int main(){
    int arr[] = {1,23,4,5,2,44,345,6,7,};
    int tam = sizeof(arr) / sizeof(arr[0]);

    cout << tam << endl;
    
    cout << *arr << endl;
    cout << &arr[0] << endl;  

    cout <<endl;
    cout << " "<< endl;

    int *ptr = arr;

    cout <<"FORMA CORTA: "<< endl;
    for(int i = 0; i < tam; i++){
        cout << *(ptr + i)<< " ";
    }
    cout <<endl;
    cout << " "<< endl;

    cout << "FORMA LARGA: "<< endl;
    cout << *(ptr + 0) <<" ";
    cout << *(ptr + 1) <<" ";
    cout << *(ptr + 2) <<" ";
    cout << *(ptr + 3) <<" ";
    cout << *(ptr + 4) <<" ";
    cout << *(ptr + 5) <<" ";
    cout << *(ptr + 6) <<" ";
    cout << *(ptr + tam -1) <<endl;

}