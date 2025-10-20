/*
===============================================================================
                                CRC - Jugador
===============================================================================

Clase:
    Jugador

Responsabilidades:
    - Representar al jugador humano dentro del juego.
    - Solicitar y recibir cartas desde el mazo.
    - Calcular el valor de su mano y determinar si tiene Blackjack.
    - Realizar y registrar apuestas.
    - Actualizar su saldo según el resultado de la partida.

Colaboración:
    - Mazo (para obtener nuevas cartas).
    - Apuesta (para registrar los montos apostados).
    - Crupier (para comparar resultados y determinar ganadores).

Creadores:
    - Andrés Felipe Rodríguez García 2539555
    - José Manuel Cardona 2521653
    - Nerie Vásquez Díaz 2519638
===============================================================================
*/

#ifndef JUGADOR_H
#define JUGADOR_H
#include <vector>
#include "Carta.h"
#include "Mazo.h"
#include "Apuesta.h"
using namespace std;

class Jugador {
private:
    vector<Carta> mano;     // Cartas del jugador
    double saldoActual;     // Dinero disponible
    Apuesta apuestaActual;  // Apuesta actual del jugador
    
public:
    // Constructor
    Jugador(double saldo = 1000.0);

    // Metodos
    void pedirCarta(Mazo& mazo);           // Toma una carta del mazo
    void mostrarMano() const;              // Muestra todas las cartas
    int calcularValorManoJugador() const;  // Suma de valores de la mano
    bool tieneBlackjack() const;           // Determina si tiene 21 con 2 cartas
    void realizarApuesta(double monto);    // Registra una nueva apuesta
    void actualizarSaldo(const std::string& resultado, double monto); // Ajusta saldo tras partida
    void limpiarMano();          // Limpia la mano del jugador

    // Getter
    double getSaldo() const; // Devuelve el saldo actual

};
#endif // JUGADOR_H