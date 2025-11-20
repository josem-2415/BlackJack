#include "Crupier.h"
#include <vector>
#include <iostream>

Crupier::Crupier(){}

// Metodos
void Crupier::preguntarCarta(Mazo& mazo){
    // Lógica para que el crupier tome cartas según las reglas del juego
    while (calcularValorMano() < 17) {
        mano.push_back(mazo.repartirCarta());
    }
}

void Crupier::mostrarPrimeraCarta() {
    if (!mano.empty()) {
        cout << mano[0].getValor() << " de " << mano[0].getPalo() << endl;
    }
}

void Crupier::repartirInicial(Mazo& mazo, Jugador& jugador){
    // Repartir dos cartas al jugador
    jugador.pedirCarta(mazo);
    jugador.pedirCarta(mazo);

    // Repartir dos cartas al crupier
    mano.push_back(mazo.repartirCarta());
    mano.push_back(mazo.repartirCarta());
}

