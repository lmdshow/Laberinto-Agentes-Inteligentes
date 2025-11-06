#ifndef CONTROLADOR_JUEGO_H
#define CONTROLADOR_JUEGO_H

#include "Tablero.h"
#include "Avatar.h"
#include <vector>

class ControladorJuego {
private:
    Tablero* tablero;
    Avatar* avatar;
    std::vector<Posicion> caminoRecorrido;
    
    // Búsqueda recursiva (paso por referencia)
    bool buscarSalidaRecursivo(Posicion& actual, bool visitado[10][10]);
    
public:
    ControladorJuego();
    ~ControladorJuego();
    
    void iniciarJuego();
    bool ejecutarMovimiento(int direccion);
    bool buscarSalidaAutomatica();  // NUEVO
    
    const Tablero& getTablero() const { return *tablero; }
    const Avatar& getAvatar() const { return *avatar; }
};

#endif