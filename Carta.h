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
    string valor;
    string palo;

public:
    Carta(const std::string& v = "", const std::string& p = "");
    string getValor() const;
    string getPalo() const;
    void mostrarCarta() const;
};
#endif // CARTA_H