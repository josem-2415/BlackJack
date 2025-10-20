/*
===============================================================================
                                CRC - Carta
===============================================================================

Clase:
    Carta

Responsabilidades:
    - Representar una carta individual con valor y palo.
    - Proveer el valor numérico de la carta.
    - Mostrar la información de la carta por consola.

Colaboración:
    - Ninguna (clase base simple usada por Mazo).

Creadores:
    - Andrés Felipe Rodríguez García 2539555
    - José Manuel Cardona 2521653
    - Nerie Vásquez Díaz 2519638
===============================================================================
*/

#ifndef CARTA_H
#define CARTA_H
#include <string>
using namespace std;

class Carta {
private:
    int valor;         // Valor nominal de la carta (1-11)
    string palo;       // Palo: corazones, tréboles, diamantes o picas

public:
    Carta(int v = 0, string p = "") : valor(v), palo(p) {}
    int getValor() const;    // Devuelve el valor de la carta
    void mostrarCarta() const; // Muestra el valor y palo
};
#endif // CARTA_H