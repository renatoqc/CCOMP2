#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Array.h"
using namespace std;

//constructor default para la clase Array
Array::Array(int arraySize)
    :size{(arraySize > 0 ? static_cast<size_t>(arraySize):
        throw invalid_argument{"Array size must be greater than 0"})},
    ptr{new int[size]{}} {}


//constructor copia para la clase Array
Array::Array(const Array& arrayToCopy)
    : size{arrayToCopy.size}, ptr{new int[size]}{
        for (size_t i{0}; i < size; ++i){
            ptr[i] = arrayToCopy.ptr[i];
        }
    }

//destrucotr de la calse array
Array::~Array(){
    delete[] ptr;
}

//retorna el numero de elemnetos de Array
size_t Array::getSize() const{
    return size;
}

//sobrecarga del operador de asignacion
const Array& Array::operator=(const Array& right){
    if(&right != this){
        if(size != right.size){
            delete[]ptr;
            size = right.size;
            ptr = new int[size];
        }

        for(size_t i{0}; i < size; ++i){
            ptr[i] = right.ptr[i];
        }
    }

    return *this;
}


//determina si los 2 arrays son iguales y retorna verdadero
bool Array::operator==(const Array& right) const{
    if(size  != right.size){
        return false;
    }

    for (size_t i{0}; i < size; ++i){
        if (ptr[i] != right.ptr[i]){
            return false;
        }
    }
}

//ga
int& Array::operator[](int subscript) {
// check for subscript out-of-range error
    if (subscript < 0 || subscript >= size) {
        throw out_of_range{"Subscript out of range"};
    }
    return ptr[subscript];
}


int Array::operator[](int subscript) const {
    // check for subscript out-of-range error
    if (subscript < 0 || subscript >= size) {
        throw out_of_range{"Subscript out of range"};
    }
    return ptr[subscript]; // returns copy of this element
}


istream& operator>>(istream& input, Array& a) {
    for (size_t i{0}; i < a.size; ++i) {
        input >> a.ptr[i];
    }
    return input; // enables cin >> x >> y;
} 

ostream& operator<<(ostream& output, const Array& a) {
// output private ptr-based array
    for (size_t i{0}; i < a.size; ++i) {
        output << a.ptr[i] << " ";
    }
    output << endl;
    return output; // enables cout << x << y;
}