#ifndef ACCESORIO_H
#define ACCESORIO_H

#include <string>
#include <iostream>

class Accesorio {
    std::string tipo;
    std::string marca;
    float precio;

public:
    Accesorio(std::string t, std::string m, float p) : tipo(t), marca(m), precio(p) {}

    void mostrarInfo() const {
        std::cout << "Tipo: " << tipo << ", Marca: " << marca << ", Precio: $" << precio << std::endl;
    }

    void indicarCompatibilidad(const std::string &consola) const {
        std::cout << "El accesorio " << tipo << " es compatible con la consola " << consola << "." << std::endl;
    }
};

#endif
