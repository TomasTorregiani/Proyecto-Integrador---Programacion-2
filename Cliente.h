#pragma once
#include <iostream>
#include "Persona.h"

class Cliente : public Persona{
public:
	
    //Constructores
    Cliente();
    Cliente(int idCliente, std::string nombre,
            std::string apellido, int cuil, int numeroTelefono,
            std::string email, std::string direccion, bool value);

    void mostrarCliente(); //esto deberia ser un metodo del managerClientes;
    
    //Setters
    void setIdCliente(int idCliente);
    void setCuil(int cuil);
    void setActivo(bool value);

    //Getters
    int getIdCliente();
    int getCuil();
    bool getActivo();

private:
    int _idCliente;
    int _cuil;
    bool _activo;
};
