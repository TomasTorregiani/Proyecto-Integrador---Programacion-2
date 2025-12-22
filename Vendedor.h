#pragma once
#include <iostream>
#include "Persona.h"


class Vendedor : public Persona{ //hereda de Persona
public:
    //Constructores
    Vendedor();
    Vendedor(int idVendedor, std::string nombre,
            std::string apellido, int numeroTelefono,
            std::string email, std::string direccion, bool activo); 
            
    void mostrarVendedor();
    void crearVendedor();
    void listarVendedores();
    void eliminarVendedor();
    void obtenerVendedorPorId();
    void modificarVendedor();
    
    //Setters
    void setIdVendedor(int idVendedor);
    void setActivo(bool value);

    //Getters
    int getIdVendedor();
    bool getActivo();

private:
    int _idVendedor;
    bool _activo;
};
