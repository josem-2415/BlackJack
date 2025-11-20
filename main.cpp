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
    MenuJuego menu(jugador, crupier, mazo);
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
        cout << "=======================================\n\n";

        // Repartir cartas iniciales
        menu.iniciar(crupier, jugador);

        cout << "\n======================================="<< endl;
        cout << "Tus cartas:" << endl;
        jugador.mostrarMano();
        cout << "== Valor total: " << jugador.calcularValorMano() << " =="<< endl;
        cout << "=======================================\n\n";

        cout << "======================================="<< endl;
        cout << "Carta visible del crupier:" << endl;
        crupier.mostrarPrimeraCarta();
        cout << "=======================================\n";

        // Verificar si el jugador se pasa de 21
        if (jugador.calcularValorMano() > 21) {

            cout << "\nTe pasaste de 21. Perdiste automaticamente.\n";
            jugador.actualizarSaldo("pierde", monto);
        } else if(jugador.tieneBlackjack()) {
            cout << "\n----------------------------------------" << endl;            
            cout << "¡Tienes BlackJack! Ganaste automaticamente." << endl;
            cout << "----------------------------------------\n";
            jugador.actualizarSaldo("gana", monto);
        } else {
            // Turno del jugador
            char decision;
            do {
                cout << "\n¿Deseas pedir otra carta? (s/n): ";
                cin >> decision;

                if (decision == 's' || decision == 'S') {
                    jugador.pedirCarta(mazo);
                    cout << "======================================="<< endl;
                    cout << "Tu nueva mano:" << endl;
                    jugador.mostrarMano();
                    cout << "=== Valor total: " << jugador.calcularValorMano() << " ===" << endl;
                    cout << "=======================================\n";
                }

                if (jugador.calcularValorMano() > 21) {
                    cout << "\n----------------------------------------" << endl;
                    cout << "Te pasaste de 21. Perdiste." << endl;
                    cout << "----------------------------------------\n";
                    jugador.actualizarSaldo("pierde", monto);
                    break;
                } else if (jugador.tieneBlackjack()){
                    cout << "\n----------------------------------------" << endl;
                    cout << "¡Tienes 21! Ganaste." << endl;
                    cout << "----------------------------------------\n";
                    jugador.actualizarSaldo("gana", monto);
                }
            } while (decision == 's' || decision == 'S');

            // Turno del crupier (solo si el jugador no se pasó)
            if (jugador.calcularValorMano() <= 21) {
                cout << "\n---------------------------------------" << endl;
                cout << "Turno del crupier..." << endl;
                cout << "---------------------------------------\n";
                // El crupier pide cartas hasta tener al menos 17
                while (crupier.calcularValorMano() < 17) {
                    crupier.pedirCarta(mazo);
                }
                cout << "\n======================================="<< endl;
                cout << "Mano completa del crupier:" << endl;
                crupier.mostrarMano();
                cout << "======================================="<< endl;

                // Determinar ganador con el método del menú
                string resultado = menu.determinarGanador(jugador, crupier, monto);
                jugador.actualizarSaldo(resultado, monto);
            }
        }

        cout << "\n=== Tu saldo actual: $" << jugador.getSaldo() << " ===" << endl;

        if (jugador.getSaldo() <= 0) {
            cout << "\n\nTe has quedado sin dinero. Fin del juego.\n";
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

