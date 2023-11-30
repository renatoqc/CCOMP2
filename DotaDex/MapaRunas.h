#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Runa {
private:
    std::string nombre;
    std::string tipo;

public:
    Runa(const std::string& nombre, const std::string& tipo) : nombre(nombre), tipo(tipo) {}

    std::string getNombre() const {
        return nombre;
    }

    std::string getTipo() const {
        return tipo;
    }
};

class MapaDota2 {
private:
    std::string nombre;
    std::vector<Runa> runas;

public:
    MapaDota2(const std::string& nombre) : nombre(nombre) {}

    void agregarRuna(const std::string& nombre, const std::string& tipo) {
        Runa runa(nombre, tipo);
        runas.push_back(runa);
    }

    void listarRunas() const {
        std::cout << "Runas en el mapa de Dota 2 '" << nombre << "':" << std::endl;
        for (const Runa& runa : runas) {
            std::cout << "Nombre: " << runa.getNombre() << ", Tipo: " << runa.getTipo() << std::endl;
        }
    }
};
