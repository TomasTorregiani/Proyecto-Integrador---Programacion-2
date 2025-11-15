#pragma once
#include "ArchivoProductos.h"
#include "Producto.h"

class ManagerProductos
{

public:
		ManagerProductos();
    void nuevoProducto();
    void listarProductos();
    void eliminarProducto();
    void modificarProducto();	
    
    ~ManagerProductos(); 

/*protected:
		void mostrarProducto(Producto producto);*/
		
private:
    ArchivoProductos* _archivo; //recibe un archivo de clientes para trabajar en él.
};

