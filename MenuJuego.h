/*
===============================================================================
                                CRC - MenuJuego
===============================================================================

Clase:
    MenuJuego

Responsabilidades:
    - Controlar la interacción general del juego.
    - Iniciar y reiniciar partidas de Blackjack.
    - Coordinar el flujo entre jugador, crupier, mazo y apuestas.
    - Determinar al ganador de la partida.
    - Gestionar las apuestas y actualizar los saldos.

Colaboración:
    - Jugador (para gestionar al jugador humano).
    - Crupier (para controlar la banca).
    - Mazo (para gestionar las cartas disponibles).
    - Apuesta (para manejar el monto y las ganancias).

Creadores:
    - Andrés Felipe Rodríguez García 2539555
    - José Manuel Cardona 2521653
    - Nerie Vásquez Díaz 2519638
===============================================================================
*/

#ifndef MENUJUEGO_H
#define MENUJUEGO_H
#include "Jugador.h"
#include "Crupier.h"
#include "Mazo.h"
#include "Apuesta.h"
using namespace std;

class MenuJuego {
private:
    Jugador jugador;      // Jugador principal
    Crupier crupier;      // Crupier del juego
    Mazo mazo;            // Mazo de cartas
    Apuesta apuestaActual;// Apuesta en curso

public:
    // Constructor
    MenuJuego();

    // Metodos
    void iniciar();                            // Inicia el juego
    string determinarGanador(Jugador& jugador, Crupier& crupier, double monto); // Determina el resultado
    void manejarApuesta(Jugador& jugador, string resultado); // Gestiona apuestas
    void nuevaPartida();                       // Reinicia el juego
};
#endif // MENUJUEGO_H