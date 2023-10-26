#ifndef _GEOMETRICVECTOR.H_
#define _GEOMETRICVECTOR.H_

#include <iostream>
#include "Point.h"
#include <cmath>

class Geometricvector{
    private:
    Point start;
    Point end;

    public:
    Geometricvector(Point start, Point end){
        this->start = start;
        this->end = end;
    }
    ~Geometricvector(){
        std::cout << "GEOMETRICVECTOR: Invocando al destructor" << std::endl;
    }

    double modulo() const {
        return sqrt(pow((end.getX() - start.getX()), 2)) + 
                    pow((end.getY() - start.getY()), 2);
    }

    void setStart(Point start){
        this->start = start;
    }

    void setEnd(Point end){
        this->end = end;
    }

    Point getStart() const{
        return start;
    }

    Point getEnd() const{
        return end;
    }
};

#endif