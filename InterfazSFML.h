/*

*/

#ifndef INTERFAZ_SFML_H
#define INTERFAZ_SFML_H

#include <SFML/Graphics.hpp>
#include <map>
#include "Controlador.h"

class InterfazSFML {
private:
    sf::RenderWindow ventana;
    sf::Font fuente;
    sf::Text titulo;
    sf::Text textoResultado;

    sf::RectangleShape botonJugar, botonPedir, botonPlantarse;
    sf::Text textoBotonJugar, textoBotonPedir, textoBotonPlantarse;

    Controlador controlador;
    bool juegoTerminado;
    bool mostrarCartasCrupier;

    std::map<std::string, sf::Texture> texturas;

    void configurarBoton(sf::RectangleShape& boton, sf::Text& texto, const std::string& textoStr, float x, float y);
    bool clicEnBoton(const sf::RectangleShape& boton);
    void dibujarCartasJugador();
    void dibujarCartasCrupier();

    std::string obtenerResultadoFinal(int jugadorIndex);

public:
    InterfazSFML();
    void ejecutar();
    void procesarEventos();
    void actualizar();
    void dibujar();
};

#endif //PROYECTO_BLACKJACK_INTERFAZSML_H