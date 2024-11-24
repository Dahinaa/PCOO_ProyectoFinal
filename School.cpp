
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

};

void School::recolectarColegiatura()
{
    if (!esAdmin()){ return; }

};

void School::pagarProfesores()
{
    if (!esAdmin()){ return; }

    if (!dineroSuficiente())
    { 
        return; 
    }

    for(Professor p:profesores)
    {
        dinero -= p.pagar(p.getSalario());
    }

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

void School::autenticar(std::string usuario, std::string contrasena)
{
    for (Administrator admin:administradors)
    {
        if (admin.esUsuario(usuario))
        {
            admin.logIn(contrasena);
            break;
        }
    }
};

bool School::esAdmin()
{
    for (Administrator admin:administradors)
    {
        if (admin.on())
        {
            return true;
        }
    }
    return false;
};
