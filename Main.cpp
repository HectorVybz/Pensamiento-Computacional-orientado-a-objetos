#include "Videojuego.h"
#include "Consola.h"
#include "Accesorio.h"

int main() {
    Videojuego v1("The Legend of Zelda", "Aventura", 59.99);
    Consola c1("Nintendo Switch", "Nintendo", 299.99);
    Accesorio a1("Control Pro", "Nintendo", 69.99);

    v1.mostrarInfo();
    v1.aplicarDescuento(10); // Aplica un descuento del 10%
    v1.mostrarInfo();

    c1.mostrarInfo();
    c1.verificarDisponibilidad();

    a1.mostrarInfo();
    a1.indicarCompatibilidad("Nintendo Switch");

    return 0;
}
