#pragma once
#include "ArchivoClientes.h"
#include "Cliente.h"

class ManagerClientes
{

public:
		ManagerClientes();
    void nuevoCliente();
    void mostrarCliente(int idCliente);
    void eliminarCliente(int idCliente);
    void modificarCliente(int idCliente);	

/*protected:
		void mostrarCliente(Cliente cliente);*/
		
private:
    ArchivoClientes _archivo; //recibe un archivo de clientes para trabajar en él.
};
