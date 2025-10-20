#include "Apuesta.h"
#include <string>

using namespace std;

// Constructor
Apuesta::Apuesta(double m = 0.0) : monto(m) {}

// Metodos
void Apuesta::registrarApuesta(double m){ // Registra la apuesta
    monto = m;
}

int Apuesta::calcularGanancia(string resultado){ // Calcula ganancia según resultado

}

void Apuesta::reiniciar(){ // Reinicia el monto
    monto = 0.0;
}

//Getter
double Apuesta::getMonto() const { // Devuelve el monto actual
    return monto; 
} 

