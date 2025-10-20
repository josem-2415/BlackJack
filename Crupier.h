/*
===============================================================================
                                CRC - Crupier
===============================================================================

Clase:
    Crupier

Responsabilidades:
    - Representar la banca o distribuidor del juego.
    - Repartir las cartas iniciales al jugador y a sí mismo.
    - Calcular el valor de su propia mano.
    - Mostrar las cartas del crupier.
    - Controlar la lógica del turno del crupier.

Colaboración:
    - Mazo (para repartir cartas).
    - Jugador (para interactuar y repartir cartas iniciales).

Creadores:
    - Andrés Felipe Rodríguez García 2539555
    - José Manuel Cardona 2521653
    - Nerie Vásquez Díaz 2519638
===============================================================================
*/

#ifndef CRUPIER_H
#define CRUPIER_H
#include <vector>
#include "Carta.h"
#include "Mazo.h"
#include "Jugador.h"
using namespace std;

class Crupier {
private:
    vector<Carta> mano; // Cartas del crupier
    
public:
    void repartirInicial(Jugador& jugador, Mazo& mazo); // Da dos cartas al jugador
    void preguntarCarta(Jugador& jugador, Mazo& mazo);              // Pregunta si quiere más
    int calcularValorManoCrupier() const;               // Valor total de la mano
    void limpiarMano();
    void mostrarMano() const;                           // Muestra cartas del crupier
};
#endif // CRUPIER_H