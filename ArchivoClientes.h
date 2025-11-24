#pragma once
#include <cstring>
#include "Cliente.h"

class ArchivoClientes{

private:
    char _nombre[30];
    int _tamanioRegistro;

public:
    ArchivoClientes(const char* n);
    int agregarCliente(Cliente registro);
    int modificarDatosCliente(Cliente registro, int posicion);
    Cliente buscarClientePorId(int idCliente);
    int obtenerPosicionCliente(int idCliente);
    //int eliminarCliente(int idCliente);//Estee no va, utilizo durectanete modificarDatosCliente;
    void listarClientes();//ver donde se usa este metodo. No es correcto que el archivo liste los clientes
    Cliente* obtenerClientes(int cantidadClientes);
};


