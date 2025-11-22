#include <iostream>
#include <cstring>
#include "Cliente.h"
#include "FuncionesGlobales.h"

using namespace std;

Cliente::Cliente()
:_idCliente(0), _nombre(),
_apellido(), _cuil(0),
_tipoCliente(0), _numeroTelefono(0),
_email(""), _direccion(""){}

Cliente::Cliente(string nombre,
            string apellido, long long cuil,
            int tipoCliente, int numeroTelefono,
            string email, string direccion)
{
    _idCliente = contarRegistros("clientes.dat", sizeof(Cliente)) + 1;
    setNombre(nombre);
    setApellido(apellido);
    _cuil = 1111; //En donde se pide el cuil? No deberia ser necesario un set ya
                   //que este no deberia cambiar
    setTipoCliente(tipoCliente);
    setEmail(email);
    setDireccion(direccion);
    _activo = true;
}
void Cliente::mostrarCliente(){
    cout << "=== DATOS DEL CLIENTE ===" << endl;
    cout << "ID Cliente: " << _idCliente << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "Numero de telefono: " << _numeroTelefono << endl;
    cout << "Email: " << _email << endl;
}
void Cliente::setIdCliente(int idCliente){
    _idCliente = idCliente;
}
void Cliente::setNombre(string nombre){
    strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
    _nombre[49] = '\0';
}
void Cliente::setApellido(string apellido){
    strncpy(_apellido, apellido.c_str(), sizeof(_apellido) - 1);
    _apellido[49] = '\0';
}
void Cliente::setCuilCliente(long long cuil){
    _cuil = cuil;
}
void Cliente::setTipoCliente(int tipoCliente){
    _tipoCliente = tipoCliente;
}
void Cliente::setNumeroTelefono(int numeroTelefono){
    _numeroTelefono = numeroTelefono;
}
void Cliente::setEmail(string email){
    strncpy(_email, email.c_str(), sizeof(_email) - 1);
    _email[49] = '\0';
}
void Cliente::setDireccion(string direccion){
    strncpy(_direccion, direccion.c_str(), sizeof(_direccion) - 1);
    _direccion[49] = '\0';
}
void Cliente::setActivo(bool value){
    _activo = value;
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
bool Cliente::getActivo(){
    return _activo;
}
