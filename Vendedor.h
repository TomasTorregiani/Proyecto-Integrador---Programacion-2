#pragma once
#include <iostream>


class Vendedor{
public:
    //Constructores
    Vendedor();
    Vendedor(int idVendedor, std::string nombre,
            std::string apellido, int numeroTelefono,
            std::string email, std::string direccion);

    void cargarVendedor();
    void mostrarVendedor();
    void modificarVendedor();

    //Setters
    //El setter de idCliente no es necesario //Por??
    //El setter de idVendedor no es necesario //Por??

    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setNumeroTelefono(int numeroTelefono);
    void setEmail(std::string email);
    void setDireccion(std::string direccion);

    //Getters
    int getIdVendedor();
    std::string getNombre();
    std::string getApellido();
    int getNumeroTelefono();
    std::string getEmail();
    std::string getDireccion();
    void eliminarVendedor();

protected:

private:
    int _idVendedor;
    char _nombre[50];
    char _apellido[50];
    int _numeroTelefono;
    char _email[20];
    char _direccion[20];
    bool _activo;
};
