#include <iostream>
#include <vector>
using namespace std;

class Curso; // Declaración adelantada para resolver la dependencia circular

class Estudiante {
private:
    string id;
    string nombre;
    vector<Curso*> cursos;

public:
    Estudiante(string id, string nombre) : id(id), nombre(nombre) {}
    string getNombre() const {
        return nombre;
    }
    void agregarCurso(Curso* curso) {
        cursos.push_back(curso);
    }
};

class Docente {
private:
    string id;
    string nombre;
    vector<Curso*> cursos;

public:
    Docente(string id, string nombre) : id(id), nombre(nombre) {}
    string getNombre() const {
        return nombre;
    }
};

class Curso {
private:
    string id;
    string nombre;
    Docente* docente;
    vector<Estudiante*> estudiantes;

public:
    Curso(string id, string nombre) : id(id), nombre(nombre), docente(nullptr) {}
    void agregarEstudiante(Estudiante* newEstudiante) {
        estudiantes.push_back(newEstudiante);
    }
    void asignarDocente(Docente* newDocente) {
        docente = newDocente;
    }
    string getNombre() const {
        return nombre;
    }
};

class Asociacion {
private:
    vector<Estudiante*> estudiantes;
    Docente docente;
    Curso curso;

public:
    Asociacion(vector<Estudiante*> estudiantes, Docente docente, Curso curso)
        : estudiantes(estudiantes), docente(docente), curso(curso) {}

    void verAsociacion() {
        cout << "Relacion terciaria:" << endl;
        cout << "Curso: " << curso.getNombre() << endl;
        cout << "Estudiantes en el curso: " << endl;
        for (auto& estudiante : estudiantes) {
            cout << estudiante->getNombre() << endl;
        }
        cout << "Docente del curso: " << docente.getNombre();
    }
};

int main() {
    Estudiante estudiante1("1", "Juan");
    Estudiante estudiante2("2", "María");

    Docente docente1("101", "Profesor López");
    Curso curso1("C001", "Cálculo");

    curso1.agregarEstudiante(&estudiante1);
    curso1.agregarEstudiante(&estudiante2);
    curso1.asignarDocente(&docente1);

    vector<Estudiante*> estudiantes = {&estudiante1, &estudiante2};
    Asociacion asociacion(estudiantes, docente1, curso1);

    asociacion.verAsociacion();

    return 0;
}
