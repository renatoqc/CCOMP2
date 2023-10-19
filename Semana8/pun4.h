#include <iostream>
using namespace std;

class Punto{
    private:
        int x,y;
    public:
    void setx(int _x){
        x = _x;
    }
    void sety(int _y){
        y =_y;
    }
    void print()const{
        cout << "{ " << x << ", " << y << " }" << endl; 
    }
};