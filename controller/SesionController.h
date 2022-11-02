#include "../model/Sesion.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
bool accsesoAlSistema;
class SesionController
{
private:
  vector<Sesion> vectorSesion;

public:
  SesionController();
  void agregarObjeto(Sesion);
  Sesion numero(int);
  void grabarArchivo(Sesion);
  void verificarLogin(string, string);
};
SesionController::SesionController() {}
void SesionController::agregarObjeto(Sesion objeto)
{
  vectorSesion.push_back(objeto);
}
void SesionController::grabarArchivo(Sesion grabarSesion)
{
  try
  {
    fstream archivoRegistro;
    archivoRegistro.open("DatosRegistro.csv", ios::app);

    if (archivoRegistro.is_open())
    {
      archivoRegistro << grabarSesion.getUsuario() << "/"
                      << grabarSesion.getContrasena() << "/" << endl;
      archivoRegistro.close();
    }
  }
  catch (exception e)
  {
    cout << "Ocurrio un problema\n";
  }
}
void SesionController::verificarLogin(string users, string contrasenia)
{
  fstream archivo("DatosRegistro.csv");
  string arreglo[2], linea;
  size_t pos = 0;
  int contador = 0;
  string dato;
  int fin = 0;

  while (getline(archivo, linea) && fin == 0)
  {
    while ((pos = linea.find("/")) != string::npos)
    {
      dato = linea.substr(0, pos);
      arreglo[contador] = dato;
      linea.erase(0, pos + 1);
      contador++;
    }
    if (arreglo[0].find(users, 0) != string::npos)
    {
      fin = 1;
    }
    contador = 0;

    if ((users == arreglo[0]) && (contrasenia == arreglo[1]))
    {
      accsesoAlSistema = true;
    }
    else
    {
      accsesoAlSistema = false;
    }
  }
}
