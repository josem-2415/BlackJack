#include "Carta.h"
#include "Mazo.h"
#include <iostream>
#include <algorithm>
#include <random>

// Constructor
Mazo::Mazo(){}

// Metodos
void Mazo::barajar() {
    srand(time(0)); // Inicializa la semilla del generador de números aleatorios
    for (int i = 0; i < cartas.size(); i++) {
        int indiceAleatorio = rand() % cartas.size(); // Genera un índice aleatorio
        swap(cartas[i], cartas[indiceAleatorio]);     // Intercambia las cartas
    }
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
    cartas.clear(); // Limpia el mazo por si ya tenía cartas

    // Palos y valores de las cartas
    vector<string> palos = {"Corazones", "Diamantes", "Tréboles", "Picas"};
    vector<string> valores = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

    // Crear todas las combinaciones de cartas
    for (int i = 0; i < palos.size(); i++) {
        for (int j = 0; j < valores.size(); j++) {
            cartas.push_back(Carta(valores[j], palos[i]));
        }
    }

    // Barajar el mazo de forma aleatoria
    srand(time(0)); // Inicializa la semilla para la aleatoriedad
    for (int i = 0; i < cartas.size(); i++) {
        int indiceAleatorio = rand() % cartas.size();
        swap(cartas[i], cartas[indiceAleatorio]);
    }
}

int Mazo::cartasRestantes() const {
    return static_cast<int>(cartas.size());
}