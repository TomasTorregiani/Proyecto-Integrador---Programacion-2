#pragma once
#include <iostream>
#include "ArchivoClientes.h"
#include "Cliente.h"

class ManagerClientes{
private:
    ArchivoClientes _archivo;
public:
    bool agregarCliente(Cliente cliente);
};
