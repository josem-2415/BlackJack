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
#include "Participante.h"
using namespace std;

class Crupier : public Participante {
public:
    // Metodos
    Crupier();

    void preguntarCarta(Mazo& mazo);              // Pregunta si quiere más
    void mostrarPrimeraCarta();                     // Muestra la primera carta del crupier
    void repartirInicial(Mazo& mazo, Jugador& jugador);                   // Reparte las cartas a crupier y jugador
};
#endif // CRUPIER_H