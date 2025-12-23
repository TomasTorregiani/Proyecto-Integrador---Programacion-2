#include <iostream>
#include <cstring>
#include "Vendedor.h"
#include "FuncionesGlobales.h"

using namespace std;

Vendedor::Vendedor()
:Persona(), _idVendedor(0), _activo(false) {} //el constructor "vacio";

Vendedor::Vendedor(int idVendedor, string nombre,string apellido, int numeroTelefono,
									string email, string direccion, bool activo)
									: Persona(nombre, apellido, numeroTelefono, email, direccion)
{
    _idVendedor = contarRegistros("vendedores.dat", sizeof(Vendedor)) + 1;
    _activo = true;
}

//setters

void Vendedor::setIdVendedor(int idVendedor)
{
    _idVendedor = idVendedor;
}

void Vendedor::setActivo(bool value)
{
    _activo = value;
}

//getters

int Vendedor::getIdVendedor()
{
    return _idVendedor;
}

bool Vendedor::getActivo()
{
    return _activo;
}

void Vendedor::mostrarVendedor()
{
    cout << endl;
    cout << "=== DATOS DEL VENDEDOR " << _idVendedor << " ===" << endl << endl;
    cout << "ID: " << _idVendedor << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "Telefono: " << _numeroTelefono << endl;
    cout << "Email: " << _email << endl;
    cout << "Direccion: " << _direccion << endl;
    cout << "Estado: " << (_activo ? "Activo" : "Inactivo") << endl;
}



