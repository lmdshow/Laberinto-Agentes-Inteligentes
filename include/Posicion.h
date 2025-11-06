#ifndef POSICION_H
#define POSICION_H

class Posicion {
private:
    int x;
    int y;

public:
    // Constructor con parámetros y valores por defecto
    Posicion(int x = 0, int y = 0);
    
    // Getters
    int getX() const { return x; }
    int getY() const { return y; }
    
    // Setters
    void setX(int nx) { x = nx; }
    void setY(int ny) { y = ny; }
    
    // Método para comparar las posiciones
    bool esIgual(const Posicion& otra) const;
};

#endif