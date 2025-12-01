#include "InterfazSFML.h"
#include <iostream>

InterfazSFML::InterfazSFML()
    : ventana(sf::VideoMode(1000, 600), "BlackJack"),
      juegoTerminado(false),
      mostrarCartasCrupier(false)
{
    if (!fuente.loadFromFile("resources/arial.ttf")) {
        std::cerr << "No se pudo cargar la fuente." << std::endl;
    }

    titulo.setFont(fuente);
    titulo.setString("BlackJack");
    titulo.setCharacterSize(48);
    titulo.setFillColor(sf::Color::White);
    titulo.setPosition(350, 20);

    configurarBoton(botonJugar, textoBotonJugar, "JUGAR", 750, 100);
    configurarBoton(botonPedir, textoBotonPedir, "PEDIR CARTA", 750, 180);
    configurarBoton(botonPlantarse, textoBotonPlantarse, "PLANTARSE", 750, 260);

    textoResultado.setFont(fuente);
    textoResultado.setCharacterSize(22);
    textoResultado.setFillColor(sf::Color::White);
    textoResultado.setPosition(100, 500);
    textoResultado.setString("");

    juego.agregarJugador();
}

void InterfazSFML::configurarBoton(sf::RectangleShape& boton, sf::Text& texto, const std::string& textoStr, float x, float y) {
    boton.setSize(sf::Vector2f(200, 50));
    boton.setPosition(x, y);
    boton.setFillColor(sf::Color::Green);

    texto.setFont(fuente);
    texto.setString(textoStr);
    texto.setCharacterSize(20);
    texto.setFillColor(sf::Color::Black);
    texto.setPosition(x + 30, y + 10);
}

void InterfazSFML::ejecutar() {
    while (ventana.isOpen()) {
        procesarEventos();
        actualizar();
        dibujar();
    }
}

void InterfazSFML::procesarEventos() {
    sf::Event evento;
    while (ventana.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed)
            ventana.close();

        if (evento.type == sf::Event::MouseButtonPressed) {
            if (clicEnBoton(botonJugar)) {
                juego.iniciarJuego();
                textoResultado.setString("¡Partida iniciada! Valor inicial: " +
                    std::to_string(juego.getJugador(0).calcularValorMano()));
                juegoTerminado = false;
                mostrarCartasCrupier = false;
            }

            if (clicEnBoton(botonPedir) && !juegoTerminado) {
                juego.jugadorPideCarta(0);
                int valor = juego.getJugador(0).calcularValorMano();
                textoResultado.setString("Pediste carta. Total: " + std::to_string(valor));

                if (valor > 21) {
                    textoResultado.setString("Te pasaste con " + std::to_string(valor) + ". Pierdes.");
                    juegoTerminado = true;
                    mostrarCartasCrupier = true;
                }
            }

            if (clicEnBoton(botonPlantarse) && !juegoTerminado) {
                juego.turnoCrupier();
                textoResultado.setString(juego.obtenerResultadoFinal(0));
                juegoTerminado = true;
                mostrarCartasCrupier = true;
            }
        }
    }
}


void InterfazSFML::actualizar() {

}

void InterfazSFML::dibujar() {
    ventana.clear(sf::Color(40, 40, 40));
    ventana.draw(titulo);
    ventana.draw(botonJugar);
    ventana.draw(textoBotonJugar);
    ventana.draw(botonPedir);
    ventana.draw(textoBotonPedir);
    ventana.draw(botonPlantarse);
    ventana.draw(textoBotonPlantarse);

    dibujarCartasJugador();
    dibujarCartasCrupier();

    ventana.draw(textoResultado);
    ventana.display();
}

bool InterfazSFML::clicEnBoton(const sf::RectangleShape& boton) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(ventana);
    return boton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}

void InterfazSFML::dibujarCartasJugador() {
    const auto& cartas = juego.getJugador(0).getCartas();
    for (size_t i = 0; i < cartas.size(); ++i) {
        std::string ruta = cartas[i].obtenerRutaImagen();
        if (!texturas[ruta].loadFromFile(ruta)) {
            std::cerr << "No se pudo cargar la carta: " << ruta << std::endl;
            continue;
        }
        sf::Sprite sprite(texturas[ruta]);
        sprite.setScale(0.5f, 0.5f);
        sprite.setPosition(100 + i * 90, 400);
        ventana.draw(sprite);
    }
}

void InterfazSFML::dibujarCartasCrupier() {
    const auto& cartas = juego.getCrupier().getCartas();
    for (size_t i = 0; i < cartas.size(); ++i) {
        std::string ruta;
        if (i == 0 && !mostrarCartasCrupier) {
            ruta = "resources/cartas/back.png";
        } else {
            ruta = cartas[i].obtenerRutaImagen();
        }

        if (!texturas[ruta].loadFromFile(ruta)) {
            std::cerr << "No se pudo cargar la carta: " << ruta << std::endl;
            continue;
        }

        sf::Sprite sprite(texturas[ruta]);
        sprite.setScale(0.5f, 0.5f);
        sprite.setPosition(100 + i * 90, 200);
        ventana.draw(sprite);
    }
}