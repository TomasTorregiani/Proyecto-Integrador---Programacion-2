
#include "Venta.h"
#include <cstring>

Venta::Venta()
:_idVenta(0), _cantidadDetalles(0){
    strcpy(_fecha, "");
}

Venta::Venta(int idVenta, Cliente cliente, Vendedor vendedor, std::string fecha /*int cantidadDetalles*/){
    _idVenta = idVenta;
    _cliente = cliente;
    _vendedor = vendedor;
    strcpy(_fecha,fecha.c_str());
    /*_cantidadDetalles = cantidadDetalles;*/
    _detallesAgregados = 0;
    _detalles = new DetalleVenta[_cantidadDetalles];
}

Venta::~Venta(){
    delete[] _detalles;
}

bool Venta::agregarDetalle(DetalleVenta detalle){
    if(_detallesAgregados >= _cantidadDetalles){
        return false;
    }
    _detalles[_detallesAgregados] = detalle;
    _detallesAgregados++;
    return true;
}

long long Venta::calcularTotal(){
    float total = 0;
    for(int i = 0; i < _cantidadDetalles; i++){
        total += _detalles[i].getSubtotal();
    }
    return total;
}

int Venta::getIdVenta(){
    return _idVenta;
}

Cliente Venta::getCliente(){
    return _cliente;
}

Vendedor Venta::getVendedor(){
	return _vendedor;
}

std::string Venta::getFecha(){
    return _fecha;
}

int Venta::getCantidadDetalles(){
    return _cantidadDetalles;
}
