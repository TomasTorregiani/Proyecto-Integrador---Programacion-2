#pragma once
#include "ArchivoProductos.h"
#include "Producto.h"

class ManagerProductos
{
public:
    ManagerProductos();
    void crearNuevoProducto();
    void verStockProducto();
    bool modificarStock();
    bool modificarStock(int idProducto, int nuevoStock);
    void eliminarProducto();
    void activarProducto();
    void modificarProducto();
    Producto pedirNuevosDatos();

/*protected:
		void mostrarProducto(Producto producto);*/

private:
    ArchivoProductos _archivo; //recibe un archivo de productos para trabajar en él.
};
