#include "Fecha.h"
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

Fecha::Fecha(){}

void Fecha::obtenerFechaActual(){
	
    time_t ahora = time(0);
    tm* tiempoLocal = localtime(&ahora);
    
    int dia = tiempoLocal->tm_mday;
    int mes = tiempoLocal->tm_mon + 1;
    int anio = tiempoLocal->tm_year + 1900;
}

Fecha::Fecha(int dia, int mes, int anio){
	if (validarFecha(dia, mes, anio)){
		setMes(mes);
		setAnio(anio);
		setDia(dia);
	}else{
		_dia = 1;
		_mes = 1;
		_anio = 2000;
		cout << "FECHA INCORRECTA. Se asigno una fecha por defecto." << endl;
	}
}


bool Fecha::validarFecha(int dia, int mes, int anio){
    if (anio < 2000 || anio > 2100){
        return false;
    }

    if (mes < 1 || mes > 12){
        return false;
    }

    if (dia < 1 || dia > diasDelMes(mes, anio)){
        return false;
    }

    return true;
}

std::string Fecha::getFecha(){
	return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
}

bool Fecha::anioBisiesto(int anio){
    if((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)){
		return true;
    }
}

int Fecha::diasDelMes(int mes, int anio){
    int dias[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(mes == 2 && anioBisiesto(anio)){
        return 29;
    }
    return dias[mes - 1];
}

void Fecha::setMes(int mes){
	_mes = mes;
}

void Fecha::setAnio(int anio){
	_anio = anio;
}

void Fecha::setDia(int dia){
    if(dia >= 1 && dia <= diasDelMes(_mes, _anio)){
        _dia = dia;
    }
}

int Fecha::getDia(){return _dia;}

int Fecha::getMes(){return _mes;}

int Fecha::getAnio(){return _anio;}



