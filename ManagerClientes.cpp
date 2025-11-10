#include <iostream>
#include <string>
#include <cstring>
#include "ManagerClientes.h"
#include "ArchivoClientes.h"
#include "FuncionesGlobales.h"
#include "Cliente.h"

using namespace std;

ManagerClientes::ManagerClientes()
{
	_archivo = new ArchivoClientes("clientes.dat");
}

void ManagerClientes::nuevoCliente()  //crea clase, pide datos, valida y graba.
{
    Cliente cliente;
    char nombre[50], apellido[50], email[50], direccion[100];
    int idCliente, cuilCliente, telefonoCliente;
    bool estado;
    
    cliente.setIdCliente();
    
    cout << "Ingresar nombre cliente nuevo: " << endl;
    cin.ignore();
    cin.getline(nombre, 50);
    cliente.setNombre(nombre);
    
    cout << "Ingresar apellido cliente nuevo: " << endl;
    cin.getline(apellido, 50);
		cliente.setApellido(apellido);
		
    cout << "Ingresar cuil cliente nuevo: " << endl;
    cin >> cuilCliente;
    cliente.setCuil(cuilCliente);
    
    cout << "Ingresar numero de telefono: " << endl;
    cin >> telefonoCliente;
    cliente.setNumeroTelefono(telefonoCliente);
    
    cout << "Ingresar email cliente nuevo: " << endl;
    cin.ignore();
    cin.getline(email, 50);  
    
    cout << "Ingresar direccion cliente nuevo: " << endl;
    cin.getline(direccion, 50);  
     
    estado = true;
    cliente.setEstado(estado);

    if(ArchivoClientes.guardarCliente(cliente))  //si está todo okey, graba.
    {
        cout << "El cliente se guardo correctamente" << endl;
    }
    else
    {
        cout << " === Error: El cliente no se guardo correctamente === " << endl;
    }
}

void ManagerClientes::eliminarCliente(int idCliente)
{
	/*Si */
	
	/*if(ArchivoClientes.eliminarCliente(int idCliente))  //se está todo okey, graba.
    {
        cout << "El cliente se guardo correctamente" << endl;
    }
    else
    {
        cout << " === Error: El cliente no se guardo correctamente === " << endl;
    }*/
}


/*void ManagerClientes::modificarCliente()
{
	cout << "Ingresar nombre cliente nuevo: " << endl;
    cin >> _nombre;
    cout << "Ingresar apellido cliente nuevo: " << endl;
    cin >> _apellido;
    cout << "Ingresar cuit cliente nuevo: " << endl;
    cin >> _cuil;
    cout << "Ingresar tipo cliente nuevo: " << endl;
    cin >> _tipoCliente;
    cout << "Ingresar numero de telefono: " << endl;
    cin >> _numeroTelefono;
    cout << "Ingresar email cliente nuevo: " << endl;
    cin >> _email;
    cout << "Ingresar direccion cliente nuevo: " << endl;
    cin >> _direccion;


}*/

void ManagerClientes::mostrarCliente(int idCliente){
	/*
    cout << "=== DATOS DEL CLIENTE ===" << endl;
    cout << "ID Cliente: " << _idCliente << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "Numero de telefono: " << _numeroTelefono << endl;
    cout << "Email: " << _email << endl;*/
}

/*void ManagerClientes::listarClientes(){
		ArchivoClientes.listarClientes();
		//TODO
}*/
