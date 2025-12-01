#include <iostream>
#include "Jugador.h"
#include "Crupier.h"
#include "Mazo.h"
#include "Controlador.h"
#include "Vista.h"
#include "VistaJugador.h"
using namespace std;

int main() {
    Jugador jugador;
    Crupier crupier;
    Mazo mazo;
    Controlador controlador(jugador, crupier, mazo);
    Vista vista;
    VistaJugador vistaJugador;

    char opcion;

    do {
        // Iniciar el juego

        controlador.iniciar(crupier, jugador);

        // Solicitar apuesta al jugador
        double monto = vistaJugador.solicitarMontoApuesta(jugador.getSaldo(), jugador);
        vistaJugador.mostrarSaldo(jugador.getSaldo() - monto);

        // Mostrar manos iniciales
        vistaJugador.mostrarManoJugador(jugador);
        vistaJugador.mostrarManoCrupier(crupier);

        // Verificar si el jugador se pasa de 21
        if (jugador.calcularValorMano() > 21) {
            vista.mostrarResultado("pierde", monto, jugador.calcularValorMano());
            controlador.manejarApuesta(jugador, "pierde");

        } else if(jugador.tieneBlackjack()) {
            vista.mostrarResultado("gana", monto, jugador.calcularValorMano());
            controlador.manejarApuesta(jugador, "gana");

        } else {
            // Turno del jugador
            char decision;
            do {
                decision = vistaJugador.confirmarNuevaCarta();
                if (decision == 's' || decision == 'S') {
                    jugador.pedirCarta(mazo);
                    vistaJugador.mostrarManoJugador(jugador);
                }

                if (jugador.calcularValorMano() > 21) {
                    vista.mostrarResultado("pierde", monto, jugador.calcularValorMano());
                    controlador.manejarApuesta(jugador, "pierde");
                    break;
                } else if (jugador.calcularValorMano() == 21) {
                    vista.mostrarResultado("gana", monto, jugador.calcularValorMano());
                    controlador.manejarApuesta(jugador, "gana");
                }

            } while (decision == 's' || decision == 'S');

            // Turno del crupier (solo si el jugador no se pasó)
            if (jugador.calcularValorMano() <= 21) {
                vista.tunroCrupier();
                // El crupier pide cartas hasta tener al menos 17
                while (crupier.calcularValorMano() < 17) {
                    crupier.pedirCarta(mazo);
                }

                vistaJugador.mostrarManoCrupierCompleta(crupier);

                // Determinar ganador con el método del menú
                string resultado = controlador.determinarGanador(jugador, crupier, monto);
                controlador.manejarApuesta(jugador, resultado);
            }
        }

        vistaJugador.mostrarSaldo(jugador.getSaldo());

        if (jugador.getSaldo() <= 0) {
            cout << "\n\nTe has quedado sin dinero. Fin del juego.\n";
            break;
        }

        opcion = vistaJugador.confirmarDecision();

        if (opcion == 's' || opcion == 'S')
            cout << "\nReiniciando el juego...\n";

    } while (opcion == 's' || opcion == 'S');

    cout << "\nGracias por jugar Blackjack.\n";
    return 0;
}

