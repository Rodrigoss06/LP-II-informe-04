#include <iostream>
#include <string>

using namespace std;

// Paso 1: Definir una clase base que contenga los atributos y métodos comunes a las clases que heredarán de ella
class Animal {
protected:
    string nombre;
    int edad;

public:
    Animal(string _nombre, int _edad) : nombre(_nombre), edad(_edad) {}

    string getNombre() const {
        return nombre;
    }

    int getEdad() const {
        return edad;
    }

    virtual void hacerSonido() const = 0;
};

class Perro : public Animal {
private:
    string raza;

public:
    Perro(string _nombre, int _edad, string _raza) : Animal(_nombre, _edad), raza(_raza) {}


    ~Perro() {
        cout << "Destructor de Perro llamado para " << nombre << endl;
    }

    string getRaza() const {
        return raza;
    }

    void hacerSonido() const override {
        cout << nombre << " ladra: ¡Guau guau!" << endl;
    }
};

int main() {
    Perro miPerro("Fido", 5, "Labrador");


    cout << "Nombre: " << miPerro.getNombre() << endl;
    cout << "Edad: " << miPerro.getEdad() << " años" << endl;


    cout << "Raza: " << miPerro.getRaza() << endl;


    miPerro.hacerSonido();

    return 0;
}
