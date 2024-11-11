#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <string>
#include <iostream>

class Videojuego {
    std::string titulo;
    std::string genero;
    float precio;

public:
    Videojuego(std::string t, std::string g, float p) : titulo(t), genero(g), precio(p) {}

    void mostrarInfo() const {
        std::cout << "Título: " << titulo << ", Género: " << genero << ", Precio: $" << precio << std::endl;
    }

    void aplicarDescuento(float porcentaje) {
        precio -= precio * (porcentaje / 100);
    }
};

#endif
