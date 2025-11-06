#include "Tablero.h"
#include <cstdlib>
#include <ctime>

Tablero::Tablero() {
    inicializarLaberinto();
}

// Valores aleatorios
void Tablero::inicializarLaberinto() {
    srand(time(nullptr));
    
    // Caminos y precipicios 
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            matriz[i][j] = (rand() % 100 < 70) ? 1 : 0;
        }
    }
    
    // Aseguramos que la salida sea válida
    matriz[9][9] = 1;
}

int Tablero::getValor(int x, int y) const {  // Agregamos el const
    if(x >= 0 && x < 10 && y >= 0 && y < 10) {
        return matriz[x][y];
    }
    return -1;
}