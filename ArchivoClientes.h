#pragma once
#include <cstring>
#include <string>
#include "Cliente.h"

class ArchivoClientes{

public:
	
    ArchivoClientes(const char* nombreArchivo = "clientes.dat");
    bool guardarCliente(Cliente registro); //ok. siempre guarda al final.
    std::string buscarClientePorId(int idCliente); //INPROCESS
    bool eliminarCliente(int idCliente); //TODO
    bool modificarDatosCliente(Cliente registro, int posicion); //TODO
    
    int getTamanoRegistro();
    int getCantidadRegistros();
    
    void listarClientes();
    
		int obtenerPosicionCliente(int idCliente);
    
private:
    const char* _nombreArchivo; //se asigna cuando llamo al constructor?
    int _tamanioRegistro;
};


