#pragma once

class ArchivoVentas{
public:
    ArchivoVentas(const char* n);

    int agregarVenta(Venta& venta);
    Venta obtenerVenta(int idVenta);
private:
    char _nombre[50];
    int _tamanioRegistro;
};
