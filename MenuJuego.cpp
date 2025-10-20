#include "MenuJuego.h"
#include <iostream>

using namespace std;

// Constructor
MenuJuego::MenuJuego() : jugador(), crupier(), mazo(), apuestaActual(0.0){}

// Metodos
void MenuJuego::iniciar(){
    // Lógica para iniciar el juego
    cout << "Iniciando el juego de Blackjack..." << endl;
    mazo.barajar();
    crupier.repartirInicial(jugador, mazo);
}

string MenuJuego::determinarGanador(Jugador& jugador, Crupier& crupier, double monto) {
    int valorJugador = jugador.calcularValorManoJugador();
    int valorCrupier = crupier.calcularValorManoCrupier();

    if ((valorJugador > valorCrupier && valorJugador <= 21) ||
        (valorCrupier > 21 && valorJugador <= 21)) {
        cout << "\n¡Ganaste $" << monto * 2 << "!" << endl;
        return "gana";
    } 
    else if (valorJugador == valorCrupier) {
        cout << "\nEmpate. Recuperas tu apuesta." << endl;
        return "empate";
    } 
    else {
        cout << "\nPerdiste $" << monto << "." << endl;
        return "pierde";
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