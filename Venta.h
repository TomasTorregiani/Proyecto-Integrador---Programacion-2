#pragma once

#include "Vendedor.h"
#include "Cliente.h"
#include "DetalleVenta.h"


class Venta{
public:
    //Constructores
    Venta();
    //Venta(int idVenta, Cliente cliente, Vendedor vendedor, std::string fecha);//Cambie para no paasarle 2 objetos enteros
    Venta(int IdCliente, int IdVendedor, std::string fecha);
    ~Venta(); // cuando se carga el detalle de la venta?? (DetalleVenta)

    bool agregarDetalle(DetalleVenta detalle);
    long long calcularTotal();

    //No es necesario ningun setter

    //Getters
    int getIdVenta();
    int getIdCliente();
    int getIdVendedor();
    std::string getFecha();
    int getCantidadDetalles();
    void anularVenta();

protected:

private:
    int _idVenta;
    int _idCliente;
    int _idVendedor; //agregue el vendedor
    char _fecha[30];
    DetalleVenta* _detalles; //Detalles es cada producto de la venta
    int _cantidadDetalles;
    bool _anulada;
};


