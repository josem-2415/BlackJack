#ifndef VISTA_H
#define VISTA_H
#include <iostream>
#include <string>
using namespace std;

class Vista {
public:
    Vista();

    void bienvenida();
    void mostrarResultado(string resultado, double monto, int valor);
    void tunroCrupier();
};
#endif // VISTA_H