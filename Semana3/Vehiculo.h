#pragma once
#include <iostream>
#include <string>

using namespace std;

class MotorVehicle
{
private:

    string make;
    string fueltype;
    int year;
    string color;
    int capacidad;

public:
    MotorVehicle(string make_, string fueltype_, int year_, string color_, int capacidad_) {
        make = make_;
        fueltype = fueltype_;
        year = year_;
        color = color_;
        capacidad = capacidad_;
    }

    void setMake(string make_) {
        make = make_;
    }
    void setFuel(string fueltype_) {
        fueltype = fueltype_;
    }
    void setYearr(int year_) {
        year = year_;
    }
    void setCol(string color_) {
        color = color_;
    }
    void setCap(int capacidad_) {
        capacidad = capacidad_;
    }

    string getMake() {
        return make;
    }
    string getFuel() {
        return fueltype;
    }
    int getYearr() {
        return year;
    }
    string getCol() {
        return color;
    }
    int getCap() {
        return capacidad;
    }

    void getdisplayCarDetails() {

        cout << " ------------------------------" << endl;
        cout << "| FORMULARIO SOBRE SU VEHICULO |" << endl;
        cout << " ------------------------------" << endl;
        cout << "" << endl;
        cout << "Marca: " << getMake() << endl;
        cout << "Tipo de gasolina: " << getFuel() << endl;
        cout << "Año: " << getYearr() << endl;
        cout << "Color: " << getCol() << endl;
        cout << "Capacidad del motor: " << getCap() << endl;

    }


};
