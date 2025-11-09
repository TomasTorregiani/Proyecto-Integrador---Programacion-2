#pragma once
#include "ArchivoVentas.h"
#include "Venta.h"

class ManagerVentas
{

public:
		ManagerVenta();
    void nuevaVenta();
    void agregarProducto(); //ojo acá.
    void listarVentas();
    void eliminarVenta(int idVenta); //sería como una nota de crédito.
    void cargarCliente();
    void modificarVenta();

/*protected:
		void mostrarVenta(Venta venta);*/
		
private:
    ArchivoVentas _archivo; //recibe un archivo de ventas para trabajar en él.
};
