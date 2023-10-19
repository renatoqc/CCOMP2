#include "Heroe.h"
#include "DotaDex.h"
#include <iostream>
#include <vector>



using namespace std;

int main() {

    cout << "--------------------------------------------";
    cout << "|           DOTADEX           |";
    cout << "--------------------------------------------" << endl;
    // Parte de DotaDex
    string NombredeUsuario;    // Crear una instancia de DotaDex
    std::cout << "Ingrese su nombre de Usuario: ";
    std::cin >> NombredeUsuario;
        DotaDex dotaDex(NombredeUsuario);


        // Llamar a los métodos de DotaDex
        dotaDex.generarIdSteam();
        int idSteam = dotaDex.obtenerIdSteam();

        // Mostrar la información
        dotaDex.mostrarInformacion();

        cout << "--------------------------------------------";
        cout << "|           DOTADEX           |";
        cout << "--------------------------------------------";
        
        cout << endl;
        cout << endl;


        // Imprimir el ID de Steam
        //std::cout << "ID de Steam: " << idSteam << std::endl;

        
        

    // Crear varios héroes y almacenarlos en un vector
    vector<Heroe*> heroes;

    Estadisticas estadisticasHeroe1 = { 21, 19, 24 };
    string historiaHeroe1 =
        "Conocedor de secretos que destrozarían una mente mortal, Void Spirit "
        "emerge de su Templo Oculto \t\t\t"
        "\t     para vigilar al mismo tiempo las distintas áreas del campo de "
        "batalla.";
    Agilidad heroe1("Void Spirit", historiaHeroe1, estadisticasHeroe1);
    heroe1.agregarHabilidad("Remanente Etereo");
    heroe1.agregarHabilidad("Disimilar");
    heroe1.agregarHabilidad("Pulso Resonante");
    heroe1.agregarHabilidad("Paso Astral");
    heroes.push_back(&heroe1);

    Estadisticas estadisticasHeroe2 = { 23, 23, 23 };
    string historiaHeroe2 = "Bane lleva el terror a sus enemigos con su arsenal "
        "de habilidades incapacitantes.";
    Universal heroe2("Bane", historiaHeroe2, estadisticasHeroe2);
    heroe2.agregarHabilidad("Debilitar");
    heroe2.agregarHabilidad("Absorción Cerebral");
    heroe2.agregarHabilidad("Pesadilla");
    heroe2.agregarHabilidad("Garra del Diablo");
    heroes.push_back(&heroe2);

    Estadisticas estadisticasHeroe3 = { 17, 14, 23 };
    string historiaHeroe3 =
        "Io tiene el talento de hacer a sus aliados más efectivos.";
    Universal heroe3("Io", historiaHeroe3, estadisticasHeroe3);
    heroe3.agregarHabilidad("Vínculo");
    heroe3.agregarHabilidad("Espíritus");
    heroe3.agregarHabilidad("Sobrecarga");
    heroe3.agregarHabilidad("Reubicar");
    heroes.push_back(&heroe3);

    Estadisticas estadisticasHeroe4 = { 19, 14, 19 };
    string historiaHeroe4 = "Con un intrincado arsenal de hechizos a su "
        "disposición, Invoker puede adaptarse"
        "\n\t\t     a cualquier situación en la batalla.";
    Inteligencia heroe4("Invoker", historiaHeroe4, estadisticasHeroe4);
    heroe4.agregarHabilidad("Quas");
    heroe4.agregarHabilidad("Wex");
    heroe4.agregarHabilidad("Exort");
    heroe4.agregarHabilidad("Invocar");
    heroes.push_back(&heroe4);

    Estadisticas estadisticasHeroe5 = { 25, 14, 16 };
    string historiaHeroe5 = "Con cada gancho, su habilidad estrella, Pudge "
        "desata el miedo entre sus enemigos.";
    Fuerza heroe5("Pudge", historiaHeroe5, estadisticasHeroe5);
    heroe5.agregarHabilidad("Gancho de Carne");
    heroe5.agregarHabilidad("Pudrir");
    heroe5.agregarHabilidad("Montón de Carne");
    heroe5.agregarHabilidad("Descuartizar");
    heroes.push_back(&heroe5);

    Estadisticas estadisticasHeroe6 = { 23, 22, 25 };
    string historiaHeroe6 = "Sintetizando los recursos adicionales de cada una "
        "de las muertes, Alchemist no tiene"
        "\n\t\t     problema en reunir las herramientas "
        "necesarias para destruir a sus enemigos.";
    Fuerza heroe6("Alchemist", historiaHeroe6, estadisticasHeroe6);
    heroe6.agregarHabilidad("Ácido Pulverizado");
    heroe6.agregarHabilidad("Mezcla Inestable");
    heroe6.agregarHabilidad("Armamento Corrosivo");
    heroe6.agregarHabilidad("Furia Química");
    heroes.push_back(&heroe6);

    // Mostrar información de todos los héroes
    for (const Heroe* heroe : heroes) {
        cout << "NOMBRE DEL HEROE   : " << heroe->obtenerNombre() << endl;
        cout << "TIPO DEL HEROE     : " << heroe->obtenerTipo() << endl;
        cout << "BIOGRAFÍA DEL HEROE: " << heroe->obtenerBiografia() << endl;
        cout << endl;

        Estadisticas estadisticas = heroe->obtenerEstadisticas();
        cout << "ESTADÍSTICAS DEL HEROE:" << endl;
        cout << " - Fuerza: " << estadisticas.fuerza << endl;
        cout << " - Agilidad: " << estadisticas.agilidad << endl;
        cout << " - Inteligencia: " << estadisticas.inteligencia << endl;
        cout << endl;

        vector<string> habilidades = heroe->obtenerHabilidades();
        cout << "HABILIDADES DEL HEROE:" << endl;
        for (const string& habilidad : habilidades) {
            cout << " - " << habilidad << endl;
        }

        cout << "------------------------------------------------------------------"
            "--------------------------------------------"
            << endl; // Separador entre héroes
    }

    return 0;
}


