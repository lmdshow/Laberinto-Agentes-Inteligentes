#ifndef POSICION_H
#define POSICION_H

class Posicion {
private:
    int x;
    int y;

public:
    // Constructor 
    Posicion();
    
    // Getters 
    int getX();
    int getY();

    // Setters 
    void setX(int nx);
    void setY(int ny);
    
};

#endif