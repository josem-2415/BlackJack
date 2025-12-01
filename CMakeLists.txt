cmake_minimum_required(VERSION 3.26)
project(Blackjack)

set(CMAKE_CXX_STANDARD 17)

add_executable(Blackjack
    main.cpp
    Apuesta.cpp
    Carta.cpp
    Controlador.cpp
    Crupier.cpp
    Jugador.cpp
    Mazo.cpp
    Participante.cpp
)
