#pragma once
#include <iostream>
using namespace std;
class Categoria
{
private:
	int codCat;
	string nomCat;

public:
	Categoria();
	Categoria(int, string);
	// Set
	void setCodCategoria(int);
	void setNomCat(string);
	// Get
	int getCodCategoria();
	string getNomCat();
};
Categoria::Categoria()
{
}
Categoria::Categoria(int codCat, string nomCat)
{
	this->codCat = codCat;
	this->nomCat = nomCat;
}
// Set
void Categoria::setCodCategoria(int cod)
{
	this->codCat = cod;
}
void Categoria::Categoria::setNomCat(string nom)
{
	this->nomCat = nom;
}
// Get
int Categoria::getCodCategoria()
{
	return this->codCat;
}
string Categoria::getNomCat()
{
	return this->nomCat;
}
