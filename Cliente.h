#pragma once
#include <iostream>
#include <cstring>
#include "ArchivoClientes.h"

class Cliente{
public:
    //Constructores
    Cliente();
    Cliente(int idCliente, string nombre,string apellido, int cuil, int numeroTelefono,
						string email, string direccion, bool activo);
    
    //Setters
    //El setter de idCliente no es necesario
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setCuil(int numeroCuil);
    void setNumeroTelefono(int numeroTelefono);
    void setEmail(string email);
    void setDireccion(string direccion);
    void setEstado(bool estado);

    //Getters
    int getIdCliente();
    string getNombre();
    string getApellido();
    int getCuil();
    string getEmail();
    string getDireccion();
		bool getEstado();

    

protected:

private:
    int _idCliente;
    char _nombre[50];
    char _apellido[50];
    int _cuil;
    int _numeroTelefono;
    char _email[50];
    char _direccion[50];
    bool _activo;
};
