#pragma once
#include <iostream>

class Cliente{
public:
    //Constructores
    Cliente();
    Cliente(int idCliente, std::string nombre,
            std::string apellido, int cuil,
            int tipoCliente, int numeroTelefono,
            std::string email, std::string direccion);

    //Setters
    //El setter de idCliente no es necesario
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    //El setter de cuil no es necesario
    void setTipoCliente(int tipoCliente);
    void setNumeroTelefono(int numeroTelefono);
    void setEmail(std::string email);
    void setDireccion(std::string direccion);

    //Getters
    int getIdCliente();
    std::string getNombre();
    std::string getApellido();
    int getCuil();
    int getTipoCliente();
    std::string getEmail();
    std::string getDireccion();

protected:

private:
    int _idCliente;
    char _nombre[50];
    char _apellido[50];
    int _cuil;
    int _tipoCliente;
    int _numeroTelefono;
    char _email[20];
    char _direccion[20];
};
