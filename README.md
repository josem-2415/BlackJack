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
* Control de flujo mediante un menú interactivo.
* Reinicio automático del mazo cuando se agota.

Este proyecto implementa un juego de Blackjack en C++ usando una arquitectura organizada por módulos:

* **Modelo/** → Lógica del juego (Jugador, Crupier, Mazo, Carta, Apuesta, Participante).
* **Controlador/** → Controlador general del flujo del juego.
* **Vista/** → Salidas a consola.
* **tests/** → Pruebas automatizadas con GoogleTest.

El proyecto está configurado para que:

✔ Se compile con **Ctrl + Shift + B** dentro de VSCode (Build Task)
✔ Se ejecute con **F5** (Debug/Run Task)
✔ GoogleTest se descargue automáticamente vía **FetchContent**

---

## Requisitos

* **MSYS2 MinGW-w64 (64 bits)**
* g++ (mingw64)
* CMake
* Ninja (opcional, pero recomendado)
* VSCode + extensiones:

  * *C/C++* (Microsoft)
  * *CMake Tools*

---

## Estructura del proyecto

```
Proyecto_Blackjack/
│ CMakeLists.txt
│ README.md
├── Controlador/
│     └── Controlador.cpp
├── Modelo/
│     ├── Apuesta.cpp
│     ├── Carta.cpp
│     ├── Crupier.cpp
│     ├── Jugador.cpp
│     ├── Mazo.cpp
│     ├── Participante.cpp
│     └── main.cpp
├── Vista/
│     ├── Vista.cpp
│     └── VistaParticipante.cpp
└── tests/
      └── test_blackjack.cpp
```

---

## Compilación con VSCode (Ctrl + Shift + B)

El proyecto ya está configurado para que **VSCode compile automáticamente usando CMake**.

Para compilar:

```
Ctrl + Shift + B
```

Esto ejecuta:

```
cmake --build build
```

El ejecutable se genera en:

```
build/bin/Blackjack.exe
```

---

## Ejecutar el juego con F5

Presiona:

```
F5
```

Esto ejecuta **launch.json**, que lanza:

```
build/bin/Blackjack.exe
```

Si quieres ejecutar desde terminal:

```powershell
./build/bin/Blackjack.exe
```

---

## Ejecutar Tests

Los tests se construyen automáticamente dentro de **build/bin/**:

```powershell
./build/bin/Tests.exe
```

O usando `ctest`:

```powershell
ctest --output-on-failure
```

---

## Comandos manuales (si no usas VSCode)

### 1. Configuración

```powershell
cmake -G "MinGW Makefiles" -B build -S . \
  -DCMAKE_C_COMPILER=C:/msys64/mingw64/bin/gcc.exe \
  -DCMAKE_CXX_COMPILER=C:/msys64/mingw64/bin/g++.exe
```

### 2. Compilación

```powershell
cmake --build build
```

### 3. Ejecutar

```powershell
./build/bin/Blackjack.exe
```

### 4. Ejecutar tests

```powershell
./build/bin/Tests.exe
```

---

## Funcionalidades del juego

* Reparto inicial
* Pedir carta
* Lógica del crupier
* Apuestas
* Blackjack natural
* Comparación de manos
* Reinicio de ronda

---

## Funcionalidades de testing

Se prueban los siguientes módulos:

* **Mazo** (reparto, inicialización, conteo)
* **Participante** (valor de mano, pedir carta)
* **Jugador** (blackjack, apuestas)
* **Crupier** (lógica de pedir hasta 17)
* **Controlador** (ganador, empate, pierde)

---

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
