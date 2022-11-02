#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "../model/Cliente.h"
using namespace std;
using std::stoi;

class ClienteController
{
private:
    vector<Cliente> vectorCliente;

public:
    ClienteController();
    void addCliente(Cliente);
    Cliente getObjCliente(int);
    int rows();
    int getCorrelativo();
    Cliente buscarPorCodigoCliente(int);
    void grabarEnArchivo(Cliente);
    void grabarModificarEliminar();
    void cargarDatosDelArchivo();
    bool modificar(Cliente, int, string, string, string);
    int getPostArray(Cliente);
    void removeCliente(Cliente);
    void listarCliente();
};
ClienteController::ClienteController()
{
    cargarDatosDelArchivo();
}
// agregar obj al arreglo
void ClienteController::addCliente(Cliente objCliente)
{
    vectorCliente.push_back(objCliente);
}
Cliente ClienteController::getObjCliente(int pos)
{
    return vectorCliente[pos];
}
int ClienteController::rows()
{
    return vectorCliente.size();
}
int ClienteController::getCorrelativo()
{
    if (rows() == 0)
    {
        return 1;
    }
    else
    {
        return vectorCliente[rows() - 1].getCodCliente() + 1;
    }
}
Cliente ClienteController::buscarPorCodigoCliente(int codigoCliente)
{
    Cliente objError;
    objError.setNombreCliente("ERROR");
    for (Cliente x : vectorCliente)
    {
        if (codigoCliente == x.getCodCliente())
        {
            return x;
        }
    }
    return objError;
}
void ClienteController::grabarEnArchivo(Cliente Cliente)
{
    try
    {
        fstream archivoCliente;
        archivoCliente.open("Cliente.csv", ios::app);

        if (archivoCliente.is_open())
        {
            archivoCliente << Cliente.getCodCliente() << "/"
                           << Cliente.getDniCliente() << "/"
                           << Cliente.getNombreCliente() << "/"
                           << Cliente.getApellidoCliente() << "/"
                           << Cliente.getDireccionCliente() << "/" << endl;
            archivoCliente.close();
        }
    }
    catch (exception e)
    {
        cout << "Ocurrio un error al grabar el archivo\n";
    }
}
void ClienteController::grabarModificarEliminar()
{
    try
    {
        fstream archivoCliente;
        archivoCliente.open("Cliente.csv", ios::out);

        if (archivoCliente.is_open())
        {
            for (Cliente x : vectorCliente)
            {
                archivoCliente << x.getCodCliente() << "/"
                               << x.getDniCliente() << "/"
                               << x.getNombreCliente() << "/"
                               << x.getApellidoCliente() << "/"
                               << x.getDireccionCliente() << "/" << endl;
            }
            archivoCliente.close();
        }
    }
    catch (exception e)
    {
        cout << "Ocurrio un error al grabar el archivo\n";
    }
}
void ClienteController::cargarDatosDelArchivo()
{
    try
    {
        int i;
        size_t posi;
        string linea;
        string temporal[5];
        fstream archivoCliente;
        archivoCliente.open("Cliente.csv", ios::in);

        if (archivoCliente.is_open())
        {
            while (!archivoCliente.eof() && getline(archivoCliente, linea))
            {
                i = 0;

                while ((posi = linea.find("/")) != string::npos)
                {
                    temporal[i] = linea.substr(0, posi);
                    linea.erase(0, posi + 1);
                    i++;
                }
                // Asignar valores al vector
                Cliente Cliente(stoi(temporal[0]), stoi(temporal[1]), temporal[2], temporal[3], temporal[4]);
                addCliente(Cliente);
            }
        }
    }
    catch (exception e)
    {
        cout << "Ocurrio un error al grabar el archivo\n";
    }
}
bool ClienteController::modificar(Cliente objCliente, int dniCliente, string nombreCliente, string apellidoCliente, string direccionCliente)
{
    for (int i = 0; i < vectorCliente.size(); i++)
    {
        if (objCliente.getCodCliente() == vectorCliente[i].getCodCliente())
        {
            vectorCliente[i].setDniCliente(dniCliente);
            vectorCliente[i].setNombreCliente(nombreCliente);
            vectorCliente[i].setApellidoCliente(apellidoCliente);
            vectorCliente[i].setDireccionCliente(direccionCliente);
            return true;
        }
    }
    return false;
}
int ClienteController::getPostArray(Cliente objCliente)
{
    for (int i = 0; i < vectorCliente.size(); i++)
    {
        if (objCliente.getCodCliente() == vectorCliente[i].getCodCliente())
        {
            return i;
        }
    }
    return -1;
}
void ClienteController::removeCliente(Cliente objCliente)
{
    vectorCliente.erase(vectorCliente.begin() + getPostArray(objCliente));
}
void ClienteController::listarCliente()
{
    for (int i = 0; i < vectorCliente.size(); i++)
    {
        cout << vectorCliente[i].getCodCliente() << "\t";
        cout << vectorCliente[i].getDniCliente() << "\t";
        cout << vectorCliente[i].getNombreCliente() << "\t";
        cout << vectorCliente[i].getApellidoCliente() << "\t";
        cout << vectorCliente[i].getDireccionCliente() << "\t";
    }
}