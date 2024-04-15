#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Estudiante;  
class Curso {
private:
    string nombre;
    string codigo;
    string descripcion;
    string fechaInicio;
    string fechaFin;
    vector<Estudiante*> estudiantes;

public:

    Curso(string nombre, string codigo, string descripcion, string fechaInicio, string fechaFin)
        : nombre(nombre), codigo(codigo), descripcion(descripcion), fechaInicio(fechaInicio), fechaFin(fechaFin) {}

    void agregarEstudiante(Estudiante* estudiante) {
        estudiantes.push_back(estudiante);
    }


    void eliminarEstudiante(Estudiante* estudiante) {
        estudiantes.erase(remove(estudiantes.begin(), estudiantes.end(), estudiante), estudiantes.end());
    }
};


class Curso;  

class Estudiante {
private:
    string nombre;
    string apellido;
    int numeroIdentificacion;
    string correoElectronico;
    vector<Curso*> cursos;

public:
    
    Estudiante(string nombre, string apellido, int numeroIdentificacion, string correoElectronico)
        : nombre(nombre), apellido(apellido), numeroIdentificacion(numeroIdentificacion), correoElectronico(correoElectronico) {}


    void agregarCurso(Curso* curso) {
        cursos.push_back(curso);
    }

    void eliminarCurso(Curso* curso) {
        cursos.erase(remove(cursos.begin(), cursos.end(), curso), cursos.end());
    }
};

int main() {

    Estudiante estudiante1("Juan", "Perez", 12345678, "juanperez@mail.com");
    Estudiante estudiante2("María", "García", 87654321, "mariagarcia@mail.com");
    Curso curso1("Programación Básica", "PB001", "Introducción a la programación", "01/05/2024", "30/06/2024");
    Curso curso2("Matemáticas Avanzadas", "MA002", "Cálculo y álgebra avanzada", "01/06/2024", "31/07/2024");


    curso1.agregarEstudiante(&estudiante1);
    curso1.agregarEstudiante(&estudiante2);
    estudiante1.agregarCurso(&curso1);
    estudiante1.agregarCurso(&curso2);


    curso1.eliminarEstudiante(&estudiante2);
    estudiante1.eliminarCurso(&curso2);

    return 0;
}
