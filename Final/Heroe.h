#include <iostream>
#include <string>
#include <vector> 

using namespace std;

// Definimos una estructura para almacenar estad�sticas
struct Estadisticas {
    int fuerza;
    int agilidad;
    int inteligencia;
};

class Heroe {
private:
    string nombre;
    string tipo;
    string historia;
    Estadisticas estadisticas;
    vector<string> habilidades;

public:
    
    Heroe(string nombre, string tipo, string historia, Estadisticas estadisticas) {
        this->nombre = nombre;
        this->tipo = tipo;
        this->historia = historia;
        this->estadisticas = estadisticas;
    }

    
    string obtenerNombre() const {
        return nombre;
    }

    string obtenerTipo() const {
        return tipo;
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

    // M�todo para agregar una habilidad al h�roe
    void agregarHabilidad(string habilidad) {
        habilidades.push_back(habilidad);
    }
};

