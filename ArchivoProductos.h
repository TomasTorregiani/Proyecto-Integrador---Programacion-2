#pragma once
#include "Producto.h"

class ArchivoProductos{

public:
    ArchivoProductos(const char* n);

    int agregarNuevoProducto(Producto nuevoProducto);
    Producto buscarProductoPorId(int idProducto);
    int buscarPosicionPorId(int idProducto);
    int agregarProductoModificado(Producto productoModificado, int posicionProdModificado);
private:
    char _nombre[50];
    int _tamanioRegistro;
};
