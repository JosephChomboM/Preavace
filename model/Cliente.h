#pragma once
#include <iostream>
using namespace std;
class Cliente
{
private:
    int codCliente, dniCliente;
    string nombreCliente, apellidoCliente, direccionCliente;

public:
    Cliente();
    Cliente(int, int, string, string, string);
    void setCodCliente(int);
    void setDniCliente(int);
    void setNombreCliente(string);
    void setApellidoCliente(string);
    void setDireccionCliente(string);

    int getCodCliente();
    int getDniCliente();
    string getNombreCliente();
    string getApellidoCliente();
    string getDireccionCliente();
};
Cliente::Cliente()
{
}
Cliente::Cliente(int codCli, int dniCli, string nombreCli, string apellidoCli, string direccionCli)
{
    this->codCliente = codCli;
    this->dniCliente = dniCli;
    this->nombreCliente = nombreCli;
    this->apellidoCliente = apellidoCli;
    this->direccionCliente = direccionCli;
}
// set
void Cliente::setCodCliente(int codCliente)
{
    this->codCliente = codCliente;
}
void Cliente::setDniCliente(int dniCliente)
{
    this->dniCliente = dniCliente;
}
void Cliente::setNombreCliente(string nombreCliente)
{
    this->nombreCliente = nombreCliente;
}
void Cliente::setApellidoCliente(string apellidoCliente)
{
    this->apellidoCliente = apellidoCliente;
}
void Cliente::setDireccionCliente(string direccionCliente)
{
    this->direccionCliente = direccionCliente;
}
// get
int Cliente::getCodCliente()
{
    return this->codCliente;
}
int Cliente::getDniCliente()
{
    return this->dniCliente;
}
string Cliente::getNombreCliente()
{
    return this->nombreCliente;
}
string Cliente::getApellidoCliente()
{
    return this->apellidoCliente;
}
string Cliente::getDireccionCliente()
{
    return this->direccionCliente;
}
