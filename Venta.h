#pragma once
#include "Vendedor.h"
#include "Cliente.h"
#include "Fecha.h"
#include "DetalleVenta.h"
#include <string>

class Venta
{

public:
		Venta(); 
    Venta(int idVenta, std::string fecha, int IdVendedor, int IdCliente, DetalleVenta detalle);
    Venta(int idCliente, int idVendedor, std::string fecha);

    long calcularTotal();
    bool eliminarVenta(); // esto lo tendría que hacer el managerVentas.
    bool agregarDetalle(DetalleVenta detalle);
    
    bool setIdVenta();
    bool setFecha();
    bool setIdVendedor();
    bool setIdCliente();
    void setDetalleVenta();
    bool setEstado(); 
    
    int getIdVenta();
		std::string getFecha();
    int getIdVendedor();
		int getIdCliente();
    int getDetalleVenta();
    int getCantidadDetalles();
    bool getEstado(); 

    ~Venta();

private:
    int _idVenta;
    char _fecha[30];
    int _idCliente;
    int _idVendedor;
    DetalleVenta* _detalles; //Detalles es cada producto de la venta
    bool _estado;
    int _cantidadDetalles; 
    
};


