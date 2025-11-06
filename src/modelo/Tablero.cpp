#include "Tablero.h"
#include <cstdlib>
#include <ctime>

// Constructor con la lista de inicialización 
Tablero::Tablero() : salida(9, 9) {
    inicializarLaberinto();
}

// Llenar matriz con valores aleatorios 
void Tablero::inicializarLaberinto() {
    srand(time(nullptr));
    
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            matriz[i][j] = (rand() % 100 < 70) ? 1 : 0;
        }
    }
    
    // Asegurar caminos válidos
    matriz[9][9] = 1;  // Salida
    matriz[0][0] = 1;  // Posibles inicios
    matriz[0][1] = 1;
    matriz[1][0] = 1;
}

// Paso por referencia constante
bool Tablero::esCaminoValido(const Posicion& pos) const {
    int x = pos.getX();
    int y = pos.getY();
    
    // Verificar límites del tablero 
    if(x < 0 || x >= 10 || y < 0 || y >= 10) {
        return false;
    }
    
    // Verificar que sea camino (1) no precipicio (0)
    return matriz[x][y] == 1;
}

// Verifica si la posición recibida es salida
bool Tablero::esSalida(const Posicion& pos) const {
    return pos.esIgual(salida);
}

int Tablero::getValor(int x, int y) const {
    if(x >= 0 && x < 10 && y >= 0 && y < 10) {
        return matriz[x][y];
    }
    return -1;
}