#pragma once

#include "Vendedor.h"
#include "Cliente.h"
#include "DetalleVenta.h"


class Venta{
public:
    //Constructores
    Venta();
    Venta(int idVenta, Cliente cliente, Vendedor vendedor, std::string fecha, int cantidadDetalles);
    ~Venta();

    bool agregarDetalle(DetalleVenta detalle);
    float calcularTotal();

    //No es necesario ningun setter

    //Getters
    int getIdVenta();
    Cliente getCliente(); //Composicion
    Vendedor getVendedor();
    std::string getFecha();
    int getCantidadDetalles();

protected:

private:
    int _idVenta;
    Cliente _cliente;
    Vendedor _vendedor; //agregue el vendedor
    char _fecha[30];
    DetalleVenta* _detalles; //Detalles es cada producto de la venta
    int _cantidadDetalles;
    int _detallesAgregados;
};


