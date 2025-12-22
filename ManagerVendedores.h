#pragma once
#include "ArchivoVendedores.h"
#include "Vendedor.h"

class ManagerVendedores
{

public:
    ManagerVendedores();
    void crearVendedor();
    Vendedor crearNuevoVendedor(); 
    void guardarUnVendedor(Vendedor vendedor);
        
    Vendedor pedirNuevosDatos();  // ?????
    
    void listarVendedores();
    void eliminarVendedor();
    void activarVendedor(); 
    void obtenerVendedorPorId();
    void modificarVendedor();

private:
    ArchivoVendedores _archivoVendedores; //recibe un archivo de vendedor para trabajar en él.
};
