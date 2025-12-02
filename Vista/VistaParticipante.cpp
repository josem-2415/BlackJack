#include "VistaParticipante.h"
#include <iostream>

VistaParticipante::VistaParticipante() {}

void VistaParticipante::mostrarManoJugador(Jugador& jugador) {
    cout << "\n======================================="<< endl;
        cout << "Tus cartas:" << endl;
        jugador.mostrarMano();
        cout << "== Valor total: " << jugador.calcularValorMano() << " =="<< endl;
        cout << "=======================================\n\n";
}

void VistaParticipante::mostrarManoCrupier(Crupier& crupier) {
    cout << "\n======================================="<< endl;
        cout << "Carta visible del crupier:" << endl;
        crupier.mostrarPrimeraCarta();
        cout << "=======================================\n";
}

double VistaParticipante::solicitarMontoApuesta(double saldo, Jugador& jugador) {
    double monto;
    std::cout << "\nTu saldo actual es: $" << saldo << std::endl;
    std::cout << "Ingresa el monto que deseas apostar: $";
    std::cin >> monto;
    while (monto > saldo || monto <= 0) {
        std::cout << "Monto invalido. Ingresa una cantidad menor o igual a tu saldo actual: $";
        std::cin >> monto;
    }
    jugador.realizarApuesta(monto);
    jugador.actualizarSaldo("apostar", monto);
    return monto;
}

void VistaParticipante::mostrarSaldo(double saldo) {
    std::cout << "Saldo restante despues de apostar: $" << saldo << std::endl;
    std::cout << "=======================================\n\n";
}

void VistaParticipante::mostrarManoCrupierCompleta(Crupier& crupier) {
    cout << "\n======================================="<< endl;
        cout << "Mano completa del crupier:" << endl;
        crupier.mostrarMano();
        cout << "== Valor total: " << crupier.calcularValorMano() << " =="<< endl;
        cout << "=======================================\n\n";
}

char VistaParticipante::confirmarNuevaCarta() {
    char decision;
    std::cout << "¿Deseas pedir otra carta? (s/n): ";
    std::cin >> decision;
    return decision;
}

char VistaParticipante::confirmarDecision() {
    char decision;
    std::cout << "¿Deseas continuar jugando? (s/n): ";
    std::cin >> decision;
    return decision;
}