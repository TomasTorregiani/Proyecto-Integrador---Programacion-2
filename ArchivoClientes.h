#pragma once
#include <cstring>
#include "Cliente.h"

class ArchivoClientes{

private:
    char _nombre[30];
    int _tamanioRegistro;

public:
    ArchivoClientes(const char* n);
    int agregarCliente(Cliente registro);
    bool modificarDatosCliente(Cliente registro, int posicion);
    Cliente buscarClientePorId(int idCliente);

    int eliminarCliente(int idCliente);
};






