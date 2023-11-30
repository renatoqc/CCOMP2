#include <iostream>
#include <string>
#include <vector> 

using namespace std;

// Definimos una estructura para almacenar estadisticas
struct Estadisticas {
    int fuerza;
    int agilidad;
    int inteligencia;
};

class Heroe {
private:
    string nombre;
    string historia;
    Estadisticas estadisticas;
    vector<string> habilidades;

public:
    Heroe(string nombre, string historia, Estadisticas estadisticas) 
    :nombre(nombre), historia(historia), estadisticas(estadisticas) {
    }

    virtual string obtenerTipo() const {
        return "Desconocido";
    }

    string obtenerNombre() const {
        return nombre;
    }

    Estadisticas obtenerEstadisticas() const {
        return estadisticas;
    }

    vector<string> obtenerHabilidades() const {
        return habilidades;
    }

    string obtenerBiografia() const {
        return historia;
    }

    // Método para agregar una habilidad al héroe
    void agregarHabilidad(string habilidad) {
        habilidades.push_back(habilidad);
    }
};

class Fuerza : public Heroe {
public:
    Fuerza(string nombre, string historia, Estadisticas estadisticas)
        : Heroe(nombre, historia, estadisticas) {
    }

    string obtenerTipo() const override {
        return "Fuerza";
    }
};
class Universal : public Heroe {
public:
    Universal(string nombre, string historia, Estadisticas estadisticas)
        : Heroe(nombre, historia, estadisticas) {
    }

    string obtenerTipo() const override {
        return "Universal";
    }
};



class Inteligencia : public Heroe {
public:
    Inteligencia(string nombre, string historia, Estadisticas estadisticas)
        : Heroe(nombre, historia, estadisticas) {
    }

    string obtenerTipo() const override {
        return "Inteligencia";
    }
};

class Creep : public Heroe {
public:
    Creep(string nombre, string historia, Estadisticas estadisticas)
        : Heroe(nombre, historia, estadisticas) {
    }

    string obtenerTipo() const override {
        return "Creep";
    }
};

class Agilidad : public Heroe {
public:
    Agilidad(string nombre, string historia, Estadisticas estadisticas)
        : Heroe(nombre, historia, estadisticas) {
    }

    string obtenerTipo() const override {
        return "Agilidad";
    }
};

