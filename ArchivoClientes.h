#pragma once
#include <cstring>
#include <string>
#include "Cliente.h"

class ArchivoClientes{

public:
	
    ArchivoClientes(const char* nombreArchivo = "clientes.dat");
    bool guardarCliente(Cliente registro); //ok. siempre guarda al final.
    Cliente buscarClientePorId(int idCliente);
    bool eliminarCliente(int idCliente); //TODO
    bool modificarDatosCliente(Cliente registro, int posicion);
    
    int getTamanoRegistro();
    int getCantidadRegistros();
    
    void listarClientes();
    
		int obtenerPosicionCliente(int idCliente);
    
private:
    char _nombreArchivo[50]; //se asigna cuando llamo al constructor?
    int _tamanioRegistro;
};


