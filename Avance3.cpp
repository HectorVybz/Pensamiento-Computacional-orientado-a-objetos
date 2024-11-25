#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Clase base Producto
class Producto {
protected:
    string nombre;
    double precio;

public:
    Producto(string nombre, double precio) {
        this->nombre = nombre;
        this->precio = precio;
    }

    string getNombre() {
        return nombre;
    }

    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    double getPrecio() {
        return precio;
    }

    void setPrecio(double precio) {
        this->precio = precio;
    }

    virtual string toString() {
        return "Nombre: " + nombre + ", Precio: " + to_string(precio);
    }
};

// Clases que heredan de Producto
class Accesorio : public Producto {
private:
    string tipo;

public:
    Accesorio(string nombre, double precio, string tipo) : Producto(nombre, precio) {
        this->tipo = tipo;
    }

    string getTipo() {
        return tipo;
    }

    void setTipo(string tipo) {
        this->tipo = tipo;
    }

    string toString() override {
        return Producto::toString() + ", Tipo: " + tipo;
    }
};

class Consola : public Producto {
private:
    string marca;
    string modelo;

public:
    Consola(string nombre, double precio, string marca, string modelo) : Producto(nombre, precio) {
        this->marca = marca;
        this->modelo = modelo;
    }

    string getMarca() {
        return marca;
    }

    void setMarca(string marca) {
        this->marca = marca;
    }

    string getModelo() {
        return modelo;
    }

    void setModelo(string modelo) {
        this->modelo = modelo;
    }

    string toString() override {
        return Producto::toString() + ", Marca: " + marca + ", Modelo: " + modelo;
    }
};

class Videojuego : public Producto {
private:
    string genero;
    string clasificacion;

public:
    Videojuego(string nombre, double precio, string genero, string clasificacion) : Producto(nombre, precio) {
        this->genero = genero;
        this->clasificacion = clasificacion;
    }

    string getGenero() {
        return genero;
    }

    void setGenero(string genero) {
        this->genero = genero;
    }

    string getClasificacion() {
        return clasificacion;
    }

    void setClasificacion(string clasificacion) {
        this->clasificacion = clasificacion;
    }

    string toString() override {
        return Producto::toString() + ", Genero: " + genero + ", Clasificacion: " + clasificacion;
    }
};

// Clase Tienda con agregacion/composicion
class Tienda {
private:
    vector<Producto*> inventario;

public:
    void agregarProducto(Producto* producto) {
        inventario.push_back(producto);
    }

    void eliminarProducto(Producto* producto) {
        for (auto it = inventario.begin(); it != inventario.end(); ++it) {
            if (*it == producto) {
                inventario.erase(it);
                break;
            }
        }
    }

    void mostrarInventario() {
        for (Producto* producto : inventario) {
            cout << producto->toString() << endl;
        }
    }
};

int main() {
    Tienda tienda;

    Accesorio* accesorio = new Accesorio("Control", 59.99, "Gamepad");
    Consola* consola = new Consola("PlayStation 5", 499.99, "Sony", "PS5");
    Videojuego* videojuego = new Videojuego("God of War: Ragnarok", 69.99, "Accion-Aventura", "M");

    tienda.agregarProducto(accesorio);
    tienda.agregarProducto(consola);
    tienda.agregarProducto(videojuego);

    tienda.mostrarInventario();

    tienda.eliminarProducto(accesorio);
    tienda.mostrarInventario();

    delete accesorio;
    delete consola;
    delete videojuego;

    return 0;
}
