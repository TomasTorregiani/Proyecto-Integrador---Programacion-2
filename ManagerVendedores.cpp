#include <iostream>
#include "ManagerVendedores.h"

using namespace std;

ManagerVendedores::ManagerVendedores(){}

void ManagerVendedores::nuevoVendedor(){
		
		Vendedor vendedor; 
		//FIXME
		
    ArchivoVendedores archivoVendedor("vendedores.dat");
    int agregado = archivoVendedor.nuevoVendedor();
    if(agregado == 1){
        cout << "Vendedor agregado correctamente" << endl;
    }else{
        cout << "Error al agregar el vendedor" << endl;
    }
}


void ManagerVendedores::listarVendedores(){
	
//TODO
	
}

void ManagerVendedores::modificarVendedor(){
	
//TODO
	
}	

void ManagerVendedores::eliminarVendedor(int id){
	
	int pos = _archivo.//FIXME
	
	_activo = false;
}
