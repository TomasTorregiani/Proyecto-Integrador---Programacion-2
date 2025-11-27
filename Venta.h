#pragma once
#include "Vendedor.h"
#include "Cliente.h"
#include "Fecha.h"
#include <string>

//Declaracion adelantada
class DetalleVenta;

class Venta{
public:
    Venta();
    Venta(int IdCliente, int IdVendedor, Fecha fecha);
     // cuando se carga el detalle de la venta?? (DetalleVenta)

    bool agregarDetalle(DetalleVenta detalle);

    ~Venta();

    //No es necesario ningun setter

    //Getters
    int getIdVenta();
    int getIdCliente();
    int getIdVendedor();
    Fecha getFecha();
    std::string getFechaString();
    int getCantidadDetalles();
    float getTotal();
    bool getAnulada();
    void anularVenta();

protected:

private:
    int _idVenta;
    int _idCliente;
    int _idVendedor; //agregue el vendedor
    Fecha _fecha;
    DetalleVenta* _detalles; //Detalles es cada producto de la venta
    int _cantidadDetalles;
    float _totalVenta;
    bool _anulada;
};


