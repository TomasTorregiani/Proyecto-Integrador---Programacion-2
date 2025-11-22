#pragma once
#include <iostream>


class Vendedor{
public:
    //Constructores
    Vendedor();
    Vendedor(std::string nombre,
            std::string apellido, int numeroTelefono,
            std::string email, std::string direccion); //Creo que directamente sacaria este constructor y dejaria uno vacio

    void crearVendedor();
    void mostrarVendedor();
    void modificarVendedor();

    //Setters
    void setIdVendedor(int idVendedor);
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setNumeroTelefono(int numeroTelefono);
    void setEmail(std::string email);
    void setDireccion(std::string direccion);
    void setActivo(bool value);

    //Getters
    int getIdVendedor();
    std::string getNombre();
    std::string getApellido();
    int getNumeroTelefono();
    std::string getEmail();
    std::string getDireccion();
    void eliminarVendedor();
    bool getEstado();

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
