#include "Carta.h"
#include <iostream>

// Constructor
Carta::Carta(const std::string& v, const std::string& p) : valor(v), palo(p) {}

// Metodo
void Carta::mostrarCarta() const { std::cout << valor << " de " << palo << std::endl; }

// Getters
std::string Carta::getValor() const { return valor; }

std::string Carta::getPalo() const { return palo; }

