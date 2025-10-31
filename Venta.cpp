
#include "Venta.h"
#include <cstring>

Venta::Venta()
:_idVenta(0), _cantidadDetalles(0){
    strcpy(_fecha, "");
}


Venta::Venta(int cliente, int vendedor, std::string fecha){
    _idVenta = contarRegistros("ventas.dat", sizeof(Venta)) + 1;
    _idCliente = IdCliente;
    _idVendedor = IdVendedor;
    strcpy(_fecha,fecha.c_str());
    _cantidadDetalles = 0;
    _detalles = nullptr;
    _anulada = false;

}

Venta::~Venta(){
    delete[] _detalles;
}

bool Venta::agregarDetalle(DetalleVenta detalle){
    DetalleVenta* nuevo = new DetalleVenta[_cantidadDetalles + 1];
    for(int i = 0; i < _cantidadDetalles; i++){
        nuevo[i] = _detalles[i];
    }
    nuevo[_cantidadDetalles] = detalle;
    delete[] _detalles;
    _detalles = nuevo;
    _cantidadDetalles++;
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

void Venta::anularVenta(){
	_anulada = true;
}
