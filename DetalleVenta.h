#pragma once

#include "Producto.h"

class DetalleVenta{
public:
    DetalleVenta();
    DetalleVenta(int idVenta; Producto producto, int cantidad);

    // Getters
    int getIdVenta();
    Producto getProducto();
    int getCantidad();
    float getSubtotal();

    // Setters
    void setIdVenta(int idVenta);
    void setProducto(Producto producto);
    void setCantidad(int cantidad);
private:
    int _idVenta; //Para relacionar el detalle con la venta
    Producto _producto;
    int _cantidad;
};
