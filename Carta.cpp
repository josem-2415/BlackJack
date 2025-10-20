#include "Carta.h"
#include <iostream>

// Constructor
Carta::Carta(string v, string p): valor(0), palo(""){}

// Metodos
void Carta::mostrarCarta()const{
    std::cout<<valor<<" de "<<palo<<std::endl;
}

// Getter
std::string Carta::getValor()const{
    return valor;
}

std::string Carta::getPalo()const{
    return palo;
}
