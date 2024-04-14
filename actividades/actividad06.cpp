#include <iostream>
#include <string>

using namespace std;

// Paso 2: Definir la clase del objeto que se compone
class Habitacion {
private:
    string tipo;

public:
    Habitacion(string tipo) : tipo(tipo) {}

    string getTipo() const {
        return tipo;
    }
};

// Paso 1: Definir la clase base que represente la entidad principal de la relación de composición
class Casa {
private:
    Habitacion* habitacion;

public:
    // Paso 3: Implementar un constructor en la clase base que inicialice el objeto compuesto
    Casa(string tipoHabitacion) {
        habitacion = new Habitacion(tipoHabitacion);
    }

    // Paso 4: Implementar un destructor en la clase base que destruya el objeto compuesto y libere su memoria
    ~Casa() {
        delete habitacion;
    }

    // Paso 5: Implementar un método en la clase base para acceder al objeto compuesto
    Habitacion& obtenerHabitacion() const {
        return *habitacion;
    }
};

int main() {
    // Paso 6: Crear un objeto de la clase base y un objeto de la clase que se compone
    // Paso 7: Inicializar el objeto compuesto del objeto de la clase base utilizando el constructor implementado
    Casa miCasa("Dormitorio");

    // Paso 8: Acceder al objeto compuesto utilizando el método implementado
    Habitacion& habitacion = miCasa.obtenerHabitacion();
    cout << "Tipo de habitación en mi casa: " << habitacion.getTipo() << endl;



    return 0;
}
