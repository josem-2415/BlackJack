#include "Apuesta.h"
#include <string>

using namespace std;

Apuesta::Apuesta() : monto(0.0) {}
Apuesta::Apuesta(double m) : monto(m) {}

void Apuesta::registrarApuesta(double m) { monto = m; }

int Apuesta::calcularGanancia(string resultado) {
    // implementar lógica y devolver int (o double si quieres)
    return 0; // placeholder
}

void Apuesta::reiniciar() { monto = 0.0; }

double Apuesta::getMonto() const { return monto; }
