//Clase principal de todo el programa.)
#ifndef DOTADEX_H
#define DOTADEX_H

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "HeroeA.h"
#include "JugadorA.h"


class Dotadex {
public:
    void addHeroe(const Heroe& heroe) {
        heroes.push_back(heroe);
    }

    void showHeroes() {
        std::cout << "Lista de Heroes en Dotadex:" << std::endl;
        for ( Heroe& heroe : heroes) {
            heroe.showInfo();
        }
    }

private:
    std::vector<Heroe> heroes;
};

#endif