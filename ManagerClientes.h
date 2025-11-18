#pragma once
#include <iostream>
#include "ArchivoClientes.h"
#include "Cliente.h"

class ManagerClientes{
private:
    ArchivoClientes _archivoCliente;
public:
    ManagerClientes();
    Cliente crearNuevoCliente();
    int crearCliente();
    int modificarCliente(int idCliente);
};
