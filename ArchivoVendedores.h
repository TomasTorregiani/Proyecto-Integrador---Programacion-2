#pragma once

#include "Vendedor.h"

class ArchivoVendedores
{

public:
    ArchivoVendedores(const char* nombreArchivo = "vendedores.dat");
    bool guardarVendedor(Vendedor registro); //ok. siempre guarda al final.
    std::string buscarVendedorPorId(int idVendedor); //INPROCESS
    bool eliminarDatosVendedor(int idVendedor); //TODO
    int modificarDatosVendedor(Vendedor registro, int posicion); //TODO

    int getTamanioRegistro();
    int getCantidadRegistros();

    void listarVendedores();

		int obtenerPosicionVendedor(int idVendedor);
    
private:
    const char* _nombreArchivo;
    int _tamanioRegistro;
};
