#pragma once
#include "ArchivoProductos.h"
#include "Productos.h"

class ManagerProductos
{

public:
		ManagerProducto();
    void agregarProducto();
    void listarProductos();
    void eliminarProducto();
    void modificarProducto();	

/*protected:
		void mostrarProducto(Producto producto);*/
		
private:
    ArchivoProductos _archivo; //recibe un archivo de clientes para trabajar en él.
};

