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
    void crearCliente();
    Cliente pedirNuevosDatos();
    void modificarCliente();
    void buscarClientePorId();
    void eliminarCliente();
    void activarCliente();
    void listarClientes();
};
