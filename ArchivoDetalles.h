#pragma once

#include "DetalleVenta.h"
#include "Venta.h"

class ArchivoDetalles{
private:
    char _nombre[50];
    int _tamanioRegistro;
public:
    ArchivoDetalles(const char* n);
    int agregarDetalle(DetalleVenta& detalle);
    int verDetalleVenta(int idVenta, DetalleVenta *detalles);
    int *obtenerVentasPorProducto(int cantidadDetallesVendidos, int &tamanioArray);
};
