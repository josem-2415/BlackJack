# Proyecto Blackjack en C++

## Descripción

Este es un proyecto de **Blackjack** (21) desarrollado en **C++** como práctica de Programación Orientada a Objetos.
El jugador compite contra el crupier apostando dinero y tomando decisiones para acercarse lo más posible a 21 sin pasarse.

## Funcionalidades principales

* Sistema de apuestas con saldo inicial.
* Reparto de cartas aleatorio mediante la clase `Mazo`.
* Clases bien estructuradas:

  * `Carta`: Representa una carta del mazo.
  * `Mazo`: Administra y reparte cartas.
  * `Jugador`: Maneja las cartas y el saldo del jugador.
  * `Crupier`: Controla la lógica del crupier.
  * `Apuesta`: Calcula ganancias o pérdidas.
  * `MenuJuego`: Determina el ganador de la partida.
* Control de flujo mediante un menú interactivo.
* Reinicio automático del mazo cuando se agota.

## Estructura del proyecto

```
Proyecto_Blackjack/
│
├── Apuesta.h / Apuesta.cpp
├── Carta.h / Carta.cpp
├── Crupier.h / Crupier.cpp
├── Jugador.h / Jugador.cpp
├── Mazo.h / Mazo.cpp
├── MenuJuego.h / MenuJuego.cpp
├── main.cpp
├── README.md
└── .gitignore
```

## Cómo compilar y ejecutar

Asegúrate de tener **g++** instalado.
En la carpeta raíz del proyecto, ejecuta:

```bash
g++ -std=c++17 -o blackjack main.cpp MenuJuego.cpp Mazo.cpp Jugador.cpp Crupier.cpp Carta.cpp Apuesta.cpp
```

Luego ejecuta el programa:

```bash
./blackjack
```

## Reglas del juego

1. El jugador inicia con un saldo inicial (definido en el código).
2. Se elige una cantidad para apostar.
3. Se reparten **dos cartas al jugador** y **una visible + una oculta al crupier**.
4. El jugador puede **pedir cartas** o **plantarse**.
5. El crupier pedirá cartas hasta alcanzar 17 o más puntos.
6. Gana quien esté más cerca de 21 sin pasarse.
7. Si el jugador gana, su saldo aumenta según su apuesta. Si pierde, se descuenta.

## Autores

**Nombres:** Jose Cardona, Nerie Vasquez, Sebastian Valencia, Andres Rodriguez
**Curso:** Fundamentos de Programación Orientada a Objetos
**Institución:** Universidad del Valle
**Año:** 2025