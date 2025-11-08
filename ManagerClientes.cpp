#include <iostream>
#include "ManagerClientes.h"

using namespace std;

ManagerClientes::ManagerClientes(){

}
	
void ManagerClientes::nuevoCliente()
:_activo=true
	{ 
		//FIXME
		Cliente cliente; 
		//Pide todos los datos del cliente??
		
		cliente.setNombre();
		cliente.setApellido();
		cliente.setCuil();
		cliente.setNumeroTelefono();
		cliente.setEmail();
		cliente.setDireccion();
		
		//Fin de pedir todos los datos; 
		
    if(ArchivoClientes.guardarCliente(cliente)){
			cout << "El cliente se guardo correctamente" << endl;
    }else {
			cout << " === Error: El cliente no se guardo correctamente === " << endl;
    }
}

void ManagerClientes::listarClientes(){
	
//TODO
	
}

void ManagerClientes::modificarCliente(){
	
//TODO
	
}	

void ManagerClientes::eliminarCliente(int id){
	
	int pos = _archivo.//FIXME
	
	_activo = false;
}



