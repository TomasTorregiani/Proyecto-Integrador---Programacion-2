#pragma once
#include "ArchivoVendedores.h"
#include "Vendedor.h"

class ManagerVendedores
{

public:
    ManagerVendedores();
    void crearVendedor();
    void listarVendedores();
    void modificarVendedor();
    void eliminarVendedor();
    void obtenerVendedorPorId();

private:
    ArchivoVendedores _archivoVendedores; //recibe un archivo de vendedor para trabajar en él.
};
