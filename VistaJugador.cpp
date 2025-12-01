#include "VistaJugador.h"
#include <iostream>

VistaJugador::VistaJugador() {}

void VistaJugador::mostrarManoJugador(Jugador& jugador) {
    cout << "\n======================================="<< endl;
        cout << "Tus cartas:" << endl;
        jugador.mostrarMano();
        cout << "== Valor total: " << jugador.calcularValorMano() << " =="<< endl;
        cout << "=======================================\n\n";
}

void VistaJugador::mostrarManoCrupier(Crupier& crupier) {
    cout << "\n======================================="<< endl;
        cout << "Carta visible del crupier:" << endl;
        crupier.mostrarPrimeraCarta();
        cout << "=======================================\n";
}

double VistaJugador::solicitarMontoApuesta(double saldo, Jugador& jugador) {
    double monto;
    std::cout << "\nTu saldo actual es: $" << saldo << std::endl;
    std::cout << "Ingresa el monto que deseas apostar: $";
    std::cin >> monto;
    while (monto > saldo || monto <= 0) {
        std::cout << "Monto invalido. Ingresa una cantidad menor o igual a tu saldo actual: $";
        std::cin >> monto;
    }
    jugador.realizarApuesta(monto);
    return monto;
}

void VistaJugador::mostrarSaldo(double saldo) {
    std::cout << "Saldo restante despues de apostar: $" << saldo << std::endl;
    std::cout << "=======================================\n\n";
}

void VistaJugador::mostrarManoCrupierCompleta(Crupier& crupier) {
    cout << "\n======================================="<< endl;
        cout << "Mano completa del crupier:" << endl;
        crupier.mostrarMano();
        cout << "== Valor total: " << crupier.calcularValorMano() << " =="<< endl;
        cout << "=======================================\n\n";
}

char VistaJugador::confirmarNuevaCarta() {
    char decision;
    std::cout << "¿Deseas pedir otra carta? (s/n): ";
    std::cin >> decision;
    return decision;
}

char VistaJugador::confirmarDecision() {
    char decision;
    std::cout << "¿Deseas continuar jugando? (s/n): ";
    std::cin >> decision;
    return decision;
}