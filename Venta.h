#pragma once

#include "Vendedor.h"
#include "Cliente.h"
#include "Fecha.h"
#include "DetalleVenta.h"

class Venta
{

public:
		Venta(); 
    Venta(int idVenta, Fecha fecha, int IdVendedor, int IdCliente, DetalleVenta detalle);

    long calcularTotal();

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
    bool getEstado(); 

    ~Venta();

private:
    int _idVenta;
    char _fecha[30];
    int _idCliente;
    int _idVendedor;
    DetalleVenta* _detalles; //Detalles es cada producto de la venta
    bool _estado;
    
};


