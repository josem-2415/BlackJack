/*
===============================================================================
                                CRC - Participante
===============================================================================

Clase:
    Participante

Responsabilidades:
    - Calcular el valor del participante (crupier o jugador).
    - Mostrar las cartas del crupier y.
    - Controlar la lógica del turno del crupier.

Creadores:
    - Andrés Felipe Rodríguez García 2539555
    - José Manuel Cardona 2521653
    - Nerie Vásquez Díaz 2519638
===============================================================================
*/

#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H
#include <vector>
#include "Carta.h"
#include "Mazo.h"
using namespace std;

class Participante {
protected:
    vector<Carta> mano; // Cartas del crupier
    
public:
    Participante ();
    // Metodos
    int calcularValorMano() const;               // Valor total de la mano
    void pedirCarta(Mazo &mazo);                     // Toma una carta del mazo
    void mostrarMano() const;                           // Muestra cartas del participante
    void limpiarMano();                         // Limpia la mano del participante
};
#endif // CRUPIER_H