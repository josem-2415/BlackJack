
/*
===============================================================================
                                CRC - Mazo
===============================================================================

Clase:
    Mazo

Responsabilidades:
    - Contener todas las cartas del juego.
    - Barajar el conjunto de cartas aleatoriamente.
    - Repartir cartas a los jugadores o crupier.
    - Llevar el conteo de cartas restantes.

Colaboración:
    - Carta (para componer el mazo con objetos de carta).

Creadores:
    - Andrés Felipe Rodríguez García 2539555
    - José Manuel Cardona 2521653
    - Nerie Vásquez Díaz 2519638
===============================================================================
*/

#ifndef MAZO_H
#define MAZO_H
#include <vector>
#include "Carta.h"
using namespace std;

class Mazo {
private:
    vector<Carta> cartas; // Vector de cartas en el mazo

public:
    Mazo();
    void barajar();             // Mezcla las cartas
    Carta repartirCarta();      // Devuelve y elimina la carta superior
    void inicializarMazo();
    int cartasRestantes() const; // Devuelve el número de cartas restantes
};
#endif // MAZO_H