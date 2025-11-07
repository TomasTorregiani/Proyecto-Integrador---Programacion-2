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
    void eliminarVenta(); //sería como una nota de crédito.

/*protected:
		void mostrarVenta(Venta venta);*/
		
private:
    ArchivoVentas _archivo; //recibe un archivo de ventas para trabajar en él.
};
