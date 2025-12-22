#pragma once
#include "Vendedor.h"

class ArchivoVendedores{
private:
    char _nombre[50];
    int _tamanioRegistro;
public:
    ArchivoVendedores(const char *n);
    int agregarVendedor(Vendedor vendedor);
    Vendedor buscarVendedorPorId(int idVendedor);
    int buscarPosicionDelVendedor(int idVendedor);
    int modificarDatosVendedor(Vendedor registroVendedor, int posicion);
    int obtenerPosicionVendedor(int idVendedor);
    void listarVendedores();
    Vendedor* obtenerVendedores(int cantidadVendedores);
};

