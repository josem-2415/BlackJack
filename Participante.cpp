#include "Participante.h"

Participante::Participante(){}

int Participante::calcularValorMano() const {
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

void Participante::pedirCarta(Mazo& mazo) {
    Carta nuevaCarta = mazo.repartirCarta();
    mano.push_back(nuevaCarta);
}

void Participante::mostrarMano()const{
    for (const auto& carta : mano) {
        carta.mostrarCarta();
    }
}

void Participante::limpiarMano() {
    mano.clear();  // elimina todas las cartas del vector
}
