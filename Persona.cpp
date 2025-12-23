#include "Persona.h"
#include <cstring>

Persona::Persona(): _numeroTelefono(0)
{
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_email,"");
    strcpy(_direccion,"");
}

Persona::Persona(std::string nombre, std::string apellido, int numeroTelefono, std::string email, std::string direccion)
{
    setNombre(nombre);
    setApellido(apellido);
    setNumeroTelefono(numeroTelefono);
    setEmail(email);
    setDireccion(direccion);
}

//setters

void Persona::setNombre(std::string nombre)
{
	strncpy(_nombre, nombre.c_str(), sizeof(_nombre)-1);
	_nombre[49] = '\0';
}

void Persona::setApellido(std::string apellido)
{
	strncpy(_apellido, apellido.c_str(), sizeof(_apellido) -1);
	_apellido[49] = '\0';
}

void Persona::setNumeroTelefono(int numeroTelefono)
{
	_numeroTelefono = numeroTelefono;
}

void Persona::setEmail(std::string email)
{
	strncpy(_email, email.c_str(), sizeof(_email) -1);
	_email[19] = '\0';
}

void Persona::setDireccion(std::string direccion)
{
	strncpy(_direccion, direccion.c_str(), sizeof(_direccion) -1);
	_direccion[19] = '\0';
}

//getters

std::string Persona::getNombre()
{
	return _nombre;
}

std::string Persona::getApellido()
{
	return _apellido;
}

int Persona::getNumeroTelefono()
{
	return _numeroTelefono;
}

std::string Persona::getEmail()
{
	return _email;
}

std::string Persona::getDireccion()
{
	return _direccion;
}
