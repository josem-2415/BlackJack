#ifndef VISTAPARTICIPANTE_H
#define VISTAPARTICIPANTE_H

#include <iostream>
#include <vector>
#include "../Modelo/Jugador.h"
#include "../Modelo/Crupier.h"

using namespace std;

class VistaParticipante {
public:
    VistaParticipante();

    void mostrarManoJugador(Jugador& jugador);
    void mostrarManoCrupier(Crupier& crupier);
    void mostrarManoCrupierCompleta(Crupier& crupier);
    void mostrarSaldo(double saldo);
    double solicitarMontoApuesta(double saldo, Jugador& jugador);
    char confirmarNuevaCarta();
    char confirmarDecision();
};
#endif // VISTAPARTICIPANTE_H