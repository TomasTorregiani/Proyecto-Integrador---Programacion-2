#pragma once

#include "Producto.h"

class DetalleVenta{
public:
    DetalleVenta();
    DetalleVenta(Producto producto, int cantidad);

    //Getters
    Producto getProducto();
    int getCantidad();
    float getSubtotal();
private:
    Producto _producto;
    int _cantidad;
};
