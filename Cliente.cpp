#include <iostream>
#include <cstring>
#include "Cliente.h"
#include "FuncionesGlobales.h"

using namespace std;

Cliente::Cliente()
:Persona() , _idCliente(0), _cuil(0), _activo(true){} //hereda el constructor de Persona;

Cliente::Cliente(int IdCliente, string nombre,string apellido, int cuil, int numeroTelefono, string email, string direccion, bool value)
								: Persona(nombre, apellido, numeroTelefono, email, direccion)
{
    _idCliente = contarRegistros("clientes.dat", sizeof(Cliente)) + 1;
    _cuil = cuil;
    _activo = true;
}

void Cliente::setIdCliente(int idCliente){
    _idCliente = idCliente;
}

void Cliente::setCuil(int cuil){
    _cuil = cuil;
}

void Cliente::setActivo(bool value){
    _activo = value;
}
int Cliente::getIdCliente(){
    return _idCliente;
}

int Cliente::getCuil(){
    return _cuil;
}

bool Cliente::getActivo(){
    return _activo;
}

void Cliente::mostrarCliente(){ //esto deberia ser un metodo del managerClientes; 
	
		cout << endl; 
    cout << "=== DATOS DEL CLIENTE " << _idCliente << " ===" << endl << endl; 
    cout << "ID Cliente: " << _idCliente << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "Numero de telefono: " << _numeroTelefono << endl;
    cout << "Email: " << _email << endl;
    if(_activo)
		{
			cout << "Estado: Activo" << endl; 
		}else
			{
				cout << "Estado: Inactivo" << endl; 
			}
    
}
