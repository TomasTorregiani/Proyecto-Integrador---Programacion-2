#pragma once
#include "ArchivoVentas.h"
#include "Venta.h"

class ManagerVentas
{

public:
		ManagerVentas();
		
    bool nuevaVenta();
    bool agregarFecha();
    bool agregarVendedor();
    bool agregarCliente();
    bool agregarDetalleVenta(); //ojo acá. Vincular con DetalleVenta
    void mostrarResumen(); //muestra la factura y el total. Si el usuario dá el okey, la guarda.
     
    bool guardarVenta(); 
    
		void generarFactura(); 
    
    void listarVentas();
    void eliminarVenta(int idVenta); //sería como una nota de crédito.
    
		~ ManagerVentas(); 
    
    /*Validaciones
    bool validarStock(int idProducto, int cantidad);
    
    // Actualizar datos relacionados
    bool actualizarStock(const Venta& venta);
    
    // Consultas y reportes
    void listarVentas();
    void consultarPorFecha(Fecha inicio, Fecha fin);
    void consultarPorCliente(int idCliente);*/
	
		
private:
    ArchivoVentas _archivo; //recibe un archivo de Ventas para trabajar en él.
    Venta _ventaActual;
};
