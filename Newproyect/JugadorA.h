#ifndef JUGADORA_H
#define JUGADORA_H


#include <iostream>
#include <string>
#include <vector>
#include <ctime>


class Jugador {
public:
    Jugador(const std::string& name) : name(name) {
        generateRandomID();
    }

    void showInfo() {
        std::cout << "Jugador: " << name << " (ID: " << playerID << ")" << std::endl;
    }

private:
    std::string name;
    int playerID;

    void generateRandomID() {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        playerID = rand() % 900000 + 100000;
    }
};

#endif