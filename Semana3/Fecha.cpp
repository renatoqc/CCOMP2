#include <iostream>
#include "Fecha.h"

using namespace std;

int main() {

	cout << "Ingrese el dia que estamos hoy: ";
	int day_;
	cin >> day_;

	cout << "Ingrese que mes estamos: ";
	int month_;
	cin >> month_;

	cout << "Ingrese en que ano estamos: ";
	int year_;
	cin >> year_;

	Date f{ month_, day_, year_ };
	f.getdisplayDate();

	return 0;
}
