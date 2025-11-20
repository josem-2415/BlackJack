#include "MenuJuego.h"
#include <iostream>

using namespace std;

// Constructor
MenuJuego::MenuJuego(Jugador& j, Crupier& c, Mazo& m)
    : jugador(j), crupier(c), mazo(m) {}

// Metodos
void MenuJuego::iniciar(Crupier& crupier, Jugador& jugador){
    // Lógica para iniciar el juego
    cout << "Iniciando el juego de Blackjack..." << endl;
    mazo.barajar();
    crupier.repartirInicial(mazo, jugador);
}

string MenuJuego::determinarGanador(Jugador& jugador, Crupier& crupier, double monto) {
    int valorJugador = jugador.calcularValorMano();
    int valorCrupier = crupier.calcularValorMano();

    if ((valorJugador > valorCrupier && valorJugador <= 21) ||
        (valorCrupier > 21 && valorJugador <= 21)) {
        cout << "\n---------------------------------------"<< endl;
        cout << "¡Ganaste $" << monto * 2 << "!" << endl;
        cout << "---------------------------------------\n\n";
        return "gana";
    } 
    else if (valorJugador == valorCrupier) {
        cout << "\n---------------------------------------"<< endl;
        cout << "Empate. Recuperas tu apuesta." << endl;
        cout << "---------------------------------------\n\n";
        return "empate";
    } 
    else {
        cout << "\n---------------------------------------"<< endl;
        cout << "Perdiste $" << monto << "." << endl;
        cout << "---------------------------------------\n\n";
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
    jugador = Jugador();        //Reinicuar jugador
    crupier = Crupier();        //Reiniciar crupier  
    mazo = Mazo();       // Reiniciar mazo
    apuestaActual.reiniciar(); // Reiniciar apuesta
    iniciar(crupier, jugador);           // Iniciar nueva partida
}