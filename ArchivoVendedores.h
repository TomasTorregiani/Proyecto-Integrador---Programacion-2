#pragma once

#include "Vendedor.h"

class ArchivoVendedores
{

public:
    ArchivoVendedores(const char* nombreArchivo = "vendedores.dat");
    bool guardarVendedor(Vendedor registro); //ok. siempre guarda al final.
    int buscarVendedorPorId(int idVendedor); //INPROCESS
    bool eliminarVendedor(int idVendedor); //TODO
    bool modificarDatosVendedor(Vendedor registro, int posicion); //TODO

    int getTamañoRegistro();
    int getCantidadRegistros();

    void listarVendedores();

		int obtenerPosicionVendedor(int idVendedor);
    
private:
    const char* _nombreArchivo;
};
