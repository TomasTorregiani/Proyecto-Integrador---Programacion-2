#pragma once
#include "Producto.h"

class ArchivoProductos{
private:
    char _nombre[50];
    int _tamanioRegistro;
public:
    ArchivoProductos(const char* n);

    Producto buscarProductoPorId(int idProducto);
};
