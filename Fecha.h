#pragma once
#include <string>

class Fecha{

public:
	Fecha();
	Fecha(int dia, int mes, int anio);

	void setDia(int dia);
	void setMes(int mes);
	void setAnio(int anio);

	int getDia();
	int getMes();
	int getAnio();

	bool validarFecha(int dia, int mes, int anio);
	std::string getFecha();

private:
	int _dia, _mes, _anio;
	bool anioBisiesto(int anio); //privado porque es una validación interna de la clase.
	int diasDelMes(int mes, int anio); // idem;
};
