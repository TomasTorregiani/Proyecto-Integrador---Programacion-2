#pragma once
#include <string>

class Fecha{

public:
	Fecha();
	Fecha(int dia, int mes, int anio);

	void obtenerFechaActual(); // << nuevo

	void setDia(int dia);
	void setMes(int mes);
	void setAnio(int anio);

	int getDia();
	int getMes();
	int getAnio();
	bool validarAnio(int anio);

	bool validarFecha(int dia, int mes, int anio);
	void ingresarFecha();
	Fecha getFecha();
	std::string toString();
	std::string toString(Fecha fecha);

private:
	int _dia, _mes, _anio;
};
