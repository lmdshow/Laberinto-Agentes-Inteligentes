#ifndef TABLERO_H
#define TABLERO_H

#include "Posicion.h"

class Tablero {
private:
    int matriz[10][10];
    Posicion salida;  // Relación de composición: Tablero contiene Posicion
    
public:
    Tablero();
    void inicializarLaberinto();
    
    // Validación de caminos (paso por referencia constante)
    bool esCaminoValido(const Posicion& pos) const;
    bool esSalida(const Posicion& pos) const; // Verifica si una posición es salida 
    
    int getValor(int x, int y) const;
    const Posicion& getSalida() const { return salida; } // Getter 
    
};

#endif