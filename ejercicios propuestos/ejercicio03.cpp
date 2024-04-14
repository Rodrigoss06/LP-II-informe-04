#include <iostream>
#include <vector>
#include <stdexcept> 

using namespace std;

class Profesor;
class Asignatura;
class Estudiante;

class Calificaciones {
private:
    Asignatura* asignatura;
    float nota;

public:
    Calificaciones(Asignatura& asignatura, float nota) : asignatura(&asignatura), nota(nota) {}

    Asignatura& getAsignatura() const {
        return *asignatura;
    }

    float getNota() const {
        return nota;
    }
};


class Asignatura {
private:
    string codigo;
    string nombre;
    string descripcion;
    Profesor* profesor;
    vector<Estudiante*> estudiantes;

public:
    Asignatura(string codigo, string nombre, string descripcion): codigo(codigo), nombre(nombre), descripcion(descripcion), profesor(nullptr) {}

    void asignarProfesor(Profesor& profe);

    void agregarEstudiante(Estudiante& newEstudiante);

    string getCodigo() const {
        return codigo;
    }

    string getNombre() const {
        return nombre;
    }

    string getDescripcion() const {
        return descripcion;
    }

    Profesor* getProfesor() const {
        return profesor;
    }
};

class Estudiante {
private:
    string nombre;
    string direccion;
    string matricula_id;
    vector<Asignatura*> asignaturas;
    vector<Calificaciones> calificaciones;

public:
    Estudiante(string nombre, string direccion, string matricula_id): nombre(nombre), direccion(direccion), matricula_id(matricula_id) {}

    void matricularseEnAsignatura(Asignatura& asignatura) {
        asignaturas.push_back(&asignatura);
        asignatura.agregarEstudiante(*this);
    }

    string getNombre() const {
        return nombre;
    }

    string getDireccion() const {
        return direccion;
    }

    string getMatriculaId() const {
        return matricula_id;
    }

    vector<Asignatura*> getAsignaturas() const {
        return asignaturas;
    }

    vector<Calificaciones> getCalificaciones() const {
        return calificaciones;
    }

    friend class Profesor;
};

class Profesor {
private:
    string nombre;
    string direccion;
    int telefono;
    vector<Asignatura*> asignaturas_impartidas;

public:
    Profesor(string nombre, string direccion, int telefono) : nombre(nombre), direccion(direccion), telefono(telefono) {}

    void calificar(Asignatura& asignatura, Estudiante& estudiante, float nota) {
        bool encontrada = false;
        for (const Asignatura* asignatura_profesor : asignaturas_impartidas) {
            if (asignatura_profesor == &asignatura) {
                encontrada = true;
                break;
            }
        }

        if (!encontrada) {
            throw runtime_error("El profesor no imparte la asignatura proporcionada.");
        }

        Calificaciones calificacion(asignatura, nota);
        estudiante.calificaciones.push_back(calificacion);
        cout << "El estudiante " << estudiante.getNombre() << " ha sido calificado en la asignatura "<< asignatura.getCodigo() << " con nota " << nota << endl;
    }

    string getNombre() const {
        return nombre;
    }

    string getDireccion() const {
        return direccion;
    }

    int getTelefono() const {
        return telefono;
    }

    vector<Asignatura*> getAsignaturasImpartidas() const {
        return asignaturas_impartidas;
    }

    void agregarAsignatura(Asignatura& asignatura) {
        asignaturas_impartidas.push_back(&asignatura);
    }
};

void Asignatura::asignarProfesor(Profesor& profe) {
    profesor = &profe;
    profe.agregarAsignatura(*this);
}

void Asignatura::agregarEstudiante(Estudiante& newEstudiante){
    estudiantes.push_back(&newEstudiante);
}
int main() {
    Profesor profesor("Profesor López", "Dirección 123", 123456789);

    Asignatura matematicas("MAT01", "Matemáticas", "Asignatura de matemáticas");
    Asignatura historia("HIS01", "Historia", "Asignatura de historia");

    matematicas.asignarProfesor(profesor);
    historia.asignarProfesor(profesor);

    Estudiante estudiante("Juan", "Calle 123", "ABC123");

    estudiante.matricularseEnAsignatura(matematicas);
    estudiante.matricularseEnAsignatura(historia);

    try {
        profesor.calificar(matematicas, estudiante, 8.5);
        profesor.calificar(historia, estudiante, 12.3);
    } catch (const exception& e) {
        cerr << "Error al calificar: " << e.what() << endl;
    }

    cout << "Datos del estudiante:" << endl;
    cout << "Nombre: " << estudiante.getNombre() << endl;
    cout << "Dirección: " << estudiante.getDireccion() << endl;
    cout << "Matrícula ID: " << estudiante.getMatriculaId() << endl;

    cout << "Asignaturas matriculadas:" << endl;
    vector<Asignatura*> asignaturas = estudiante.getAsignaturas();
    for (const Asignatura* asignatura : asignaturas) {
        cout << "   - Código: " << asignatura->getCodigo() << endl;
        cout << "     Nombre: " << asignatura->getNombre() << endl;
        cout << "     Descripción: " << asignatura->getDescripcion() << endl;
        cout << endl;
    }

    cout << "Calificaciones:" << endl;
    vector<Calificaciones> calificaciones = estudiante.getCalificaciones();
    for (const Calificaciones& calificacion : calificaciones) {
        cout << "   - Asignatura: " << calificacion.getAsignatura().getNombre() << endl;
        cout << "     Nota: " << calificacion.getNota() << endl;
        cout << endl;
    }

    return 0;
}
