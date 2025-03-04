
#ifndef SCHOOL_H
#define SCHOOL_H

#include <string>
#include <vector>

#include "Student.h"
#include "Professor.h"
#include "Administrator.h"

class School
{
    private:
    std::string nombre;
    double dinero;
    double colegiatura;
    
    std::vector<Student> estudiantes;
    std::vector<Professor> profesores;
    std::vector<Administrator> administradors;

    public:
    School();
    School(std::string _nombre, double _colegiatura, Administrator& admin);
    ~School();

    void aumentarColegiatura(double _cantidad);
    void recolectarColegiatura();
    double pagarProfesores();
    
    bool dineroSuficiente();
    void autenticar(std::string _usuario, std::string _contrasena);

    void printInfo();

    void AddEstudiante(Student& _estudiante);
    void AddProfesor(Professor& _professor);
    void AddAdministrador(Administrator& _admin);

    private:
    bool esAdmin();
    void noAdminMensaje();
};

#endif