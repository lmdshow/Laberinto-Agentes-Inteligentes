#ifndef CONTROLADOR_JUEGO_H
#define CONTROLADOR_JUEGO_H

#include "Tablero.h"
#include "Avatar.h"

class ControladorJuego {
private:
    Tablero* tablero;
    Avatar* avatar;
    
public:
    ControladorJuego();
    ~ControladorJuego();
    
    void iniciarJuego();
    bool ejecutarMovimiento(int direccion);
    
    // NUEVO: Getters con paso por referencia constante
    const Tablero& getTablero() const { return *tablero; }
    const Avatar& getAvatar() const { return *avatar; }
};

#endif