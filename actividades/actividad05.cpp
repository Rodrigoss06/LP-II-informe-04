#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Articulo {
private:
    int id;
    string nombre;
    double precio;

public:
    Articulo(int id, string nombre, double precio) : id(id), nombre(nombre), precio(precio) {}

    int getId() const {
        return id;
    }

    string getNombre() const {
        return nombre;
    }

    double getPrecio() const {
        return precio;
    }
};

class OrdenCompra {
protected:
    vector<Articulo> articulos;

public:
    void agregarArticulo(const Articulo& articulo) {
        articulos.push_back(articulo);
    }

    void eliminarArticulo(int id) {
        articulos.erase(remove_if(articulos.begin(), articulos.end(), [id](const Articulo& art) { return art.getId() == id; }), articulos.end());
    }

    const Articulo& obtenerArticulo(int id) const {
        auto it = find_if(articulos.begin(), articulos.end(), [id](const Articulo& art) { return art.getId() == id; });
        if (it != articulos.end()) {
            return *it;
        } else {
            throw invalid_argument("El artículo con el ID proporcionado no se encontró en la colección.");
        }
    }
};

int main() {
    OrdenCompra orden;

    Articulo articulo1(1, "Camisa", 29.99);
    Articulo articulo2(2, "Pantalón", 39.99);
    Articulo articulo3(3, "Zapatos", 59.99);

    orden.agregarArticulo(articulo1);
    orden.agregarArticulo(articulo2);
    orden.agregarArticulo(articulo3);

    try {
        const Articulo& articuloObtenido = orden.obtenerArticulo(2);
        cout << "Artículo obtenido: " << articuloObtenido.getNombre() << " - Precio: $" << articuloObtenido.getPrecio() << endl;
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    orden.eliminarArticulo(1);

    return 0;
}
