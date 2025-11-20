#pragma once

#include "Vendedor.h"

class ArchivoVendedores
{

public:
    ArchivoVendedores(const char* nombreArchivo = "vendedores.dat");
    bool guardarVendedor(Vendedor registro); //ok. siempre guarda al final.
    Vendedor buscarVendedorPorId(int idVendedor);
    bool agregarVendedor(Vendedor registro); 
    Vendedor* obtenerVendedores(int cantidadVendedores);
    bool eliminarDatosVendedor(int idVendedor); //TODO
    int modificarDatosVendedor(Vendedor registro, int posicion); //TODO

    int getTamanioRegistro();
    int getCantidadRegistros();

    void listarVendedores();

		int obtenerPosicionVendedor(int idVendedor);
    
private:
    char _nombre[50];
    int _tamanioRegistro;
};
