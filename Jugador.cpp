#include "Jugador.h"
#include <iostream>

using namespace std;

// Constructor
Jugador::Jugador(double saldo) : saldoActual(saldo), apuestaActual(0.0) {}

// Metodos
void Jugador::pedirCarta(Mazo& mazo){
    Carta nuevaCarta = mazo.repartirCarta();
    mano.push_back(nuevaCarta);
}

void Jugador::mostrarMano()const{
    cout << "Mano del Jugador:" << endl;
    for (const auto& carta : mano) {
        carta.mostrarCarta();
    }
}

int Jugador::calcularValorManoJugador()const{
    int valorTotal = 0;
    int numAses = 0;

    for (const auto& carta : mano) {
        std::string valorCarta = carta.getValor();

        if (valorCarta == "A") {
            valorTotal += 11; // As vale 11 inicialmente
            numAses++;
        } else if (valorCarta == "K" || valorCarta == "Q" || valorCarta == "J") {
            valorTotal += 10; // Figuras valen 10
        } else {
            valorTotal += std::stoi(valorCarta); // Cartas numéricas
        }
    }

    // Ajustar el valor de los Ases si el total excede 21
    while (valorTotal > 21 && numAses > 0) {
        valorTotal -= 10; // Convertir un As de 11 a 1
        numAses--;
    }

    return valorTotal;
}

bool Jugador::tieneBlackjack()const{
    return (mano.size() == 2 && calcularValorManoJugador() == 21);
}

void Jugador::realizarApuesta(double monto){
    apuestaActual.registrarApuesta(monto);
}

void Jugador::actualizarSaldo(string resultado, double monto){
    int ganancia = apuestaActual.calcularGanancia(resultado);
    saldoActual += ganancia;
    apuestaActual.reiniciar();
}

void Jugador::limpiarMano() {
    mano.clear();  // elimina todas las cartas del vector
}

// Getter
double Jugador::getSaldo() const {
    return saldoActual;
}