#include <iostream>
#include <vector>

using namespace std;


class Trabajador {
private:
    string nombre;
    vector<Trabajador*> companeros;

public:
    Trabajador(string nombre) : nombre(nombre) {}

    void agregarCompanero(Trabajador* companero) {
        companeros.push_back(companero);
    }

    string getNombre() const {
        return nombre;
    }

    vector<Trabajador*> getCompaneros() const {
        return companeros;
    }
};

class Gerente : public Trabajador {
private:
    vector<Trabajador*> trabajadoresACargo;

public:
    Gerente(string nombre) : Trabajador(nombre) {}

    void asignarTrabajador(Trabajador* trabajador) {
        trabajadoresACargo.push_back(trabajador);
    }

    vector<Trabajador*> getTrabajadoresACargo() const {
        return trabajadoresACargo;
    }
};

int main() {

    Trabajador t1("Juan");
    Trabajador t2("María");
    Trabajador t3("Pedro");
    Trabajador t4("Ana");

    Gerente gerente("Carlos");

    t1.agregarCompanero(&t2);
    t1.agregarCompanero(&t3);
    t1.agregarCompanero(&t4);
    
    t2.agregarCompanero(&t2);
    t2.agregarCompanero(&t3);
    t2.agregarCompanero(&t4);

    t3.agregarCompanero(&t2);
    t3.agregarCompanero(&t3);
    t3.agregarCompanero(&t4);

    t4.agregarCompanero(&t2);
    t4.agregarCompanero(&t3);
    t4.agregarCompanero(&t4);
    
    gerente.asignarTrabajador(&t1);
    gerente.asignarTrabajador(&t2);
    gerente.asignarTrabajador(&t3);
    gerente.asignarTrabajador(&t4);

    cout << "Trabajador " << t1.getNombre() << " tiene los siguientes compañeros:\n";
    for (const auto& companero : t1.getCompaneros()) {
        cout << " - " << companero->getNombre() << endl;
    }

    cout << "El gerente " << gerente.getNombre() << " tiene los siguientes trabajadores a su cargo:\n";
    for (const auto& trabajador : gerente.getTrabajadoresACargo()) {
        cout << " - " << trabajador->getNombre() << endl;
    }

    return 0;
}
