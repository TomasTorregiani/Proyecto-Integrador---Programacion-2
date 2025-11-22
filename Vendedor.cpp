#include <iostream>
#include <cstring>
#include "Vendedor.h"
#include "FuncionesGlobales.h"

using namespace std;

Vendedor::Vendedor()
: _idVendedor(0), _nombre(),
_apellido(), _numeroTelefono(0),
_email(""), _direccion(""){
}

Vendedor::Vendedor(std::string nombre,
            std::string apellido,int numeroTelefono,
            std::string email, std::string direccion)
{
    _idVendedor = contarRegistros("vendedores.dat" , sizeof(Vendedor)) + 1;
    setNombre(nombre);
    setApellido(apellido);
    setEmail(email);
    setDireccion(direccion);
    _activo = true;
}

void Vendedor::crearVendedor(){
    _idVendedor = contarRegistros("vendedores.dat" , sizeof(Vendedor)) + 1;
    cout << "Ingrese nombre: " << endl;
    cin >> _nombre;
    cout << "Ingrese apellido: " << endl;
    cin >> _apellido;
    cout << "Ingrese numero de telefono: " << endl;
    cin >> _numeroTelefono;
    cout << "Ingrese email: " << endl;
    cin >> _email;
    cout << "Ingrese direccion: " << endl;
    cin >> _direccion;
    _activo = true;
}

void Vendedor::modificarVendedor(){
    cout << "Ingrese nombre: " << endl;
    cin >> _nombre;
    cout << "Ingrese apellido: " << endl;
    cin >> _apellido;
    cout << "Ingrese número de telefono: " << endl;
    cin >> _numeroTelefono;
    cout << "Ingrese email: " << endl;
    cin >> _email;
    cout << "Ingrese direccion: " << endl;
    cin >> _direccion;
}

void Vendedor::mostrarVendedor(){
    cout << "\n--- Datos del vendedor ---\n";
    cout << "ID: " << _idVendedor << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "Telefono: " << _numeroTelefono << endl;
    cout << "Email: " << _email << endl;
    cout << "Direccion: " << _direccion << endl;
    cout << "Activo: " << (_activo ? "Si" : "No") << endl;
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
void Vendedor::setIdVendedor(int idVendedor){
    _idVendedor = idVendedor;
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
void setActivo(bool value){
    _activo = value;
}
bool Vendedor::getEstado(){
    return _activo;
}
