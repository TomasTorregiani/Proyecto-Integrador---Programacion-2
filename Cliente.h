#pragma once
#include <iostream>

class Cliente{
public:
    //Constructores
    Cliente();
    Cliente(std::string nombre,
            std::string apellido, int cuil, int numeroTelefono,
            std::string email, std::string direccion);

    void mostrarCliente();
    //Setters
    void setIdCliente(int idCliente);
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setCuil(int cuil);
    void setTipoCliente(int tipoCliente);
    void setNumeroTelefono(int numeroTelefono);
    void setEmail(std::string email);
    void setDireccion(std::string direccion);
    void setActivo(bool value);

    //Getters
    int getIdCliente();
    std::string getNombre();
    std::string getApellido();
    int getCuil();
    int getTipoCliente();
    std::string getEmail();
    std::string getDireccion();
    bool getActivo();

    void eliminarCliente();
    void activarCliente();

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
