#include <iostream>
#include "MenuJuego.h"

int main() {
    MenuJuego juego;
    juego.iniciar();
    juego.determinarGanador();
    char opcion;
    std::cout << "¿Desea jugar otra partida? (s/n): ";
    cin >> opcion;
    if (opcion == 's' || opcion == 'S') 
    {
        juego.nuevaPartida();
    } 
    else 
    {
        std::cout << "Gracias por jugar. ¡Hasta la próxima!" << endl;
        return 0;
    }
}