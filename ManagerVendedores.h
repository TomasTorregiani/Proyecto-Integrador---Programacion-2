#pragma once
#include "ArchivoVendedores.h"
#include "Vendedor.h"

class ManagerVendedores
{

public:
    ManagerVendedores();
    Vendedor crearVendedor();
    void listarVendedores();
    void modificarVendedor();
    void eliminarVendedor();

private:
    ArchivoVendedores _archivoVendedores; //recibe un archivo de vendedor para trabajar en él.
};
