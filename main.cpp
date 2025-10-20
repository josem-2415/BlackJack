#include <iostream>
#include "Jugador.h"
#include "Crupier.h"
#include "Mazo.h"
#include "MenuJuego.h"
using namespace std;

int main() {
    Jugador jugador;
    Crupier crupier;
    Mazo mazo;
    MenuJuego menu;
    char opcion;

    do {
        cout << "=========================================\n";
        cout << "           Bienvenido al Blackjack       \n";
        cout << "=========================================\n";

        mazo.inicializarMazo();
        jugador.limpiarMano();
        crupier.limpiarMano();

        double monto;
        cout << "\nTu saldo actual es: $" << jugador.getSaldo() << endl;
        cout << "Ingresa el monto que deseas apostar: $";
        cin >> monto;

        while (monto > jugador.getSaldo() || monto <= 0) {
            cout << "Monto invalido. Ingresa una cantidad menor o igual a tu saldo actual: $";
            cin >> monto;
        }

        jugador.realizarApuesta(monto);
        jugador.actualizarSaldo("apostar", monto); // Se descuenta el monto al apostar
        cout << "Saldo restante despues de apostar: $" << jugador.getSaldo() << endl;

        // Repartir cartas iniciales
        jugador.pedirCarta(mazo);
        jugador.pedirCarta(mazo);

        crupier.pedirCarta(mazo); // carta visible
        crupier.pedirCarta(mazo); // carta oculta

        cout << "\nTus cartas:" << endl;
        jugador.mostrarMano();
        cout << "Valor total: " << jugador.calcularValorManoJugador() << endl;

        cout << "\nCarta visible del crupier:" << endl;
        crupier.mostrarPrimeraCarta();

        // Verificar si el jugador se pasa de 21
        if (jugador.calcularValorManoJugador() > 21) {
            cout << "\nTe pasaste de 21. Perdiste automaticamente.\n";
            jugador.actualizarSaldo("pierde", monto);
        } else {
            // Turno del jugador
            char decision;
            do {
                cout << "\n¿Deseas pedir otra carta? (s/n): ";
                cin >> decision;

                if (decision == 's' || decision == 'S') {
                    jugador.pedirCarta(mazo);
                    cout << "\nTu nueva mano:" << endl;
                    jugador.mostrarMano();
                    cout << "Valor total: " << jugador.calcularValorManoJugador() << endl;
                }

                if (jugador.calcularValorManoJugador() > 21) {
                    cout << "Te pasaste de 21. Perdiste." << endl;
                    jugador.actualizarSaldo("pierde", monto);
                    break;
                }
            } while (decision == 's' || decision == 'S');

            // Turno del crupier (solo si el jugador no se pasó)
            if (jugador.calcularValorManoJugador() <= 21) {
                cout << "\nTurno del crupier..." << endl;

                // El crupier pide cartas hasta tener al menos 17
                while (crupier.calcularValorManoCrupier() < 17) {
                    crupier.pedirCarta(mazo);
                }

                cout << "\nMano completa del crupier:" << endl;
                crupier.mostrarMano();

                // Determinar ganador con el método del menú
                string resultado = menu.determinarGanador(jugador, crupier, monto);
                jugador.actualizarSaldo(resultado, monto);
            }
        }

        cout << "\nTu saldo actual: $" << jugador.getSaldo() << endl;

        if (jugador.getSaldo() <= 0) {
            cout << "\nTe has quedado sin dinero. Fin del juego.\n";
            break;
        }

        cout << "\n¿Desea jugar otra partida? (s/n): ";
        cin >> opcion;

        if (opcion == 's' || opcion == 'S')
            cout << "\nReiniciando el juego...\n";

    } while (opcion == 's' || opcion == 'S');

    cout << "\nGracias por jugar Blackjack.\n";
    return 0;
}

