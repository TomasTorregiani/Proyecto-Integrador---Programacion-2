#pragma once
#include "ArchivoClientes.h"
#include "Cliente.h"
class ArchivoClientes;

class ManagerClientes
{

public:
		ManagerClientes();
    void nuevoCliente();
    void mostrarCliente(int idCliente);
    void eliminarCliente(int idCliente);
    void modificarCliente();
		~ManagerClientes();
/*protected:
		void mostrarCliente(Cliente cliente);*/
		
private:
    ArchivoClientes* _archivo; //recibe un archivo de clientes para trabajar en él.
};
