#pragma once
#include "Producto.h"

class ArchivoProductos{
private:
    char _nombre[50];
    int _tamanioRegistro;
public:
    ArchivoProductos(const char* n);
    int agregarNuevoProducto(Producto nuevoProducto);
    bool modificarStock(int idProducto, int nuevoStock);
    Producto buscarProductoPorId(int idProducto);
    int buscarPosicionPorId(int idProducto);
    int agregarProductoModificado(Producto productoModificado, int posicionProdModificado);
    Producto *obtenerProductos(int cantidadProductos);
};
