#include "Carta.h"
#include "Mazo.h"
#include <iostream>
#include <algorithm>
#include <random>

// Constructor
Mazo::Mazo(){}

// Metodos
void Mazo::barajar(){
    random_device rd;   // obtiene una semilla aleatoria del sistema
    mt19937 g(rd());    // generador Mersenne Twister 
    shuffle(cartas.begin(), cartas.end(), g);
}

Carta Mazo::repartirCarta() {
    if (cartas.empty()) {
        std::cout << "Se reinicia el mazo." << std::endl;
        inicializarMazo(); // <-- ahora sí existe
    }
    Carta carta = cartas.back();
    cartas.pop_back();
    return carta;
}

void Mazo::inicializarMazo() {
    cartas.clear(); // Limpiamos por si ya tenía cartas

    vector<string> palos = {"Corazones", "Diamantes", "Tréboles", "Picas"};
    vector<string> valores = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

    for (const auto& palo : palos) {
        for (const auto& valor : valores) {
            cartas.emplace_back(valor, palo);
        }
    }

    // Barajamos el mazo
    random_device rd;
    mt19937 g(rd());
    shuffle(cartas.begin(), cartas.end(), g);
}

int Mazo::cartasRestantes() const {
    return static_cast<int>(cartas.size());
}