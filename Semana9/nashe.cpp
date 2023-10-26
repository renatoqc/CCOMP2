#include <iostream>
#include "geometricVector.h"
#include "Point.h"

using namespace std;

int main(){
    cout << "Main terminado"<< endl;

    Point a1(1,4);
    Point a2(3,7);

    Geometricvector vec(a1, a2);
    cout << vec.modulo() << endl;

    return 0;
}