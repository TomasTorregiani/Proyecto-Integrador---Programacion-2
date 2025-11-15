#pragma once
#include "DetalleVenta.h"
#include "Venta.h"

class ArchivoDetalles{

public:
    ArchivoDetalles(const char* n);
    int agregarDetalle(DetalleVenta& detalle);
    int verDetalleVenta(int idVenta, DetalleVenta *detalles);
    
private:
    char _nombre[50];
    int _tamanioRegistro;
};
