#include "ControladorJuego.h"
#include <iostream>
#include <vector>

ControladorJuego::ControladorJuego() {
    tablero = new Tablero();
    avatar = new Avatar(tablero);
}

ControladorJuego::~ControladorJuego() {
    delete avatar;
    delete tablero;
}

void ControladorJuego::iniciarJuego() {
    std::cout << "¡Juego iniciado!" << std::endl;
    std::cout << "Posición inicial: [" 
              << avatar->getPosicion()->getX() << "," 
              << avatar->getPosicion()->getY() << "]" << std::endl;
}

bool ControladorJuego::ejecutarMovimiento(int direccion) {
    Posicion nuevaPos;
    
    switch(direccion) {
        case 1: return avatar->mover(0, -1, nuevaPos);
        case 2: return avatar->mover(0, 1, nuevaPos);
        case 3: return avatar->mover(-1, 0, nuevaPos);
        case 4: return avatar->mover(1, 0, nuevaPos);
        default: return false;
    }
}

// NUEVO: Búsqueda automática
bool ControladorJuego::buscarSalidaAutomatica() {
    bool visitado[10][10] = {false};
    Posicion actual = *avatar->getPosicion();
    
    return buscarSalidaRecursivo(actual, visitado);
}

// NUEVO: Algoritmo DFS recursivo
bool ControladorJuego::buscarSalidaRecursivo(Posicion& actual, bool visitado[10][10]) {
    // Caso base: llegamos a la salida
    if(tablero->esSalida(actual)) {
        return true;
    }
    
    int x = actual.getX();
    int y = actual.getY();
    
    // Marcar como visitado
    visitado[x][y] = true;
    // FALTA: registrar en caminoRecorrido (ERROR intencional)
    
    // Direcciones: arriba, derecha, abajo, izquierda
    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};
    
    // Explorar en 4 direcciones
    for(int i = 0; i < 4; i++) {
        Posicion siguiente(x + dx[i], y + dy[i]);
        
        if(tablero->esCaminoValido(siguiente) && 
           !visitado[siguiente.getX()][siguiente.getY()]) {
            
            if(buscarSalidaRecursivo(siguiente, visitado)) {
                avatar->actualizarPosicion(&siguiente);
                return true;
            }
        }
    }
    
    return false;  // Backtracking
}