#pragma once
#include "ArchivoProductos.h"
#include "Producto.h"

class ManagerProductos
{
public:
    ManagerProductos();
    void crearNuevoProducto();
    void verStockProducto();
    void eliminarProducto();
    void modificarProducto();
    Producto pedirNuevosDatos();

/*protected:
		void mostrarProducto(Producto producto);*/

private:
    ArchivoProductos _archivo; //recibe un archivo de productos para trabajar en él.
};
