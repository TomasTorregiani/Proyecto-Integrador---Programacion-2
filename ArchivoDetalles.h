#pragma once

#include "DetalleVenta.h"
#include "Venta.h"

class ArchivoDetalles(){
private:
    char _nombre[50];Pero
    int _tamanioRegistro;
public:
    ArchivoDetalles(const char* n);
    int agregarDetalle(DetalleVenta& detalle);
    int verDetalleVenta(int idVenta, DetalleVenta *detalles);

    /*Venta obtenerVenta(int idVenta);
    int eliminarVenta(int idVenta);*/  //==> Estos corresponden a ArchivoVentas.h

};
