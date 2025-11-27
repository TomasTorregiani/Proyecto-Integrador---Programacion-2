#include "Fecha.h"
#include <string>
#include <iostream>
#include <ctime>
#include "FuncionesGlobales.h"

using namespace std;

Fecha::Fecha() {}

void Fecha::obtenerFechaActual()
{

    time_t ahora = time(0);
    tm* tiempoLocal = localtime(&ahora);

    _dia = tiempoLocal->tm_mday;
    _mes = tiempoLocal->tm_mon + 1;
    _anio = tiempoLocal->tm_year + 1900;
}

Fecha::Fecha(int dia, int mes, int anio)
{
    if (validarFecha(dia, mes, anio))
    {
        setMes(mes);
        setAnio(anio);
        setDia(dia);
    }
    else
    {
        _dia = 1;
        _mes = 1;
        _anio = 2000;
        cout << "FECHA INCORRECTA. Se asigno una fecha por defecto." << endl;
    }
}


bool Fecha::validarFecha(int dia, int mes, int anio)
{
    if (anio < 2000 || anio > 2100)
    {
        return false;
    }

    if (mes < 1 || mes > 12)
    {
        return false;
    }

    if (dia < 1 || dia > diasDelMes(mes, anio))
    {
        return false;
    }

    return true;
}

Fecha Fecha::getFecha()
{
    return Fecha(_dia, _mes,_anio);
}

string Fecha::toString(){
	return to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
}

string Fecha::toString(Fecha fecha){
	return to_string(fecha.getDia()) + "/" + to_string(fecha.getMes()) + "/" + to_string(fecha.getAnio());
}

void Fecha::setMes(int mes)
{
    _mes = mes;
}

void Fecha::setAnio(int anio)
{
    _anio = anio;
}

void Fecha::setDia(int dia)
{
    if(dia >= 1 && dia <= diasDelMes(_mes, _anio))
    {
        _dia = dia;
    }
}

int Fecha::getDia()
{
    return _dia;
}

int Fecha::getMes()
{
    return _mes;
}

int Fecha::getAnio()
{
    return _anio;
}



