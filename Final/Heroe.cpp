#include <iostream>
#include <vector>
#include "Heroe.h"
using namespace std;


int main() {
    // Crear varios h�roes y almacenarlos en un vector
    vector<Heroe> heroes;

    Estadisticas estadisticasHeroe1 = { 21, 19, 24 };
    string historiaHeroe1 = "Conocedor de secretos que destrozarian una mente mortal, Void Spirit emerge de su Templo Oculto \t\t\t" 
                            "\t     para vigilar al mismo tiempo las distintas areas del campo de batalla.";
    Heroe heroe1("Void Spirit", "Universal", historiaHeroe1, estadisticasHeroe1);
    heroe1.agregarHabilidad("Remanente Etereo");
    heroe1.agregarHabilidad("Disimilar");
    heroe1.agregarHabilidad("Pulso Resonante");
    heroe1.agregarHabilidad("Paso Astral");
    heroes.push_back(heroe1);

    
    Estadisticas estadisticasHeroe2 = { 23, 23, 23 };
    string historiaHeroe2 = "Bane lleva el terror a sus enemigos con su arsenal de habilidades incapacitantes.";
    Heroe heroe2("Bane", "Universal", historiaHeroe2, estadisticasHeroe2);
    heroe2.agregarHabilidad("Debilitar");
    heroe2.agregarHabilidad("Absorcion Cerebral");
    heroe2.agregarHabilidad("Pesadilla");
    heroe2.agregarHabilidad("Garra del Diablo");
    heroes.push_back(heroe2);
   
    
    Estadisticas estadisticasHeroe3 = { 17, 14, 23 };
    string historiaHeroe3 = "Io tiene el talento de hacer a sus aliados mas efectivos.";
    Heroe heroe3("Io", "Universal", historiaHeroe3, estadisticasHeroe3);
    heroe3.agregarHabilidad("Vinculo");
    heroe3.agregarHabilidad("Espiritus");
    heroe3.agregarHabilidad("Sobrecarga");
    heroe3.agregarHabilidad("Reubicar");
    heroes.push_back(heroe3);

    Estadisticas estadisticasHeroe4 = { 19, 14, 19 };
    string historiaHeroe4 = "Con un intrincado arsenal de hechizos a su disposicion, Invoker puede adaptarse" 
                                "\n\t\t     a cualquier situacion en la batalla.";
    Heroe heroe4("Invoker", "Universal", historiaHeroe4, estadisticasHeroe4);
    heroe4.agregarHabilidad("Quas");
    heroe4.agregarHabilidad("Wex");
    heroe4.agregarHabilidad("Exort");
    heroe4.agregarHabilidad("Invocar");
    heroes.push_back(heroe4);


    Estadisticas estadisticasHeroe5 = { 25, 14, 16 };
    string historiaHeroe5 = "Con cada gancho, su habilidad estrella, Pudge desata el miedo entre sus enemigos.";
    Heroe heroe5("Pudge", "Fuerza", historiaHeroe5, estadisticasHeroe5);
    heroe5.agregarHabilidad("Gancho de Carne");
    heroe5.agregarHabilidad("Pudrir");
    heroe5.agregarHabilidad("Monton de Carne");
    heroe5.agregarHabilidad("Descuartizar");
    heroes.push_back(heroe5);


    Estadisticas estadisticasHeroe6 = { 25, 14, 16 };
    string historiaHeroe6 = "Con cada gancho, su habilidad estrella, Pudge desata el miedo entre sus enemigos.";
    Heroe heroe6("Pudge", "Fuerza", historiaHeroe6, estadisticasHeroe6);
    heroe6.agregarHabilidad("Gancho de Carne");
    heroe6.agregarHabilidad("Pudrir");
    heroe6.agregarHabilidad("Monton de Carne");
    heroe6.agregarHabilidad("Descuartizar");
    heroes.push_back(heroe6);
    
    // Mostrar informaci�n de todos los h�roes
    for (const Heroe& heroe : heroes) {
        cout << "NOMBRE DEL HEROE   : " << heroe.obtenerNombre() << endl;
        cout << "TIPO DEL HEROE     : " << heroe.obtenerTipo() << endl;
        cout << "BIOGRAFIA DEL HEROE: " << heroe.obtenerBiografia() << endl;
        cout << endl;

        Estadisticas estadisticas = heroe.obtenerEstadisticas();
        cout << "ESTADISTICAS DEL HEROE:" << endl;
        cout << " -Fuerza: " << estadisticas.fuerza << endl;
        cout << " -Agilidad: " << estadisticas.agilidad << endl;
        cout << " -Inteligencia: " << estadisticas.inteligencia << endl;
        cout << endl;

        vector<string> habilidades = heroe.obtenerHabilidades();
        cout << "HABILIDADES DEL HEROE:" << endl;
        for (const string& habilidad : habilidades) {
            cout <<" -"<< habilidad << endl;
        }

        cout <<"--------------------------------------------------------------------------------------------------------------"<< endl; // Separador entre h�roes
    }

    return 0;
}
