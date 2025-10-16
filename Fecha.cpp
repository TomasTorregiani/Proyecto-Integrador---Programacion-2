#include "Fecha.h"
#include <string>
#include <iostream>

using namespace std;

Fecha::Fecha(){}

Fecha::Fecha(int dia, int mes, int anio)
{
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}

void Fecha::setDia(int dia){
	_dia = dia;
}

void Fecha::setMes(int mes){
	_mes = mes;
}

void Fecha::setAnio(int anio){
	_anio = anio;
}

int Fecha::getDia(){return _dia;}

int Fecha::getMes(){return _mes;}

int Fecha::getAnio(){return _anio;}

std::string Fecha::getFecha(){
	return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
}

