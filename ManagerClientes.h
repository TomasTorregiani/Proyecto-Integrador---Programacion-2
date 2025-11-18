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
    Cliente pedirNuevosDatos();
    void modificarCliente();
    Cliente buscarClientePorId(int idCliente);
    int eliminarCliente(int idCliente);
    int activarCliente(int idCliente);
};
