#include "Posicion.h"

Posicion::Posicion() {
    x = 0;
    y = 0;
}

int Posicion::getX() {
    return x;
}

int Posicion::getY() {
    return y;
}

// Implementación de los setters
void Posicion::setX(int nx) {
    x = nx;
}

void Posicion::setY(int ny) {
    y = ny;
}