#ifndef VISTAJUGADOR_H
#define VISTAJUGADOR_H

#include <iostream>
#include <vector>
#include "Jugador.h"
#include "Crupier.h"

using namespace std;

class VistaJugador {
public:
    VistaJugador();

    void mostrarManoJugador(Jugador& jugador);
    void mostrarManoCrupier(Crupier& crupier);
    void mostrarManoCrupierCompleta(Crupier& crupier);
    void mostrarSaldo(double saldo);
    double solicitarMontoApuesta(double saldo, Jugador& jugador);
    char confirmarNuevaCarta();
    char confirmarDecision();
};
#endif // VISTAJUGADOR_H