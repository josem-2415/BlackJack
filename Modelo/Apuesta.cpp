#include "Apuesta.h"
#include <string>

// Constructor
Apuesta::Apuesta() : monto(0.0) {}
Apuesta::Apuesta(double m) : monto(m) {}

// Metodos
void Apuesta::registrarApuesta(double m) { monto = m; }

int Apuesta::calcularGanancia(string resultado) {
    if (resultado == "gana") {
        // Si gana, se duplica la apuesta (recupera lo apostado + lo mismo en ganancia)
        return monto * 2;
    } 
    else if (resultado == "empate") {
        // Si empata, solo recupera la apuesta
        return monto;
    } 
    else if (resultado == "pierde") {
        // Si pierde, no recupera nada
        return 0;
    }
    return 0; // Valor por defecto
}

void Apuesta::reiniciar() { monto = 0.0; }

//Getter
double Apuesta::getMonto() const { return monto; }
