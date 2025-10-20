
/*
===============================================================================
                                CRC - Apuesta
===============================================================================

Clase:
    Apuesta

Responsabilidades:
    - Registrar el monto de una apuesta realizada por el jugador.
    - Calcular la ganancia o pérdida según el resultado de la partida.
    - Reiniciar la apuesta entre partidas.

Colaboración:
    - Jugador (para aplicar resultados y actualizar saldo).
    - MenuJuego (para manejar apuestas durante el flujo del juego).

Creadores:
    - Andrés Felipe Rodríguez García 2539555
    - José Manuel Cardona 2521653
    - Nerie Vásquez Díaz 2519638
===============================================================================
*/

#ifndef APUESTA_H
#define APUESTA_H
#include <string>
using namespace std;

class Apuesta {
private:
    double monto; // Monto apostado

public:
    Apuesta(double m = 0.0) : monto(m) {}
    void registrarApuesta(double m);           // Registra la apuesta
    int calcularGanancia(string resultado);    // Calcula ganancia según resultado
    void reiniciar();                          // Reinicia el monto
    double getMonto() const { return monto; }  // Devuelve el monto actual
};
#endif