#ifndef DOTADEX_H
#define DOTADEX_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

class DotaDex {
private:
    std::string nombreUsuario;
    long long idSteam;

public:

    DotaDex();
    DotaDex(std::string nombreUsuario);

    // Método para generar un ID de Steam aleatorio
    void generarIdSteam();

    // Método para obtener el ID de Steam
    int obtenerIdSteam() const;

    // Método para mostrar información del usuario
    void mostrarInformacion() const;
};

DotaDex::DotaDex() : nombreUsuario(""), idSteam(0) {
    // Inicializar la semilla del generador de números aleatorios
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

DotaDex::DotaDex(std::string nombreUsuario) : nombreUsuario(nombreUsuario), idSteam(0) {
    // Inicializar la semilla del generador de números aleatorios
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void DotaDex::generarIdSteam() {
    // Generar un número aleatorio como ID de Steam
    idSteam = std::rand() % 10000000;
}

int DotaDex::obtenerIdSteam() const {
    return idSteam;
}

void DotaDex::mostrarInformacion() const {
    std::cout << "Nombre de Usuario: " << nombreUsuario << std::endl;
    std::cout << "ID de Steam: " << idSteam << std::endl;
}
#endif // DOTADEX_H
