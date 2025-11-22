#pragma once
#include "ArchivoVendedores.h"
#include "Vendedor.h"

class ManagerVendedores
{

public:
    ManagerVendedores();
    void crearVendedor();
    
    void crearNuevoVendedor(); //nuevo, de la rama-personal
    
    Vendedor pedirNuevosDatos(); 
        
    void listarVendedores();
    void modificarVendedor();
    void eliminarVendedor();
    void obtenerVendedorPorId();

private:
    ArchivoVendedores _archivoVendedores; //recibe un archivo de vendedor para trabajar en él.
};
