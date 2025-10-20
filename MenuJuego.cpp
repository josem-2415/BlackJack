#include "MenuJuego.h"
#include <iostream>

using namespace std;

// Metodos
void MenuJuego::iniciar(){
    // Lógica para iniciar el juego
    cout << "Iniciando el juego de Blackjack..." << endl;
    mazo.barajar();
    crupier.repartirInicial(jugador, mazo);
}

void MenuJuego::determinarGanador(){
    // Lógica para determinar el ganador
    int valorJugador = jugador.calcularValorManoJugador();
    int valorCrupier = crupier.calcularValorManoCrupier();

    cout << "Valor del Jugador: " << valorJugador << endl;
    cout << "Valor del Crupier: " << valorCrupier << endl;

    if (valorJugador > 21) {
        cout << "El Jugador se ha pasado. Gana el Crupier." << endl;
        manejarApuesta(jugador, "pierde");
    } else if (valorCrupier > 21 || valorJugador > valorCrupier) {
        cout << "El Jugador gana!" << endl;
        manejarApuesta(jugador, "gana");
    } else if (valorJugador < valorCrupier) {
        cout << "El Crupier gana!" << endl;
        manejarApuesta(jugador, "pierde");
    } else {
        cout << "Empate!" << endl;
        manejarApuesta(jugador, "empata");
    }
}

void MenuJuego::manejarApuesta(Jugador& jugador, string resultado){
    // Lógica para manejar la apuesta según el resultado
    jugador.actualizarSaldo(resultado, apuestaActual.getMonto());
}

void MenuJuego::nuevaPartida(){
    // Lógica para reiniciar el juego
    cout << "Reiniciando el juego para una nueva partida..." << endl;
    jugador = Jugador(); // Reiniciar jugador
    crupier = Crupier(); // Reiniciar crupier
    mazo = Mazo();       // Reiniciar mazo
    apuestaActual.reiniciar(); // Reiniciar apuesta
    iniciar();           // Iniciar nueva partida
}