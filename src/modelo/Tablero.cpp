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

  // Se agregó la validación de límites 
int Tablero::getValor(int x, int y) {
    if(x >= 0 && x < 10 && y >= 0 && y < 10) {
        return matriz[x][y];
    }
    return -1;  // Valor inválido para indicar error
}