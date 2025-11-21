#pragma once
#include "Vendedor.h"
#include "Cliente.h"

//Declaracion adelantada
class DetalleVenta;

class Venta{
public:
    Venta();
    Venta(int IdCliente, int IdVendedor, std::string fecha);
    ~Venta(); // cuando se carga el detalle de la venta?? (DetalleVenta)

    bool agregarDetalle(DetalleVenta detalle);

    void calcularTotal();

    //No es necesario ningun setter

    //Getters
    int getIdVenta();
    int getIdCliente();
    int getIdVendedor();
    std::string getFecha();
    int getCantidadDetalles();
    float getTotal();
    bool getAnulada();
    void anularVenta();

protected:

private:
    int _idVenta;
    int _idCliente;
    int _idVendedor; //agregue el vendedor
    char _fecha[30];
    DetalleVenta* _detalles; //Detalles es cada producto de la venta
    int _cantidadDetalles;
    float _totalVenta;
    bool _anulada;
};


