#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

class Autor {
private:
    string nombre;
    string nacionalidad;
    vector<string> librosEscritos;

public:
    Autor(string nombre, string nacionalidad) : nombre(nombre), nacionalidad(nacionalidad) {}

    void agregarLibroEscrito(string tituloLibro) {
        librosEscritos.push_back(tituloLibro);
    }
};

class Libro {
private:
    string ISBN;
    string titulo;
    int anioPublicacion;
    int cantidadEjemplares;
    Autor* autorAsociado;

public:
    Libro(string ISBN, string titulo, int anioPublicacion, int cantidadEjemplares, Autor* autorAsociado)
        : ISBN(ISBN), titulo(titulo), anioPublicacion(anioPublicacion), cantidadEjemplares(cantidadEjemplares), autorAsociado(autorAsociado) {}
};

class Usuario {
private:
    string nombre;
    string direccion;
    string numeroTelefono;
    map<Libro*, time_t> librosPrestados;

public:
    Usuario(string nombre, string direccion, string numeroTelefono)
        : nombre(nombre), direccion(direccion), numeroTelefono(numeroTelefono) {}

    void prestarLibro(Libro* libro) {
        time_t now = time(0);
        librosPrestados[libro] = now;
    }

    void devolverLibro(Libro* libro) {
        librosPrestados.erase(libro);
    }
};

int main() {
    // Ingresar datos de un autor
    string nombreAutor, nacionalidadAutor;
    cout << "Ingrese el nombre del autor: ";
    getline(cin, nombreAutor);
    cout << "Ingrese la nacionalidad del autor: ";
    getline(cin, nacionalidadAutor);

    Autor autor1(nombreAutor, nacionalidadAutor);

    // Ingresar datos de un libro
    string ISBN, tituloLibro;
    int anioPublicacion, cantidadEjemplares;

    cout << "Ingrese el ISBN del libro: ";
    getline(cin, ISBN);
    cout << "Ingrese el título del libro: ";
    getline(cin, tituloLibro);
    cout << "Ingrese el año de publicación del libro: ";
    cin >> anioPublicacion;
    cout << "Ingrese la cantidad de ejemplares del libro: ";
    cin >> cantidadEjemplares;

    Libro libro1(ISBN, tituloLibro, anioPublicacion, cantidadEjemplares, &autor1);

    cin.ignore();  // Ignorar el salto de línea después de ingresar un número

    // Ingresar datos de un usuario
    string nombreUsuario, direccionUsuario, numeroTelefonoUsuario;
    cout << "Ingrese el nombre del usuario: ";
    getline(cin, nombreUsuario);
    cout << "Ingrese la dirección del usuario: ";
    getline(cin, direccionUsuario);
    cout << "Ingrese el número de teléfono del usuario: ";
    getline(cin, numeroTelefonoUsuario);

    Usuario usuario1(nombreUsuario, direccionUsuario, numeroTelefonoUsuario);
    usuario1.prestarLibro(&libro1);

    return 0;
}