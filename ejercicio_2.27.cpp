#include <iostream>
using namespace std;

int main() {

    char var;

    cout << "Ingrense un car�cter: ";
    cin >> var;

    cout << static_cast<int>(var);

    return 0;
}