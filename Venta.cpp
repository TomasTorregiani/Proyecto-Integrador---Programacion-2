#include <iostream>
#include <cstring>
#include "Venta.h"
#include "DetalleVenta.h"
#include "FuncionesGlobales.h"

Venta::Venta()
    :_idVenta(0), _idVendedor(0), _idCliente(0), _cantidadDetalles(0)
{
    strcpy(_fecha, "");
}

Venta::Venta(int idCliente, int idVendedor, std::string fecha){
	
}

Venta::Venta(int idVenta,  std::string fecha, int IdCliente, int IdVendedor, DetalleVenta detalle)
{
    _idVenta = contarRegistros("ventas.dat", sizeof(Venta)) + 1;
    _idCliente = IdCliente;
    _idVendedor = IdVendedor;
    strcpy(_fecha,fecha.c_str());
    _cantidadDetalles = 0;
    _detalles = nullptr;
    _estado = true;

}

/*bool Venta::agregarVendedor()
{

}

bool Venta::agregarCliente()
{
    
}

bool Venta::agregarFecha()
{

}*/

Venta::~Venta()
{
    delete[] _detalles;
}

bool Venta::agregarDetalle(DetalleVenta detalle)
{
    DetalleVenta* nuevo = new DetalleVenta[_cantidadDetalles + 1];
    for(int i = 0; i < _cantidadDetalles; i++)
    {
        nuevo[i] = _detalles[i];
    }
    nuevo[_cantidadDetalles] = detalle;
    delete[] _detalles;
    _detalles = nuevo;
    _cantidadDetalles++;
    return true;
}

bool Venta::eliminarVenta()
{
    _estado = false;
}

long Venta::calcularTotal()
{
    float total = 0;
    for(int i = 0; i < _cantidadDetalles; i++)
    {
        total += _detalles[i].getSubtotal();
    }
    return total;
}
int Venta::getIdVenta()
{
    return _idVenta;
}
int Venta::getIdCliente()
{
    return _idCliente;
}
int Venta::getIdVendedor()
{
    return _idVendedor;
}
std::string Venta::getFecha()
{
    return _fecha;
}
int Venta::getCantidadDetalles()
{
    return _cantidadDetalles;
}
bool Venta::getEstado()
{
    return _estado;
}
