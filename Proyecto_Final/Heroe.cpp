#include "Heroe.h"
#include "DotaDex.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void crearHeroes(std::vector<Heroe*>& heroes){
   
    //UNIVERSAL
    Estadisticas estadisticasHeroe1 = { 21, 19, 24 };
    string historiaHeroe1 =
        "Conocedor de secretos que destrozarían una mente mortal, Void Spirit "
        "emerge de su Templo Oculto \t\t\t"
        "\t     para vigilar al mismo tiempo las distintas áreas del campo de "
        "batalla.";
    Universal heroe1("Void Spirit", historiaHeroe1, estadisticasHeroe1);
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
    Universal heroe4("Invoker", historiaHeroe4, estadisticasHeroe4);
    heroe4.agregarHabilidad("Quas");
    heroe4.agregarHabilidad("Wex");
    heroe4.agregarHabilidad("Exort");
    heroe4.agregarHabilidad("Invocar");
    heroes.push_back(&heroe4);


    //FUERZA
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

    Estadisticas estadisticasHeroe7 = { 22, 17, 14 };
    string historiaHeroe7 = "Cuando se trata de una pelea, Bristleback  "
        "realmente se pone de espaldas a ella.";
    Fuerza heroe7("Bristeleback", historiaHeroe7, estadisticasHeroe7);
    heroe7.agregarHabilidad("Viscosidad Nasal");
    heroe7.agregarHabilidad("Lluvia de Espinas");
    heroe7.agregarHabilidad("Espalda Espinosa");
    heroe7.agregarHabilidad("Senda de Guerra");
    heroes.push_back(&heroe7);

    Estadisticas estadisticasHeroe8 = { 22, 12, 18 };
    string historiaHeroe8 = "Ya esa impidiendo la fuga de enemigos, dividiendo sus fuerzas  "
        " o rompiendo la tierra debajo de sus adversarios.";
    Fuerza heroe8("Earthshaker", historiaHeroe8, estadisticasHeroe8);
    heroe8.agregarHabilidad("Fisura");
    heroe8.agregarHabilidad("Encantar Totem");
    heroe8.agregarHabilidad("Replica");
    heroe8.agregarHabilidad("Golpe Resonante");
    heroes.push_back(&heroe8);


    //AGILIDAD
    Estadisticas estadisticasHeroe9 = { 22, 20, 24 };
    string historiaHeroe9 = "Fragmento astillado del mismo poder primordial que los "
        " mismisimos Ancestros.";
    Agilidad heroe9("Arc Warden", historiaHeroe9, estadisticasHeroe9);
    heroe9.agregarHabilidad("Flujo");
    heroe9.agregarHabilidad("Campo Magnetico");
    heroe9.agregarHabilidad("Espectro Centelleante");
    heroe9.agregarHabilidad("Duplicado de la Tempestad");
    heroes.push_back(&heroe9);

    Estadisticas estadisticasHeroe10 = { 19, 21, 15 };
    string historiaHeroe10 = "En el momento en que se encuentra a su presa, Phantom golpea "
        "acercandose al obejtivo y esquiva los ataques del rival.";
    Agilidad heroe10("Phantom Assassin", historiaHeroe10, estadisticasHeroe10);
    heroe10.agregarHabilidad("Daga Sofocante");
    heroe10.agregarHabilidad("Golpe Fantasmal");
    heroe10.agregarHabilidad("Desvanecer");
    heroe10.agregarHabilidad("Golpe de Gracia");
    heroes.push_back(&heroe10);

    Estadisticas estadisticasHeroe11 = { 25, 18, 16 };
    string historiaHeroe11 = "Con cada golpe de sus garras, Ursa aumenta la "
        "vulnerabilidad de su objetivo para el proximo ataque.";
    Agilidad heroe11("Ursa", historiaHeroe11, estadisticasHeroe11);
    heroe11.agregarHabilidad("Sacudida");
    heroe11.agregarHabilidad("Abrumar");
    heroe11.agregarHabilidad("Arañaso Furioso");
    heroe11.agregarHabilidad("Enfurecer");
    heroes.push_back(&heroe11);

    Estadisticas estadisticasHeroe12 = { 24, 17, 18 };
    string historiaHeroe12 = "Capaz de invocar hasta cinco copias ed si mismo,  "
        "Meepo puede luchar en todos los frentes a la vez.";
    Agilidad heroe12("Meepo", historiaHeroe12, estadisticasHeroe12);
    heroe12.agregarHabilidad("Ataduras Terrenales");
    heroe12.agregarHabilidad("¡Puf!");
    heroe12.agregarHabilidad("Desvalijar");
    heroe12.agregarHabilidad("Divide y Venceras");
    heroes.push_back(&heroe12);

    //INTELIGENCIA

    Estadisticas estadisticasHeroe13 = { 19, 17, 30 };
    string historiaHeroe13 = "Tinker destruye s sus enemigos con una bateria "
        "de dispositivos mortiferos.";
    Inteligencia heroe13("Tinker", historiaHeroe13, estadisticasHeroe13);
    heroe13.agregarHabilidad("Laser");
    heroe13.agregarHabilidad("Misil Infrarrojo");
    heroe13.agregarHabilidad("Matriz de Defensa");
    heroe13.agregarHabilidad("Rearmar y Transporte Ingenioso");
    heroes.push_back(&heroe13);

    Estadisticas estadisticasHeroe14 = { 19, 11, 22 };
    string historiaHeroe14 = "Nadie peude esconderse de Zeus, ya esa con uno de  "
        "relampagos o invocando descar de rayos \n contra todos los oponentes.";
    Inteligencia heroe14("Zeus", historiaHeroe14, estadisticasHeroe14);
    heroe14.agregarHabilidad("Arco Electrico");
    heroe14.agregarHabilidad("Relampago");
    heroe14.agregarHabilidad("Salto Celestial");
    heroe14.agregarHabilidad("Ira del Dios del Trueno");
    heroes.push_back(&heroe14);

    Estadisticas estadisticasHeroe15 = { 19, 20, 24 };
    string historiaHeroe15 = "Muerta es una maestra de la muerte que acecha las tierras "
        "de los vivos, acorralando objetivos con temibles disparos.";
    Inteligencia heroe15("Muerta", historiaHeroe15, estadisticasHeroe15);
    heroe15.agregarHabilidad("Disparo Mortal");
    heroe15.agregarHabilidad("La Invocacion");
    heroe15.agregarHabilidad("Pistolera");
    heroe15.agregarHabilidad("Atravesar el Velo");
    heroes.push_back(&heroe15);

    Estadisticas estadisticasHeroe16 = { 17, 22, 23 };
    string historiaHeroe16 = "Puck tiene un talento innato para confundir a sus enemigos "
        "con su elusiva picardia juguetona.";
    Inteligencia heroe16("Puck", historiaHeroe16, estadisticasHeroe16);
    heroe16.agregarHabilidad("Orbe Ilusorio");
    heroe16.agregarHabilidad("Escision Fluctuante");
    heroe16.agregarHabilidad("Cambio de Fase");
    heroe16.agregarHabilidad("Espiral de Suenos");
    heroes.push_back(&heroe16);
}

