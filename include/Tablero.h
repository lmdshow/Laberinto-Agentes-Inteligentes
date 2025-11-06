#ifndef TABLERO_H
#define TABLERO_H

#include "Posicion.h"

class Tablero {
private:
    int matriz[10][10];
    
public:
    Tablero();
    void inicializarLaberinto();
    
    // getValor sin validación de límites
    int getValor(int x, int y);
};

#endif