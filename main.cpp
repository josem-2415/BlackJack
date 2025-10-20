#include <iostream>
#include "MenuJuego.h"

using namespace std;

int main() {
    MenuJuego juego;
    juego.iniciar();
    juego.determinarGanador();
    char opcion;
    cout << "¿Desea jugar otra partida? (s/n): ";
    cin >> opcion;
    if (opcion == 's' || opcion == 'S') 
    {
        juego.nuevaPartida();
    } 
    else 
    {
        cout << "Gracias por jugar. ¡Hasta la próxima!" << endl;
        return 0;
    }
}