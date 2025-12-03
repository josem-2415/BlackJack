#include "Controlador.h"
#include <iostream>
#include <limits> 

using namespace std;


// Limpieza de Buffer y pantalla
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void limpiarPantalla() {
    system("cls");
}
// Constructor
Controlador::Controlador(Jugador& j, Crupier& c, Mazo& m)
    : jugador(j), crupier(c), mazo(m) {}



// Iniciar ronda
void Controlador::iniciar(Crupier& crupier, Jugador& jugador) {
    
    limpiarPantalla(); // Limpia la ronda anterior
    vista.bienvenida();

    mazo.inicializarMazo();
    jugador.limpiarMano();
    crupier.limpiarMano();

    cout << "Iniciando el juego de Blackjack..." << endl;
    mazo.barajar();
    crupier.repartirInicial(mazo, jugador);
}



// Determinar ganador
string Controlador::determinarGanador(Jugador& jugador, Crupier& crupier, double monto) {
    int valorJugador = jugador.calcularValorMano();
    int valorCrupier = crupier.calcularValorMano();

    if ((valorJugador > valorCrupier && valorJugador <= 21) ||
        (valorCrupier > 21 && valorJugador <= 21)) {

        cout << "\n---------------------------------------" << endl;
        cout << "¡Ganaste $" << monto * 2 << "!" << endl;
        cout << "---------------------------------------\n\n";
        return "gana";
    } 
    else if (valorJugador == valorCrupier) {

        cout << "\n---------------------------------------" << endl;
        cout << "Empate. Recuperas tu apuesta." << endl;
        cout << "---------------------------------------\n\n";
        return "empate";
    } 
    else {

        cout << "\n---------------------------------------" << endl;
        cout << "Perdiste $" << monto << "." << endl;
        cout << "---------------------------------------\n\n";
        return "pierde";
    }
}



// Manejar apuesta y verificar fin del juego
void Controlador::manejarApuesta(Jugador& jugador, string resultado) {

    jugador.actualizarSaldo(resultado, apuestaActual.getMonto());


    //  Si el jugador pierde todo, finaliza el juego

    if (jugador.getSaldo() <= 0) {
        cout << "\n===========================================\n";
        cout << "Lo perdiste todo, malo apostar.\n";
        cout << "===========================================\n\n";
        system("pause");
        exit(0);
    }
}



// Mostrar manos al apostar
void Controlador::solicitarApuesta(VistaParticipante& vistaParticipante, Jugador& jugador, Crupier& crupier) {

    limpiarPantalla(); // <-- Limpia la pantalla antes de mostrar nueva ronda

    vistaParticipante.mostrarManoJugador(jugador);
    vistaParticipante.mostrarManoCrupier(crupier);
}
