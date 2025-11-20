#include "Jugador.h"
#include <iostream>

using namespace std;

// Constructor
Jugador::Jugador(double saldo) : saldoActual(saldo), apuestaActual(0.0) {}

// Metodos

bool Jugador::tieneBlackjack()const{
    return (mano.size() == 2 && calcularValorMano() == 21);
}

void Jugador::realizarApuesta(double monto){
    apuestaActual.registrarApuesta(monto);
}

void Jugador::actualizarSaldo(const std::string& resultado, double monto) {
    if (resultado == "apostar") {
        saldoActual -= monto;
        return;
    }

    int ganancia = apuestaActual.calcularGanancia(resultado);
    saldoActual += ganancia;
    apuestaActual.reiniciar();
}

// Getter
double Jugador::getSaldo() const {
    return saldoActual;
}