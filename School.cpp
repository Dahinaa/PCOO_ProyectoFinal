
#include "School.h"

School::School()
{
    nombre = "";
    dinero = 0.0;
    colegiatura = 0.0;
};

School::School(std::string _nombre, double _colegiatura, Administrator& admin)
{
    nombre = _nombre;
    colegiatura = _colegiatura;
    administradors.push_back(admin);
};

School::~School()
{
    
};

void School::aumentarColegiatura(double cantidad)
{   
    if (!esAdmin()){ return; }
    colegiatura += cantidad;
};

//*
void School::recolectarColegiatura()
{
    if (!esAdmin()){ return; }
    
    for (int i = 0; i < estudiantes.size(); i++)
    {
        dinero += estudiantes[i].recolectarDinero(colegiatura);
    }
};
//*
double School::pagarProfesores()
{
    if (!esAdmin()){ return 0; }

    if (!dineroSuficiente())
    { 
        return 0; 
    }
    
    double dineroUsado = 0;
    for(Professor p:profesores)
    {
        dineroUsado += p.pagar(p.getSalario());
    }
    
    dinero -= dineroUsado;

};

bool School::dineroSuficiente()
{
    double dineroRequerido = 0;

    for(Professor p:profesores)
    {
        dineroRequerido += p.getSalario();
    }

    return dineroRequerido <= dinero;
};
//*/

void School::autenticar(std::string usuario, std::string contrasena)
{
    for (int i = 0; i < administradors.size(); i++)
    {
        if (administradors[i].esUsuario(usuario))
        {
            administradors[i].logIn(contrasena);
            break;
        }
    }
};

void School::printInfo()
{
    cout<<"SCHOOL: "<<nombre<<"\n";
    cout<<"Colegiatura: $"<<colegiatura<<"\n";
    cout<<"Dinero: $"<<colegiatura<<"\n";
    cout<<"Professores: "<<profesores.size()<<"\n";
    cout<<"Alumnos:     "<<estudiantes.size()<<"\n";
}

void School::AddEstudiante(Student& _estudiante)
{
    estudiantes.push_back(_estudiante);
}

void School::AddProfesor(Professor& _professor)
{
    if (!esAdmin()){ return; }
    profesores.push_back(_professor);
}

void School::AddAdministrador(Administrator& _admin)
{
    if (!esAdmin()){ return; }
    administradors.push_back(_admin);
}

bool School::esAdmin()
{
    for (Administrator admin:administradors)
    {
        if (admin.on())
        {
            return true;
        }
    }
    
    noAdminMensaje();
    return false;
};

void School::noAdminMensaje()
{
    cout<<"\e[0;31m";
    cout<<"ERROR: No se puede ejecutar esta accion sin ser administrador\n";
    cout<<"\e[0;0m";
}