void liberarHeroes(std::vector<Heroe*>& heroes) {
    for (Heroe* heroe : heroes) {
        delete heroe;
    }
}

int main() {

    fstream archivo("Heroes.txt", ios::out | ios::in);
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

        int opcion;
        vector<Heroe*> heroes;

        while (true) {
            // Mostrar el menú
            std::cout << "Menú de opciones:" << std::endl;
            std::cout << "1. Heroes" << std::endl;
            std::cout << "2. MapayRunas" << std::endl;
            std::cout << "3. Itmes" << std::endl;
            std::cout << "4. Salir" << std::endl;
            std::cout << "Ingrese el número de la opción: ";

            // Leer la opción del usuario
            std::cin >> opcion;

            // Realizar acciones basadas en la opción seleccionada
            switch (opcion) {
            case 1:
                std::cout << "Has seleccionado la Opción 1 (Heroes)." << std::endl;
                crearHeroes(heroes);
                cout << endl;
                for (const Heroe* heroe : heroes) {
                    cout << "NOMBRE DEL HEROE   : " << heroe->obtenerNombre() << endl;
                    cout << "TIPO DEL HEROE     : " << heroe->obtenerTipo() << endl;
                    cout << "BIOGRAFIA DEL HEROE: " << heroe->obtenerBiografia() << endl;
                    cout << endl;

                    Estadisticas estadisticas = heroe->obtenerEstadisticas();
                    cout << "ESTADISTICAS DEL HEROE:" << endl;
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
                break;
            case 2:
                std::cout << "Has seleccionado la Opción 2." << std::endl;
                // Realiza la acción asociada a la Opción 2
                break;
            case 3:
                std::cout << "Has seleccionado la Opción 3." << std::endl;
                // Realiza la acción asociada a la Opción 3
                break;
            case 4:
                std::cout << "Saliendo del programa." << std::endl;
                return 0; // Sal del programa
            default:
                std::cout << "Opción no válida. Por favor, elija una opción válida." << std::endl;
                break;
            }
        }
                 

    // Mostrar información de todos los héroes
    

    return 0;
        
}
