#include "Tablero.h"

Tablero::Tablero() {
    inicializarLaberinto();
}

void Tablero::inicializarLaberinto() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            matriz[i][j] = 1;
        }
    }
}

int Tablero::getValor(int x, int y) {
    return matriz[x][y];  
}