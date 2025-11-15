#pragma once
#include "ArchivoVentas.h"
#include "Venta.h"

class ManagerVentas
{

public:
		ManagerVentas();
		
    bool nuevaVenta(); //hace todo, carga datos de venta, productos, calcula el total y guarda la venta.
		void generarFactura(int idVenta); 
		bool agregarDetalleVenta();
		void verDetalleFactura(); 
    void listarVentas();
    void eliminarVenta(int idVenta); //sería como una nota de crédito.
    
		~ManagerVentas(); 
    
    /*Consultas y reportes
    void listarVentas();
    void consultarPorFecha(Fecha inicio, Fecha fin);
    void consultarPorCliente(int idCliente);*/
	
		
private:
    ArchivoVentas* _archivo; //recibe un archivo de Ventas para trabajar en él.
    Venta _ventaActual;
};
