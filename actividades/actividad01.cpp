#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Curso; // Declaración anticipada de la clase Curso

class Estudiante {
private:
    string nombreEstudiante;
    string apellidoEstudiante;
    int dniEstudiante;
    string correoEstudiante;
    int telefonoEstudiante;
    string direccionEstudiante;
    string apoderadoEstudiante;
    vector<Curso*> cursos; // Usar vector en lugar de arreglo fijo

public:
    Estudiante(string _nombreEstudiante, string _apellidoEstudiante, int _dniEstudiante, string _correoEstudiante, int _telefonoEstudiante, string _direccionEstudiante, string _apoderadoEstudiante) {
        this->nombreEstudiante = _nombreEstudiante;
        this->apellidoEstudiante = _apellidoEstudiante;
        this->dniEstudiante = _dniEstudiante;
        this->correoEstudiante = _correoEstudiante;
        this->telefonoEstudiante = _telefonoEstudiante;
        this->direccionEstudiante = _direccionEstudiante;
        this->apoderadoEstudiante = _apoderadoEstudiante;
    }

    string getNombreEstudiante() {
        return nombreEstudiante;
    }

    void agregarCurso(Curso* curso) {
        cursos.push_back(curso);
    }

    void eliminarCurso(Curso* curso) {
        for (int i = 0; i < cursos.size(); i++) {
            if (cursos[i] == curso) {
                cursos.erase(cursos.begin() + i);
                break;
            }
        }
    }
};

class Curso {
private:
    string nombreCurso;
    int codigoCurso;
    string descripcionCurso;
    string fechaInicioCurso;
    string fechaFinCurso;
    string docenteCurso;
    vector<Estudiante*> estudiantes; // Usar vector en lugar de arreglo fijo

public:
    Curso(string _nombreCurso, int _codigoCurso, string _descripcionCurso, string _fechaInicioCurso, string _fechaFinCurso, string _docenteCurso) {
        this->nombreCurso = _nombreCurso;
        this->codigoCurso = _codigoCurso;
        this->descripcionCurso = _descripcionCurso;
        this->fechaInicioCurso = _fechaInicioCurso;
        this->fechaFinCurso = _fechaFinCurso;
        this->docenteCurso = _docenteCurso;
    }

    string getNombreCurso() {
        return nombreCurso;
    }

    void agregarEstudiante(Estudiante* estudiante) {
        estudiantes.push_back(estudiante);
    }

    void eliminarEstudiante(Estudiante* estudiante) {
        for (int i = 0; i < estudiantes.size(); i++) {
            if (estudiantes[i] == estudiante) {
                estudiantes.erase(estudiantes.begin() + i);
                break;
            }
        }
    }
};

int main(){
    Estudiante estudiante1("Juan", "Pérez", 12345678, "juanperez@mail.com", 12345678, "Calle 123", "Juan Pérez padre");
    Estudiante estudiante2("María", "García", 87654321, "mariagarcia@mail.com", 87654321, "Calle 456", "María García madre");
    Curso curso1("Programación Básica", 100, "Curso introductorio a la programación", "2023-01-01", "2023-12-31", "Profesor X");
    Curso curso2("Matemáticas Avanzadas", 200, "Curso de matemáticas para estudiantes avanzados", "2023-01-01", "2023-12-31", "Profesor Y");

    curso1.agregarEstudiante(&estudiante1);
    curso1.agregarEstudiante(&estudiante2);
    estudiante1.agregarCurso(&curso1);
    estudiante1.agregarCurso(&curso2);

    return 0;
}
