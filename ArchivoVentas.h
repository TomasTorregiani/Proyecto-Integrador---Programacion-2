#pragma once

class ArchivoVentas{
private:
    char _nombre[50];
    int _tamanioRegistro;
public:
    ArchivoVentas(const char* n);
    int agregarVenta(DetalleVenta nuevaVenta);
    DetalleVenta verDetalleVenta(int idVenta);
    int eliminarVenta(int idVenta);
    int contarRegistros();
};
