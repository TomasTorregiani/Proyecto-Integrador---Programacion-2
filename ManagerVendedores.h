#pragma once
#include "ArchivoVendedores.h"
#include "Vendedores.h"

class ManagerVendedores
{

public:
		ManagerVendedores();
    void agregarVendedor();
    void listarVendedores();
    void modificarVendedor();
    void eliminarVendedor();

/*protected:
		void mostrarVendedor(Vendedor vendedor);*/
		
private:
    ArchivoVendedores _archivo; //recibe un archivo de vendedor para trabajar en él.
};
