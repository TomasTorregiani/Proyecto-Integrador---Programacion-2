#include <iostream>
#include <cstring>
#include <string>
#include "Cliente.h"
#include "ArchivoClientes.h"
#include "FuncionesGlobales.h"

using namespace std;

Cliente::Cliente()
:_idCliente(0), _nombre(),
_apellido(), _cuil(0), _numeroTelefono(0),
_email(""), _direccion(""), _estado(true){

}

Cliente::Cliente(int idCliente, std::string nombre,std::string apellido, int cuil,int numeroTelefono,std::string email, std::string direccion, bool estado)
{
    _idCliente = contarRegistros("clientes.dat", sizeof(Cliente)) + 1;
    setNombre(nombre);
    setApellido(apellido);
    _cuil = 1111; //En donde se pide el cuil? No deberia ser necesario un set ya
                   //que este no deberia cambiar
    setEmail(email);
    setDireccion(direccion);
    _estado = true;
}

void Cliente::mostrarCliente(){
    cout << "=== DATOS DEL CLIENTE ===" << endl;
    cout << "ID Cliente: " << _idCliente << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "Numero de telefono: " << _numeroTelefono << endl;
    cout << "Email: " << _email << endl;
}

/*void Cliente::cargarCliente(){

	//TODO//

}*/

void Cliente::setNombre(std::string nombre){
    strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
    _nombre[49] = '\0';
}
void Cliente::setApellido(std::string apellido){
    strncpy(_apellido, apellido.c_str(), sizeof(_apellido) - 1);
    _apellido[49] = '\0';
}
void Cliente::setCuil(int cuil){
		_cuil = cuil;
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

int Cliente::setIdCliente(){
	_idCliente =  contarRegistros("clientes.dat", sizeof(Cliente)) + 1;
}

bool Cliente::setEstado(bool estado){
	_estado = estado;
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

string Cliente::getEmail(){
    return _email;
}
string Cliente::getDireccion(){
    return _direccion;
}

int Cliente::getNumeroTelefono(){
	return _numeroTelefono; 
}

bool Cliente::getEstado(){
	return _estado;
}
