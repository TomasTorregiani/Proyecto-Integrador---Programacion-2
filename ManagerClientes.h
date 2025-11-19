#pragma once
#include <iostream>
#include "ArchivoClientes.h"
#include "Cliente.h"

class ManagerClientes{
public:
    ManagerClientes();
    Cliente crearNuevoCliente();
    void mostrarCliente();
    void eliminarCliente();
    void modificarCliente();
		~ManagerClientes();

private:
    ArchivoClientes _archivoCliente; //recibe un archivo de clientes para trabajar en él.
};
