#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "controller/SesionController.h"
#include "controller/ClienteController.h"
#include "controller/PersonalController.h"
#include "controller/TipoPersonalController.h"
#include "controller/ProductoController.h"
#include "controller/CategoriaController.h"
using namespace std;
// Variables globales
SesionController *objSesionController = new SesionController();
ClienteController *objClienteController = new ClienteController();
PersonalController *objPersonalController = new PersonalController();
TipoPersonalController *tipController = new TipoPersonalController();
ProductoController *objProductoController = new ProductoController();
CategoriaController *objCategoriaController = new CategoriaController();
// Prototipos
void title();
// Seguridad
void login();
// Sistema principal
void MenuDelSistema();
// CLIENTES
void MenuDeClientes();
void addCliente();
void buscarCliente();
void listarCliente();
void modificarCliente();
void eliminarCliente();
// PERSONAL
void MenuDePersonal();
void addPersonal();
void buscarPersonal();
void listarPersonal();
void modificarPersonal();
void eliminarPersonal();
// TIPO DE PERSONAL
void MenuDeTipoDePersonal();
void addTipoPersonal();
void buscarTipoPersonal();
void listarTipoPersonal();
void modificarTipoPersonal();
void eliminarTipoPersonal();
// PRODUCTOS
void MenuDeProductos();
void addProducto();
void buscarProducto();
void listarProducto();
void modificarProducto();
void eliminarProducto();
// CATEGORIA DE PRODUCTOS
void MenuDeCategoria();
void addCategoria();
void buscarCategoria();
void listarCategoria();
void modificarCategoria();
void eliminarCategoria();
// VENTA
void MenuDeVenta();

int main()
{
	login();
	return 0;
}
// Implementacion
void title()
{
	system("cls");
	cout << "__      __        _          __  __" << endl;
	cout << "\\ \\    / /       | |        |  \\/  |" << endl;
	cout << " \\ \\  / /__ _ __ | |_ __ _  | \\  / | __ _ ___ " << endl;
	cout << "  \\ \\/ / _ \\ '_ \\| __/ _` | | |\\/| |/ _` / __|" << endl;
	cout << "   \\  /  __/ | | | || (_| | | |  | | (_| \\__ \"" << endl;
	cout << "    \\/ \\___|_| |_|\\__\\__,_| |_|  |_|\\__,_|___/\n"
		 << endl;
	cout << endl;
}
void login()
{
	string users, contrasenia;
	bool bandera;
	int contador;

	title();
	cout << "\t     LOG IN\n";
	cout << "\t----------------\n\n";
	cout << "Escriba su Usuario: ";
	getline(cin, users);
	cout << "Escriba su Contrasenia: ";
	// getline(cin, contrasenia);

	// contrasena con asteriscos
	char caracter;
	caracter = getch();
	while (caracter != 13) // mientras caracter sea diferente de enter
	{
		if (caracter != 8) // si el caracter es diferente de backspace
		{
			contrasenia.push_back(caracter); // mete el caracter al string contra
			cout << "*";					 // muestra los * en la consola
			caracter = getch();
		}
		else
		{
			if (contrasenia.length() > 0) // si el contra.length es mayor a 0
			{
				cout << "\b \b";											   // muestra como si borrara un caracter en la consola
				contrasenia = contrasenia.substr(0, contrasenia.length() - 1); // borra de verdad el dato en contrasenia
				caracter = getch();
			}
		}
	}
	objSesionController->verificarLogin(users, contrasenia);

	if (accsesoAlSistema == true)
	{
		MenuDelSistema();
		bandera = true;
	}
	else
	{
		cout << "\nLos datos son erroneos\n";
		system("pause");
	}
}
void MenuDelSistema()
{
	int opt;
	do
	{
		title();
		cout << "\t   MENU PRINCIPAL\n";
		cout << "\t----------------------\n\n";
		cout << "[1] Clientes\n";
		cout << "[2] Personal\n";
		cout << "[3] Tipo de personal\n";
		cout << "[4] Productos\n";
		cout << "[5] Categoria de Productos\n";
		cout << "[6] Generar venta\n";
		cout << "[7] Salir\n";
		cout << "Ingrese una opcion:";
		cin >> opt;
		switch (opt)
		{
		case 1:
			system("cls");
			MenuDeClientes();
			break;
		case 2:
			system("cls");
			MenuDePersonal();
			break;
		case 3:
			system("cls");
			MenuDeTipoDePersonal();
			break;
		case 4:
			system("cls");
			MenuDeProductos();
			break;
		case 5:
			system("cls");
			MenuDeCategoria();
			break;
		case 6:
			system("cls");
			MenuDeVenta();
			break;
		case 9:
			cout << "Gracias por usar nuestro programa\n";
			break;
		default:
			system("cls");
			cout << "Ingrese una opcion correcta[1-9].\n";
		}
	} while (opt != 7);
}

