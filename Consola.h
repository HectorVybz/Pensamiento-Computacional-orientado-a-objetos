#ifndef CONSOLA_H
#define CONSOLA_H

#include <string>
#include <iostream>

class Consola {
    std::string nombre;
    std::string fabricante;
    float precio;

public:
    Consola(std::string n, std::string f, float p) : nombre(n), fabricante(f), precio(p) {}

    void mostrarInfo() const {
        std::cout << "Nombre: " << nombre << ", Fabricante: " << fabricante << ", Precio: $" << precio << std::endl;
    }

    void verificarDisponibilidad() const {
        std::cout << "La consola " << nombre << " está disponible en inventario." << std::endl;
    }
};

#endif
