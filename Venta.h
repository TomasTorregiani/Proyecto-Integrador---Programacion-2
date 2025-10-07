#pragma once

#include "Cliente.h"
#include "DetalleVenta.h"


class Venta{
public:
    //Constructores
    Venta();
    Venta(int idVenta, Cliente cliente, std::string fecha, int cantidadDetalles);
    ~Venta();

    bool agregarDetalle(DetalleVenta detalle);
    float calcularTotal();

    //No es necesario ningun setter

    //Getters
    int getIdVenta();
    Cliente getCliente(); //Composicion
    std::string getFecha(); /*Hacemos una clase para fecha? Quizas podamos
                            implementarla en otras cosas mas adelante*/
    int getCantidadDetalles();

protected:

private:
    int _idVenta;
    Cliente _cliente;
    char _fecha[30];
    DetalleVenta* _detalles; //Detalles es cada producto de la venta
    int _cantidadDetalles;
    int _detallesAgregados;
};


