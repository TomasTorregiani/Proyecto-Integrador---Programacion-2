#include <iostream>
#include "ManagerClientes.h"

using namespace std;

ManagerClientes::ManagerClientes(){

}
	
void ManagerClientes::nuevoCliente(){
		
		
		
		cout << "Ingrese el nombre del Cliente: " << endl; 
		cin << _nombre;
		
		//FIXME
		
    ArchivoClientes archivoCliente("clientes.dat");
    int agregado = archivoCliente.nuevoCliente(cliente);
    if(agregado == 1){
        cout << "Cliente agregado correctamente" << endl;
    }else{
        cout << "Error al agregar el cliente" << endl;
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