// CLIENTE
void MenuDeClientes()
{
	int opt;

	do
	{
		title();
		cout << "\t   MANTENIMIENTO DE CLIENTES\n";
		cout << "\t-------------------------------\n\n";
		cout << "Add cliente********[1]\n";
		cout << "Buscar cliente*****[2]\n";
		cout << "Listar cliente*****[3]\n";
		cout << "Modificar cliente**[4]\n";
		cout << "Eliminar cliente***[5]\n";
		cout << "Volver atras*******[6]\n";
		cout << "Ingresa una opcion correcta [1-6]: ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			addCliente();
			system("pause");
			system("cls");
			break;
		case 2:
			buscarCliente();
			system("pause");
			system("cls");
			break;
		case 3:
			listarCliente();
			system("pause");
			system("cls");
			break;
		case 4:
			modificarCliente();
			system("pause");
			system("cls");
			break;
		case 5:
			eliminarCliente();
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "Volviendo a la pagina anterior...\n";
			system("pause");
			system("cls");
			break;
		default:
			cout << "Ingrese una opcion valida [1 - 7]: \n";
		}
	} while (opt != 6);
}
void addCliente()
{
	int cod, dni;
	string nomb, apell, direc, flag;
	title();
	cout << "\t   ANIADIR CLIENTE\n";
	cout << "\t---------------------\n\n";
	do
	{
		cod = objClienteController->getCorrelativo();
		cout << "\tCodigo [ " << cod << " ]\n";
		cout << "Dni: ";
		cin >> dni;
		cin.ignore();
		cout << "Nombres: ";
		getline(cin, nomb);
		cout << "Apellidos: ";
		getline(cin, apell);
		cout << "Direccion: ";
		getline(cin, direc);

		Cliente Cliente(cod, dni, nomb, apell, direc);
		objClienteController->addCliente(Cliente);
		objClienteController->grabarEnArchivo(Cliente);

		cout << "Continuar(S/s): ";
		cin >> flag;
		cout << "-------------------------\n";
	} while (flag == "s" || flag == "S");
}
void buscarCliente()
{
	int cod;
	title();
	cout << "Ingrese codigo a buscar: ";
	cin >> cod;

	Cliente ClienteObj = objClienteController->buscarPorCodigoCliente(cod);

	if (ClienteObj.getNombreCliente() != "ERROR")
	{
		cout << "\tREGISTRO ENCONTRADO\n\n";
		cout << "Codigo: " << ClienteObj.getCodCliente() << endl;
		cout << "Dni: " << ClienteObj.getDniCliente() << endl;
		cout << "Nombres: " << ClienteObj.getNombreCliente() << endl;
		cout << "Apellidos: " << ClienteObj.getApellidoCliente() << endl;
		cout << "Dirrecion: " << ClienteObj.getDireccionCliente() << endl;
	}
	else
	{
		cout << "No se encontro el registro";
	}
}
void listarCliente()
{
	title();
	cout << "\t   REPORTE DE CLIENTES\n";
	cout << "\t-------------------------\n\n";
	objClienteController->listarCliente();
}
void modificarCliente()
{
	int cod;
	title();
	cout << "\t   MODIFICACION DE DATOS\n";
	cout << "\t---------------------------\n\n";

	cout << "Ingresar el codigo a modificar: ";
	cin >> cod;
	Cliente ClienteObj = objClienteController->buscarPorCodigoCliente(cod);
	// Buscar objeto a modificar
	cout << "\tREGISTRO ENCONTRADO\n\n";
	cout << "Codigo: " << ClienteObj.getCodCliente() << endl;
	cout << "Dni: " << ClienteObj.getDniCliente() << endl;
	cout << "Nombres: " << ClienteObj.getNombreCliente() << endl;
	cout << "Apellidos: " << ClienteObj.getApellidoCliente() << endl;
	cout << "Dirrecion: " << ClienteObj.getDireccionCliente() << endl;
	// fin del objeto a modificar
	int dniM;
	string nomM, apellM, direcM;

	cout << "MODIFICANDO CAMPOS...\n\n";
	cout << "Modificando el Dni...:";
	cin >> dniM;
	cin.ignore();
	cout << "Modificando los nombres...: ";
	getline(cin, nomM);
	cout << "Modificando los apellidos...: ";
	getline(cin, apellM);
	cout << "Modificando la direccion...: ";
	getline(cin, direcM);

	bool estado = objClienteController->modificar(ClienteObj, dniM, nomM, apellM, direcM);
	if (estado = true)
	{
		cout << "Registro modificado satisfactoriamente\n";
		objClienteController->grabarModificarEliminar();
	}
	else
	{
		cout << "No enconto el registro a modificar\n";
	}
}
void eliminarCliente()
{
	int cod;
	title();
	cout << "\t   ELIMINAR CLIENTE\n";
	cout << "\t----------------------\n\n";
	cout << "Ingrese codigo a buscar:";
	cin >> cod;
	Cliente objEliminar = objClienteController->buscarPorCodigoCliente(cod);
	if (objEliminar.getNombreCliente() != "ERROR")
	{
		objClienteController->removeCliente(objEliminar);
		cout << "Registro eliminado satisfactoriamente!!\n";
		objClienteController->grabarModificarEliminar();
	}
	else
	{
		cout << "No se encontro el registro\n";
	}
}
// PERSONAL
void MenuDePersonal()
{
	int opt;

	do
	{
		title();
		cout << "\t   MANTENIMIENTO DEL PERSONAL\n";
		cout << "\t--------------------------------\n\n";
		cout << "[1] Add personal\n";
		cout << "[2] Buscar personal\n";
		cout << "[3] Listar personal\n";
		cout << "[4] Modificar personal\n";
		cout << "[5] Eliminar personal\n";
		cout << "[6] Volver atras\n";
		cout << "Ingresa una opcion correcta [1-6]: ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			addPersonal();
			system("pause");
			system("cls");
			break;
		case 2:
			buscarPersonal();
			system("pause");
			system("cls");
			break;
		case 3:
			listarPersonal();
			system("pause");
			system("cls");
			break;
		case 4:
			modificarPersonal();
			system("pause");
			system("cls");
			break;
		case 5:
			eliminarPersonal();
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "Volviendo a la pagina anterior...\n";
			system("pause");
			system("cls");
			break;
		default:
			cout << "Ingrese una opcion valida [1 - 7]: \n";
		}
	} while (opt != 6);
}
void addPersonal()
{
	string bandera, nomApe, dni, usuario, contrasenia;
	int codPer, sue, codTipPer;

	do
	{
		title();
		codPer = objPersonalController->getCorrelativo();
		cout << "************(" << codPer << ")************\n";
		cin.ignore();
		cout << "Ingresar nombre y apellido:";
		getline(cin, nomApe);
		cout << "Ingresar dni:";
		cin >> dni;
		cout << "Ingresar sueldo:";
		cin >> sue;
		tipController->listar();
		cin >> codTipPer;
		cin.ignore();
		cout << "Registrar nuevo usuario: ";
		getline(cin, usuario);
		cout << "Registrar contrasenia: ";
		// getline(cin, contrasenia);
		char caracter;
		caracter = getch();	   // getch() = funcion para leer caracter uno por uno caracter = a
		while (caracter != 13) // mientras caracter sea diferente de enter
		{
			if (caracter != 8) // si el caracter es diferente de backspace(retroceso)
			{
				contrasenia.push_back(caracter); // mete el caracter al string contra || contra = adolf
				cout << "*";					 // muestra los * en la consola
			}
			else
			{
				if (contrasenia.length() > 0) // si el contra.length es mayor a 0
				{
					cout << "\b \b";											   // muestra como si borrara un caracter en la consola
					contrasenia = contrasenia.substr(0, contrasenia.length() - 1); // borra de verdad el dato en el string contra
				}
			}
			caracter = getch(); // vuelve a leer el siguiente caracter
		}
		cout << endl;
		cout << "Desea continuar? (S/s):";
		cin >> bandera;
		// Creando objsesion
		Sesion sesion(usuario, contrasenia);
		objSesionController->agregarObjeto(sesion);
		objSesionController->grabarArchivo(sesion);
		// Creando el obj personal con usuario y contras
		Personal objPer(codPer, nomApe, dni, sue, codTipPer, usuario, contrasenia);
		objPersonalController->add(objPer);
		// grabar en archivo
		objPersonalController->grabarEnArchivo(objPer);
		system("cls");
	} while (bandera == "S" || bandera == "s");
}
void buscarPersonal()
{
	int cod;
	title();
	cout << "\t   BUSQUEDA DE PERSONAL\n";
	cout << "\t--------------------------\n\n";
	cout << "Ingrese codigo a buscar:";
	cin >> cod;
	Personal objEncontrado = objPersonalController->buscar(cod);
	if (objEncontrado.getUser() != "Error")
	{
		cout << "\tPERSONAL ENCONTRADO\n\n";
		cout << "Nombres y Apellidos:" << objEncontrado.getNomApe() << endl;
		cout << "DNI:" << objEncontrado.getDni() << endl;
		cout << "Sueldo:" << objEncontrado.getSue() << endl;
		cout << "Tipo de personal:" << tipController->listarTipo(objEncontrado) << endl;
		cout << "Usuario:" << objEncontrado.getUser() << endl;
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
}
void listarPersonal()
{
	title();
	objPersonalController->listar();
}
void modificarPersonal()
{
	int cod;
	title();
	cout << "\t   MODIFICANDO DATOS\n";
	cout << "\t-----------------------\n\n";
	cout << "Ingrese codigo a modificar:";
	cin >> cod;
	Personal objEncontrado = objPersonalController->buscar(cod);
	if (objEncontrado.getUser() != "Error")
	{
		cout << "\tPERSONAL ENCONTRADO\n";
		cout << "Modificando nombres y apellidos...:" << objEncontrado.getNomApe() << endl;
		cout << "Modificando DNI...:" << objEncontrado.getDni() << endl;
		cout << "Modificando sueldo...:" << objEncontrado.getSue() << endl;
		cout << "Modificando tipo de personal...:" << tipController->listarTipo(objEncontrado) << endl;
		cout << "Modificando usuario...: " << objEncontrado.getUser() << endl;
		cout << "Modificando contrasenia...: " << objEncontrado.getContra() << endl;
		cin.ignore();
		// Modificacion
		string nomApe;
		string dni;
		int sue;
		int codTipPer;
		string usuario;
		string contrasenia;
		cout << "Ingresar nombre y apellido:";
		getline(cin, nomApe);
		cout << "Ingresar dni:";
		cin >> dni;
		cout << "Ingresar sueldo:";
		cin >> sue;
		tipController->listar();
		cin >> codTipPer;
		cin.ignore();
		cout << "Ingresar usuario:";
		getline(cin, usuario);
		cout << "Ingresar contrasenia:";
		char caracter;
		caracter = getch();	   // getch() = funcion para leer caracter uno por uno
		while (caracter != 13) // mientras caracter sea diferente de enter
		{
			if (caracter != 8) // si el caracter es diferente de backspace(retroceso)
			{
				contrasenia.push_back(caracter); // mete el caracter al string contra
				cout << "*";					 // muestra los * en la consola
			}
			else
			{
				if (contrasenia.length() > 0) // si el contra.length es mayor a 0
				{
					cout << "\b \b";											   // muestra como si borrara un caracter en la consola
					contrasenia = contrasenia.substr(0, contrasenia.length() - 1); // borra de verdad el dato en el string contra
				}
			}
			caracter = getch(); // vuelve a leer el siguiente caracter
		}
		cout << "\n";
		Personal objNew(objEncontrado.getCodPer(), nomApe, dni, sue, codTipPer, usuario, contrasenia);
		bool estado = objPersonalController->modificar(objEncontrado, objNew);
		if (estado = true)
		{
			cout << "Registro modificado satisfactoriamente\n";
			// grabar en archivo
			objPersonalController->grabarModificarEliminar();
		}
		else
		{
			cout << "No se Modifico el registro\n";
		}
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
}
void eliminarPersonal()
{
	int cod;
	title();
	cout << "\t   ELIMINANDO PERSONAL\n";
	cout << "\t-------------------------\n\n";
	cout << "Ingrese codigo a eliminar: ";
	cin >> cod;
	Personal objEliminar = objPersonalController->buscar(cod);
	if (objEliminar.getUser() != "Error")
	{
		objPersonalController->eliminar(objEliminar);
		cout << "Registro Eliminado Satisfactoriamente!\n";
		// Grabar en archivo
		objPersonalController->grabarModificarEliminar();
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
}

// TIPO PERSONAL
void MenuDeTipoDePersonal()
{
	int opt;
	do
	{
		cout << "\t   OPCIONES DEL TIPO DE PERSONAL\n";
		cout << "\t-----------------------------------\n\n";
		cout << "[1] Add un tipo de personal\n";
		cout << "[2] Buscar tipo de personal\n";
		cout << "[3] Listar tipo de personal\n";
		cout << "[4] Modificar tipo de personal\n";
		cout << "[5] Eliminar\n";
		cout << "[6] Atras\n";
		cout << "Ingrese una opcion:";
		cin >> opt;
		switch (opt)
		{
		case 1:
			addTipoPersonal();
			break;
		case 2:
			buscarTipoPersonal();
			break;
		case 3:
			listarTipoPersonal();
			break;
		case 4:
			modificarTipoPersonal();
			break;
		case 5:
			eliminarTipoPersonal();
			break;
		case 6:
			cout << "Volviendo a la ventana anterior...\n";
			system("pause");
			system("cls");
			break;
		default:
			system("cls");
			cout << "Ingrese una opcion correcta[1-5].\n";
		}
	} while (opt != 6);
}
void addTipoPersonal()
{
	int codTip;
	string tipoPer;
	string bandera;
	do
	{
		codTip = tipController->getCorrelativo();
		cout << "************(" << codTip << ")************\n";
		cin.ignore();
		cout << "Ingrese Tipo de Personal:";
		getline(cin, tipoPer);
		cout << "Continuar(S/s):";
		cin >> bandera;
		/*Creando el objeto de tipo Usuario*/
		TipoPersonal objTip(codTip, tipoPer); // cod = 1, usuario = "Pepito", contra = "xd";
		// Agregando el objeto al arreglo
		tipController->add(objTip);
		// grabar en archivo
		tipController->grabarEnArchivo(objTip);
		system("cls");
	} while (bandera == "S" || bandera == "s");
}
void buscarTipoPersonal()
{
	int cod;
	cout << "Ingrese codigo a buscar:";
	cin >> cod;
	TipoPersonal objEncontrado = tipController->buscar(cod);
	if (objEncontrado.getNomTip() != "Error")
	{
		cout << "Tipo de personal encontrado\n";
		cout << "Tipo de personal:" << objEncontrado.getNomTip() << endl;
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
	system("pause");
	system("cls");
}
void listarTipoPersonal()
{
	tipController->listar2();
	system("pause");
	system("cls");
}
void modificarTipoPersonal()
{
	int cod;
	cout << "Ingrese codigo a modificar:";
	cin >> cod;
	TipoPersonal objEncontrado = tipController->buscar(cod);
	if (objEncontrado.getNomTip() != "Error")
	{
		cout << "Tipo de personal encontrado\n";
		cout << "Tipo de personal:" << objEncontrado.getNomTip() << endl;
		cin.ignore();
		// Modificaci�n
		string nomTip;
		cout << "Ingresar tipo de personal:";
		getline(cin, nomTip);
		TipoPersonal objNew(objEncontrado.getCodTip(), nomTip);
		bool estado = tipController->modificar(objEncontrado, objNew);
		if (estado = true)
		{
			cout << "Registro modificado satisfactoriamente\n";
			// grabar en archivo
			tipController->grabarModificarEliminar();
		}
		else
		{
			cout << "No se Modifico el registro\n";
		}
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
}
void eliminarTipoPersonal()
{
	int cod;
	cout << "Ingrese codigo a eliminar:";
	cin >> cod;
	TipoPersonal objEliminar = tipController->buscar(cod);
	if (objEliminar.getNomTip() != "Error")
	{
		tipController->eliminar(objEliminar);
		cout << "Registro Eliminado Satisfactoriamente!\n";
		// Grabar en archivo
		tipController->grabarModificarEliminar();
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
	system("pause");
	system("cls");
}
// PRODUCTO
void MenuDeProductos()
{
	int opt;
	do
	{
		title();
		cout << "\t   MANTENIMIENTO DE PRODUCTOS\n";
		cout << "\t--------------------------------\n";
		cout << "[1] Add producto\n";
		cout << "[2] Buscar producto\n";
		cout << "[3] Listar producto\n";
		cout << "[4] Modificar producto\n";
		cout << "[5] Eliminar producto\n";
		cout << "[6] Volver atras\n";
		cout << "Ingresa una opcion correcta[1 - 6]: ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			addProducto();
			system("pause");
			system("cls");
			break;
		case 2:
			buscarProducto();
			system("pause");
			system("cls");
			break;
		case 3:
			listarProducto();
			system("pause");
			system("cls");
			break;
		case 4:
			modificarProducto();
			system("pause");
			system("cls");
			break;
		case 5:
			eliminarProducto();
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "Volviendo a la ventana anterior...\n";
			system("pause");
			system("cls");
			break;
		default:
			system("cls");
			cout << "Ingrese una opcion correcta[1-5].\n";
		}
	} while (opt != 6);
}
void addProducto()
{
	string bandera;
	int codPro;
	string nom;
	float pre;
	int stock;
	int codCat;
	do
	{
		title();
		codPro = objProductoController->getCorrelativo();
		cout << "************(" << codPro << ")************\n";
		cin.ignore();
		cout << "Ingresar nombre del producto:";
		getline(cin, nom);
		cout << "Ingresar precio del producto:";
		cin >> pre;
		cout << "Ingresar stock del producto:";
		cin >> stock;
		objCategoriaController->listar();
		cin >> codCat;
		cout << "Continuar(S/s):";
		cin >> bandera;
		/*Creando el objeto de tipo Usuario*/
		Producto objPro(codPro, nom, pre, stock, codCat);
		// Agregando el objeto al arreglo
		objProductoController->add(objPro);
		// grabar en archivo
		objProductoController->grabarEnArchivo(objPro);
	} while (bandera == "S" || bandera == "s");
}
void buscarProducto()
{
	int cod;
	title();
	cout << "Ingrese codigo a buscar:";
	cin >> cod;
	Producto objEncontrado = objProductoController->buscar(cod);
	if (objEncontrado.getNomApePro() != "Error")
	{
		cout << "\tPRODUCTO ENCONTRADO\n";
		cout << "Nombre del producto: " << objEncontrado.getNomApePro() << endl;
		cout << "Precio: " << objEncontrado.getPrePro() << endl;
		cout << "Stock: " << objEncontrado.getStockPro() << endl;
		cout << "Categoria del producto: " << objCategoriaController->listarCategoria(objEncontrado) << endl;
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
}
void modificarProducto()
{
	int cod;
	title();
	cout << "\t   MODIFICANDO PRODUCTO\n\n";
	cout << "\t--------------------------";
	cout << "Ingrese codigo a modificar:";
	cin >> cod;
	Producto objEncontrado = objProductoController->buscar(cod);
	if (objEncontrado.getNomApePro() != "Error")
	{
		cout << "\tPRODUCTO ENCONTRADO\n";
		cout << "Nombre del producto: " << objEncontrado.getNomApePro() << endl;
		cout << "Precio: " << objEncontrado.getPrePro() << endl;
		cout << "Stock :" << objEncontrado.getStockPro() << endl;
		cout << "Categoria del producto: " << objCategoriaController->listarCategoria(objEncontrado) << endl;
		cin.ignore();

		string nomPro;
		float precio;
		int stock;
		int codCat;
		cout << "\tMODIFICANDO CAMPOS...\n\n";
		cout << "Modificando nombre del producto...: ";
		getline(cin, nomPro);
		cout << "Modificando precio del producto...: ";
		cin >> precio;
		cout << "Modificando stock del producto...: ";
		cin >> stock;
		objCategoriaController->listar();
		cin >> codCat;
		Producto objNew(objEncontrado.getCodPro(), nomPro, precio, stock, codCat);
		bool estado = objProductoController->modificar(objEncontrado, objNew);
		if (estado = true)
		{
			cout << "Registro modificado satisfactoriamente\n";
			// grabar en archivo
			objProductoController->grabarModificarEliminar();
		}
		else
		{
			cout << "No se Modifico el registro\n";
		}
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
}
void eliminarProducto()
{
	int cod;
	cout << "Ingrese codigo a eliminar: ";
	cin >> cod;
	Producto objEliminar = objProductoController->buscar(cod);
	if (objEliminar.getNomApePro() != "Error")
	{
		objProductoController->eliminar(objEliminar);
		cout << "Registro Eliminado Satisfactoriamente!\n";
		// Grabar en archivo
		objProductoController->grabarModificarEliminar();
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
}
void listarProducto()
{
	objProductoController->listar();
}
// CATEGORIA
void MenuDeCategoria()
{
	int opt;
	do
	{
		title();
		cout << "\t   MEMU DE CATEGORIA DE PRODUCTOS\n";
		cout << "\t------------------------------------\n";
		cout << "[1] Add categoria\n";
		cout << "[2] Buscar categoria\n";
		cout << "[3] Listar categoria\n";
		cout << "[4] Modificar categoria\n";
		cout << "[5] Eliminar categoria\n";
		cout << "[6] Volver atras\n";
		cout << "Ingresa una opcion correcta[1 - 6]: ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			addCategoria();
			system("pause");
			system("cls");
			break;
		case 2:
			buscarCategoria();
			system("pause");
			system("cls");
			break;
		case 3:
			listarCategoria();
			system("pause");
			system("cls");
			break;
		case 4:
			modificarCategoria();
			system("pause");
			system("cls");
			break;
		case 5:
			eliminarCategoria();
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "Volviendo a la ventana anterior...\n";
			system("pause");
			system("cls");
			break;
		default:
			system("cls");
			cout << "Ingrese una opcion correcta[1-5].\n";
		}
	} while (opt != 6);
}
void addCategoria()
{
	int codCat;
	string nomCat;
	string bandera;
	do
	{
		title();
		codCat = objCategoriaController->getCorrelativo();
		cout << "************(" << codCat << ")************\n";
		cin.ignore();
		cout << "Ingrese la nueva categoria de producto:";
		getline(cin, nomCat);
		cout << "Continuar(S/s):";
		cin >> bandera;
		/*Creando el objeto de tipo Usuario*/
		Categoria objCat(codCat, nomCat); // cod = 1, usuario = "Pepito", contra = "xd";
		// Agregando el objeto al arreglo
		objCategoriaController->add(objCat);
		// grabar en archivo
		objCategoriaController->grabarEnArchivo(objCat);
	} while (bandera == "S" || bandera == "s");
}
void buscarCategoria()
{
	int cod;
	title();
	cout << "\t   BUSCANDO CATEGORIA\n";
	cout << "\t------------------------";
	cout << "Ingrese codigo a buscar:";
	cin >> cod;
	Categoria objEncontrado = objCategoriaController->buscar(cod);
	if (objEncontrado.getNomCat() != "Error")
	{
		cout << "Categoria encontrada\n";
		cout << "Categoria:" << objEncontrado.getNomCat() << endl;
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
}
void listarCategoria()
{
	title();
	objCategoriaController->listar2();
}
void modificarCategoria()
{
	int cod;
	title();
	cout << "Ingrese codigo a modificar:";
	cin >> cod;
	Categoria objEncontrado = objCategoriaController->buscar(cod);
	if (objEncontrado.getNomCat() != "Error")
	{
		cout << "Categoria encontrada\n";
		cout << "Categoria:" << objEncontrado.getNomCat() << endl;
		cin.ignore();
		// Modificacion
		string nomCat;
		cout << "Ingresar categoria de producto:";
		getline(cin, nomCat);
		Categoria objNew(objEncontrado.getCodCategoria(), nomCat);
		bool estado = objCategoriaController->modificar(objEncontrado, objNew);
		if (estado = true)
		{
			cout << "Registro modificado satisfactoriamente\n";
			// grabar en archivo
			objCategoriaController->grabarModificarEliminar();
		}
		else
		{
			cout << "No se Modifico el registro\n";
		}
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
}
void eliminarCategoria()
{
	int cod;
	title();
	cout << "Ingrese codigo a eliminar:";
	cin >> cod;
	Categoria objEliminar = objCategoriaController->buscar(cod);
	if (objEliminar.getNomCat() != "Error")
	{
		objCategoriaController->eliminar(objEliminar);
		cout << "Registro Eliminado Satisfactoriamente!\n";
		// Grabar en archivo
		objCategoriaController->grabarModificarEliminar();
	}
	else
	{
		cout << "No se encontro el codigo ingresado\n";
	}
}
void MenuDeVenta()
{
}
