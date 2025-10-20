#include <iostream>
#include "Jugador.h"
#include "Crupier.h"
#include "Mazo.h"
using namespace std;

int main() {
    Jugador jugador;
    Crupier crupier;
    Mazo mazo;
    char opcion;

    do {
        cout << "Iniciando el juego de Blackjack..." << endl;

        mazo.inicializarMazo();
        jugador.limpiarMano();
        crupier.limpiarMano();

        // Repartir cartas
        jugador.pedirCarta(mazo);
        jugador.pedirCarta(mazo);
        crupier.repartirInicial(jugador, mazo);

        // Calcular valores
        int valorJugador = jugador.calcularValorManoJugador();
        int valorCrupier = crupier.calcularValorManoCrupier();

        cout << "Valor del Jugador: " << valorJugador << endl;
        cout << "Valor del Crupier: " << valorCrupier << endl;

        if ((valorJugador > valorCrupier) && (valorJugador <= 21))
            cout << "Ganaste!" << endl;
        else if ((valorJugador < valorCrupier) && (valorCrupier <= 21 && valorJugador <= 21))
            cout << "Perdiste!" << endl;
        
        else if (valorJugador > 21)
            cout << "Te pasaste de 21. Perdiste!" << endl;
        
        else if (valorCrupier > 21 && valorJugador <= 21)
            cout << "El crupier se pasó de 21. Ganaste!" << endl;

        else if (valorJugador == valorCrupier)
            cout << "Empate!" << endl;

        cout << "¿Desea jugar otra partida? (s/n): ";
        cin >> opcion;
        if (opcion == 's' || opcion == 'S')
            cout << "Reiniciando el juego para una nueva partida..." << endl;

    } while (opcion == 's' || opcion == 'S');

    return 0;
}
