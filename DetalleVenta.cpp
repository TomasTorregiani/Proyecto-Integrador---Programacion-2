
#include "DetalleVenta.h"

DetalleVenta::DetalleVenta()
:_cantidad(0){}

DetalleVenta::DetalleVenta(Producto producto, int cantidad)
:_producto(producto) , _cantidad(cantidad){}

Producto DetalleVenta::getProducto(){
    return _producto;
}

int DetalleVenta::getCantidad(){
    return _cantidad;
}

float DetalleVenta::getSubtotal(){
    return _producto.getPrecio() * _cantidad;
}
