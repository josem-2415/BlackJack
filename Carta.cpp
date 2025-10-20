#include "Carta.h"
#include <iostream>

Carta::Carta(string v = 0, string p = ""): valor(v), palo(p){}

std::string Carta::getValor()const{
    return valor;
}

std::string Carta::getPalo()const{
    return palo;
}

void Carta::mostrarCarta()const{
    std::cout<<valor<<" de "<<palo<<std::endl;
}
