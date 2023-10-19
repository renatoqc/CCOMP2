#include <iostream>
using namespace std;

int main(){
    int x = 10;
    int *ptr = &x;
    *ptr = 100;
    cout << *ptr << endl;

    return 0;
}