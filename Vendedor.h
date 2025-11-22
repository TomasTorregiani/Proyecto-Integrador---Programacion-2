#pragma once
#include <iostream>
#include <string>


class Vendedor{
public:
    //Constructores
    Vendedor();
    Vendedor(std::string nombre,
            std::string apellido, int numeroTelefono,
            std::string email, std::string direccion); //Creo que directamente sacaria este constructor y dejaria uno vacio

    void mostrarVendedor();
    void modificarVendedor();

    //Setters
    //El setter de idCliente no es necesario //Por??
    //El setter de idVendedor no es necesario //Por?? Porque se crea cuando creamos un nuevo vendedor o cliente. 

    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    int setCuilVendedor(int cuil);
    void setNumeroTelefono(int numeroTelefono);
    void setEmail(std::string email);
    void setDireccion(std::string direccion);
    int setIdVendedor(int idVendedor);
    bool setEstado(bool estado);

    //Getters
    int getIdVendedor();
    std::string getNombre();
    std::string getApellido();
    int getCuil(); 
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
    int _cuil;
    int _numeroTelefono;
    char _email[20];
    char _direccion[20];
    bool _activo;
};
