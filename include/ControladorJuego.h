#ifndef CONTROLADOR_JUEGO_H
#define CONTROLADOR_JUEGO_H

#include "Tablero.h"
#include "Avatar.h"

class ControladorJuego {
private:
    Tablero* tablero;  // ASOCIACIÓN
    Avatar* avatar;    // ASOCIACIÓN
    
public:
    ControladorJuego();
    ~ControladorJuego();
    
    void iniciarJuego();
    bool ejecutarMovimiento(int direccion);
    
    // FALTAN: getters para acceso desde Vista
};

#endif