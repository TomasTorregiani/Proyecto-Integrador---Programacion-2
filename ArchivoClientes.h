#pragma once
#include <cstring>
#include "Cliente.h"
#include "ManagerClientes.h"

class ArchivoClientes{

public:
	
    ArchivoClientes(const char* nombreArchivo = "clientes.dat");
    bool guardarCliente(Cliente registro); //ok. siempre guarda al final.
    int buscarClientePorId(int idCliente); //INPROCESS
    bool eliminarCliente(int idCliente); //TODO
    bool modificarDatosCliente(Cliente registro, int posicion); //TODO
    
    int getTamañoRegistro();
    int getCantidadRegistros();
    
    void listarClientes();
    
		int obtenerPosicionCliente(int idCliente);
    
private:
	
    const char* _nombreArchivo; //se asigna cuando llamo al constructor?
};


