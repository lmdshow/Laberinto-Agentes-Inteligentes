#include "ControladorJuego.h"
#include <iostream>

ControladorJuego::ControladorJuego() {
    tablero = new Tablero();
    avatar = new Avatar(tablero);
}

ControladorJuego::~ControladorJuego() {
    delete avatar;
    delete tablero;
}

void ControladorJuego::iniciarJuego() {
    std::cout << "Juego iniciado!" << std::endl;
}

bool ControladorJuego::ejecutarMovimiento(int direccion) {
    Posicion nuevaPos;
    
    switch(direccion) {
        case 1: return avatar->mover(0, -1, nuevaPos);  // Arriba
        case 2: return avatar->mover(0, 1, nuevaPos);   // Abajo
        case 3: return avatar->mover(-1, 0, nuevaPos);  // Izquierda
        case 4: return avatar->mover(1, 0, nuevaPos);   // Derecha
        default: return false;
    }
}