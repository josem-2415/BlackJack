#include "Crupier.h"
#include <vector>
#include <iostream>

// Metodos
void Crupier::repartirInicial(Jugador& jugador, Mazo& mazo){
    // Repartir dos cartas al jugador
    jugador.pedirCarta(mazo);
    jugador.pedirCarta(mazo);

    // Repartir dos cartas al crupier
    mano.push_back(mazo.repartirCarta());
    mano.push_back(mazo.repartirCarta());
}

void Crupier::preguntarCarta(Jugador& jugador, Mazo& mazo){
    // Lógica para que el crupier tome cartas según las reglas del juego
    while (calcularValorManoCrupier() < 17) {
        mano.push_back(mazo.repartirCarta());
    }
}

int Crupier::calcularValorManoCrupier()const{
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

void Crupier::limpiarMano(){
    mano.clear();
}

void Crupier::mostrarMano()const{
    std::cout << "Mano del Crupier:" << std::endl;
    for (const auto& carta : mano) {
        carta.mostrarCarta();
    }
}