#pragma once

class ArchivoClientes(){
private:
    char _nombre[30];
    int _tamanioRegistro;
public:
    ArchivoClientes(const char* n)
    int agregarCliente(Cliente registro);
    bool modificarDatosCliente(Cliente registro, int posicion);
    int buscarClientePorId(int idCliente);
    int contarRegistros();
    int eliminarCliente(int idCliente);
};






