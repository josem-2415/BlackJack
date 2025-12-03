#include "Vista.h"
#include <iostream>

Vista::Vista() {}

void Vista::bienvenida() {
    cout << "=========================================\n";
    cout << "           Bienvenido al Blackjack       \n";
    cout << "=========================================\n";
}

void Vista::mostrarResultado(string resultado, double monto, int valor) {
    if (resultado == "gana" && valor == 21) {
        cout << "\n----------------------------------------" << endl;            
        cout << "¡Tienes BlackJack! Ganaste automaticamente." << monto * 2 << "!" << endl;
        cout << "----------------------------------------\n";
    } 
    else if (resultado == "gana") {
        cout << "\n---------------------------------------"<< endl;
        cout << "¡Ganaste $" << monto * 2 << "!" << endl;
        cout << "---------------------------------------\n\n";
    }
    else if (resultado == "empate") {
        cout << "\n---------------------------------------"<< endl;
        cout << "Empate. Recuperas tu apuesta de $" << monto << "." << endl;
        cout << "---------------------------------------\n\n";
    }
    else if (resultado == "pierde" && valor > 21) {
        cout << "\n---------------------------------------"<< endl;
        cout << "Te pasaste. Perdiste tu apuesta de $" << monto << "." << endl;
        cout << "---------------------------------------\n\n";
    }
    else {
        cout << "\n---------------------------------------"<< endl;
        cout << "Perdiste tu apuesta de $" << monto << "." << endl;
        cout << "---------------------------------------\n\n";
    }
}

void Vista::tunroCrupier(){
    cout << "\n---------------------------------------" << endl;
    cout << "Turno del crupier..." << endl;
    cout << "---------------------------------------\n";
}