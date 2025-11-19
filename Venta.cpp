#include <iostream>
#include <cstring>
#include "Venta.h"
#include "DetalleVenta.h"
#include "FuncionesGlobales.h"

Venta::Venta()
:_idVenta(0), _idCliente(0), _idVendedor(0), _cantidadDetalles(0), _anulada(false) {
    strcpy(_fecha, "");
    _detalles = nullptr;
}

Venta::Venta(int IdCliente, int IdVendedor, std::string fecha){
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

void Venta::anularVenta(){
    _anulada = true;
}

void Venta::calcularTotal(){
    float total = 0;
    for(int i = 0; i < _cantidadDetalles; i++){
        total += _detalles[i].getSubtotal();
    }
    _totalVenta = total;
}

float Venta::getTotal(){
    return _totalVenta;
}

int Venta::getIdVenta(){
    return _idVenta;
}
int Venta::getIdCliente(){
    return _idCliente;
}
int Venta::getIdVendedor(){
    return _idVendedor;
}
std::string Venta::getFecha(){
    return _fecha;
}
//int Venta::getCantidadDetalles(){ // Esto creo que no se usa para nada
//    return _cantidadDetalles;
//}
bool Venta::getAnulada(){
    return _anulada;
}
