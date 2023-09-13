#pragma once
#include <iostream>
#include <string>

using namespace std;

class Factura {

private:

    string NumPieza, descrip;
    int cantiCompra, precio;
    double impuesto, descuento;

public:

    Factura(string Numpieza_, string descrip_, int cantiCompra_, int precio_, double impuesto_, double descuento_)
        :NumPieza{ Numpieza_ }, descrip{ descrip_ }, cantiCompra{ cantiCompra_ }, precio{ precio_ }, impuesto{ impuesto_ }, descuento{ descuento_ } {}

    void setNum(string Numpieza_) {
        NumPieza = Numpieza_;
    }
    void setDescri(string descrip_) {
        descrip = descrip_;
    }
    void setCanco(int cantiCompra_) {
        cantiCompra = cantiCompra_;
    }
    void setPre(int precio_) {
        precio = precio_;
    }
    void setImpu(double impuesto_) {
        impuesto = impuesto_;
    }
    void setDsc(double descuento_) {
        descuento = descuento_;
    }

    string getNumPieza() {
        return NumPieza;
    }
    string getDescri() {
        return descrip;
    }
    int getCanco() {
        return cantiCompra;
    }
    int getPrecio() {
        return precio;
    }
    double getDsc() {
        return descuento;
    }
    double getImpuesto() {
        return impuesto;
    }

    double getnvoiceAmount() {
        double recibo = (cantiCompra * precio) + impuesto;
        recibo = recibo - (descuento / 100);
        recibo -= (descuento / 100);
        return recibo;
    }

    void display() {
        cout << "La persona1: " << getNumPieza() << endl;
        cout << "Descripcion: " << getDescri() << endl;
        cout << "Cnatidad de objetos: " << getCanco() << endl;
        cout << "Costo:  " << getPrecio() << endl;
        cout << "Impuesto: " << getImpuesto() << endl;
        cout << "Descuento: " << getDsc() << endl;
    }
};
