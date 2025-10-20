#include "Apuesta.h"
#include <string>

// Constructor
Apuesta::Apuesta(double m) : monto(m) {}

Apuesta::Apuesta() : monto(0.0) {}
// Metodos
void Apuesta::registrarApuesta(double m){ // Registra la apuesta
    monto = m;
}

int Apuesta::calcularGanancia(std::string resultado){ // Calcula ganancia según resultado
    if (resultado == "gana") {
        return static_cast<int>(monto); // Gana el monto apostado
    } else if (resultado == "empata") {
        return 0; // No gana ni pierde
    } else if (resultado == "pierde") {
        return -static_cast<int>(monto); // Pierde el monto apostado
    }
    return 0; // En caso de resultado desconocido
}

void Apuesta::reiniciar(){ // Reinicia el monto
    monto = 0.0;
}

//Getter
double Apuesta::getMonto() const { // Devuelve el monto actual
    return monto; 
} 

