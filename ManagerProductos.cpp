#include <iostream>
#include "ManagerProductos.h"

using namespace std;

ManagerProductos ManagerProductos(){

}

void ManagerProductos::nuevoProducto(){
		
		Producto producto; 
    ArchivoProductos archivoProducto("productos.dat");
    int agregado = archivoProducto.agregarNuevoProducto(producto);
    if(agregado == 1){
        cout << "Producto agregado correctamente" << endl;
    }else{
        cout << "Error al agregar el producto" << endl;
    }
}


void ManagerProductos::listarProductos(){
	
//TODO
	
}

void ManagerProductos::modificarProducto(){
	
//TODO
	
}	

void ManagerProductos::eliminarProducto(int idProducto){
	
	/*int pos = _archivo.//FIXME
	
	_activo = false;*/
}
