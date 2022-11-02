#pragma once
#include <iostream>
#include "categoria.h"
using namespace std;
class Producto
{
private:
	int codProducto;
	string nomPro;
	float prePro;
	int stockPro;
	int codCategoria;

public:
	Producto();
	Producto(int, string, float, int, int);
	// Set
	void setCodPro(int);
	void setNomApe(string);
	void setPrePro(float);
	void setStockPro(int);
	void setCodCat(int);
	// Get
	int getCodPro();
	string getNomApePro();
	float getPrePro();
	int getStockPro();
	int getCodCat();
};
Producto::Producto()
{
}
Producto::Producto(int cod, string nom, float prePro, int stock, int codCat)
{
	this->codProducto = cod;
	this->nomPro = nom;
	this->prePro = prePro;
	this->stockPro = stock;
	this->codCategoria = codCat;
}
// Set
void Producto::setCodPro(int cod)
{
	this->codProducto = cod;
}
void Producto::setNomApe(string nom)
{
	this->nomPro = nom;
}
void Producto::setPrePro(float prePro)
{
	this->prePro = prePro;
}
void Producto::setStockPro(int stock)
{
	this->stockPro = stock;
}
void Producto::setCodCat(int codCat)
{
	this->codCategoria = codCat;
}
// Get
int Producto::getCodPro()
{
	return this->codProducto;
}
string Producto::getNomApePro()
{
	return this->nomPro;
}
float Producto::getPrePro()
{
	return this->prePro;
}
int Producto::getStockPro()
{
	return this->stockPro;
}
int Producto::getCodCat()
{
	return this->codCategoria;
}