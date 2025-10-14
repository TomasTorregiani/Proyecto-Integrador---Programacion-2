#include <iostream>
#include <cstring>
#include "Vendedor.h"

using namespace std;

Vendedor::Vendedor()
:_idVendedor(0), _nombre("Matias"),
_apellido("Cortes"),_numeroTelefono(0),
_email(""), _direccion(""){}

Vendedor::Vendedor(int idVendedor, std::string nombre,
            std::string apellido,int numeroTelefono,
            std::string email, std::string direccion)
{
    _idVendedor = 0; //Empezar en 1 e ir sumando;
    setNombre(nombre);
    setApellido(apellido);
    setEmail(email);
    setDireccion(direccion);
}
void Vendedor::setNombre(string nombre){
    strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
    _nombre[49] = '\0';
}
void Vendedor::setApellido(string apellido){
    strncpy(_apellido, apellido.c_str(), sizeof(_apellido) - 1);
    _apellido[49] = '\0';
}

void Vendedor::setNumeroTelefono(int numeroTelefono){
    _numeroTelefono = numeroTelefono;
}
void Vendedor::setEmail(string email){
    strncpy(_email, email.c_str(), sizeof(_email) - 1);
}
void Vendedor::setDireccion(string direccion){
    strncpy(_direccion, direccion.c_str(), sizeof(_direccion) - 1);
    _direccion[49] = '\0';
}

int Vendedor::getIdVendedor(){
    return _idVendedor;
}
string Vendedor::getNombre(){
    return _nombre;
}
string Vendedor::getApellido(){
    return _apellido;
}

string Vendedor::getEmail(){
    return _email;
}
string Vendedor::getDireccion(){
    return _direccion;
}
