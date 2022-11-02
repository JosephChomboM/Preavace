#include <iostream>
using namespace std;

class Sesion
{
private:
    string usuario, contrasena;

public:
    Sesion(string, string);
    string getUsuario();
    string getContrasena();
};

Sesion::Sesion(string usuario, string contrasena)
{
    this->usuario = usuario;
    this->contrasena = contrasena;
}
string Sesion::getUsuario()
{
    return this->usuario;
}
string Sesion::getContrasena()
{
    return this->contrasena;
}