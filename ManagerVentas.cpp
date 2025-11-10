#include <iostream>
#include "ManagerVentas.h"

using namespace std;

ManagerVentas ManagerVentas(){
}

void ManagerVentas::nuevaVenta(){
		
		Venta venta; 
		
    ArchivoVentas archivoVenta("ventas.dat");
    int agregado = archivoVenta.nuevoVenta(venta);
    if(agregado == 1){
        cout << "Venta agregada correctamente" << endl;
    }else{
        cout << "Error al agregar la venta" << endl;
    }
}

void ManagerVentas::cargarCliente(){

}

void ManagerVentas::listarVentas(){
	
//TODO
	
}

void ManagerVentas::modificarVenta(){
	
//TODO
	
}	

void ManagerVentas::eliminarVenta(int idVenta){
	
	/*int pos = _archivo;//FIXME
	
	_activo = false;*/
}



