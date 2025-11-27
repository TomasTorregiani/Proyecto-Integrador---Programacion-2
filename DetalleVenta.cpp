
#include "DetalleVenta.h"

DetalleVenta::DetalleVenta()
:_cantidad(0), _idVenta(0){}

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
int DetalleVenta::getIdVenta(){
    return _idVenta;
}
void DetalleVenta::setIdVenta(int idVenta){
    _idVenta = idVenta;
}
