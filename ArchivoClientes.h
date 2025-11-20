#pragma once
#include <cstring>
#include <string>
#include "Cliente.h"

class ArchivoClientes{

public:
	
    ArchivoClientes(const char* nombreArchivo = "clientes.dat");
    bool guardarCliente(Cliente registro); //ok. siempre guarda al final.
    Cliente buscarClientePorId(int idCliente);
    int agregarCliente(Cliente registro);
    
		Cliente* obtenerClientes(int cantidadClientes);
    bool eliminarCliente(Cliente registro);
    bool modificarDatosCliente(Cliente registro, int posicion);
    
    int getTamanoRegistro();
    int getCantidadRegistros();
    
    void listarClientes();
    
		int obtenerPosicionCliente(int idCliente);
    
private:
    char _nombre[50]; //se asigna cuando llamo al constructor
    int _tamanioRegistro;
};


