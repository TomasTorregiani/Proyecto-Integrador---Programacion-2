#include <iostream>
#include <cstring>
#include "Cliente.h"

using namespace std;

Cliente::Cliente()
:_idCliente(0), _nombre("Tomas"),
_apellido("Torre"), _cuil(0),
_tipoCliente(0), _numeroTelefono(0),
_email(""), _direccion(""){}

Cliente::Cliente(int idCliente, std::string nombre,
            std::string apellido, int cuil,
            int tipoCliente, int numeroTelefono,
            std::string email, std::string direccion)
{
    _idCliente = 0; //Empezar en 1 e ir sumando;
    setNombre(nombre);
    setApellido(apellido);
    _cuil = 1111; //En donde se pide el cuil? No deberia ser necesario un set ya
                   //que este no deberia cambiar
    setTipoCliente(tipoCliente);
    setEmail(email);
    setDireccion(direccion);
}
void Cliente::setNombre(string nombre){
    strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
    _nombre[49] = '\0';
}
void Cliente::setApellido(string apellido){
    strncpy(_apellido, apellido.c_str(), sizeof(_apellido) - 1);
    _apellido[49] = '\0';
}
void Cliente::setTipoCliente(int tipoCliente){
    _tipoCliente = tipoCliente;
}
void Cliente::setNumeroTelefono(int numeroTelefono){
    _numeroTelefono = numeroTelefono;
}
void Cliente::setEmail(string email){
    strncpy(_email, email.c_str(), sizeof(_email) - 1);
}
void Cliente::setDireccion(string direccion){
    strncpy(_direccion, direccion.c_str(), sizeof(_direccion) - 1);
    _direccion[49] = '\0';
}

int Cliente::getIdCliente(){
    return _idCliente;
}
string Cliente::getNombre(){
    return _nombre;
}
string Cliente::getApellido(){
    return _apellido;
}
int Cliente::getCuil(){
    return _cuil;
}
int Cliente::getTipoCliente(){
    return _tipoCliente;
}
string Cliente::getEmail(){
    return _email;
}
string Cliente::getDireccion(){
    return _direccion;
}
