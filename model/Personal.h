#pragma once
#include <iostream>
#include "TipoDePersonal.h"
using namespace std;
class Personal
{
private:
	int codPersonal;
	string nomApePer;
	string dniPer;
	int suePer;
	int codTipPer;
	string usuario;
	string contrasenia;

public:
	Personal();
	Personal(int, string, string, int, int, string, string);
	// Set
	void setCodPer(int);
	void setNomApe(string);
	void setDniPer(string);
	void setSuePer(int);
	void setCodTipPer(int);
	void setUser(string);
	void setContra(string);
	// Get
	int getCodPer();
	string getNomApe();
	string getDni();
	int getSue();
	int getCodTipPer();
	string getUser();
	string getContra();
};
Personal::Personal()
{
}
Personal::Personal(int cod, string nomApe, string dni, int sue, int codTip, string usuario, string contrasenia)
{
	this->codPersonal = cod;
	this->nomApePer = nomApe;
	this->dniPer = dni;
	this->suePer = sue;
	this->codTipPer = codTip;
	this->usuario = usuario;
	this->contrasenia = contrasenia;
}
// Set
void Personal::setCodPer(int cod)
{
	this->codPersonal = cod;
}
void Personal::setNomApe(string nomApe)
{
	this->nomApePer = nomApe;
}
void Personal::setDniPer(string dni)
{
	this->dniPer = dni;
}
void Personal::setSuePer(int sue)
{
	this->suePer = sue;
}
void Personal::setCodTipPer(int codTip)
{
	this->codTipPer = codTip;
}
void Personal::setUser(string usuario)
{
	this->usuario = usuario;
}
void Personal::setContra(string contrasenia)
{
	this->contrasenia = contrasenia;
}
// Get
int Personal::getCodPer()
{
	return this->codPersonal;
}
string Personal::getNomApe()
{
	return this->nomApePer;
}
string Personal::getDni()
{
	return this->dniPer;
}
int Personal::getSue()
{
	return this->suePer;
}
int Personal::getCodTipPer()
{
	return this->codTipPer;
}
string Personal::getUser()
{
	return this->usuario;
}
string Personal::getContra()
{
	return this->contrasenia;
}
