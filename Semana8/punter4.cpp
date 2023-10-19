#include <iostream>
#include "pun4.h"
using namespace std;

int main(){
    
    Punto p;
    p.setx(10);
    p.sety(20);
    p.print();

    Punto *ptr = &p;

    ptr->setx(40);
    ptr->sety(100);

    ptr->print();



    return 0;
}        