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

Carta Mazo::repartirCarta(){

    //Verficar que el vector de cartas no este vacio
    if (cartas.empty()) {
        throw std::out_of_range("No quedan cartas en el mazo");
    }

    // Tomar la última carta del vector
    Carta cartaSuperior = cartas.back();

    // Eliminarla del mazo
    cartas.pop_back();

    // Devolver la carta
    return cartaSuperior;
}

void Mazo::cartasRestantes()const{
    std::cout << "Cartas restantes: " << cartas.size() << endl;
}