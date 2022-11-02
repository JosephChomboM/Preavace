#pragma once
#include <iostream>
using namespace std;
class TipoPersonal
{
private:
	int codTip;
	string nomTipPer;

public:
	TipoPersonal();
	TipoPersonal(int, string);
	// Set
	void setCodTip(int);
	void setNomTip(string);
	// Get
	int getCodTip();
	string getNomTip();
};
TipoPersonal::TipoPersonal()
{
}
TipoPersonal::TipoPersonal(int codTip, string nomTip)
{
	this->codTip = codTip;
	this->nomTipPer = nomTip;
}
// Set
void TipoPersonal::setCodTip(int cod)
{
	this->codTip = cod;
}
void TipoPersonal::setNomTip(string nom)
{
	this->nomTipPer = nom;
}
// Get
int TipoPersonal::getCodTip()
{
	return this->codTip;
}
string TipoPersonal::getNomTip()
{
	return this->nomTipPer;
}
