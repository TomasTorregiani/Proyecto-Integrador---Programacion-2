#pragma once
#include <string>

class Cliente{
public:
    //Constructores
    Cliente();
    Cliente(int idCliente, std::string nombre,std::string apellido, int cuil, int numeroTelefono,std::string email, std::string direccion, bool estado);
    
    int setIdCliente();
    void cargarCliente();
    //Setters
    //El setter de idCliente no es necesario??
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setCuil(int numeroCuil);
    void setNumeroTelefono(int numeroTelefono);
    void setEmail(std::string email);
    void setDireccion(std::string direccion);
    void setEstado(bool estado);

    //Getters
    int getIdCliente();
    std::string getNombre();
    std::string getApellido();
    int getCuil();
    int getNumeroTelefono();
    std::string getEmail();
    std::string getDireccion();
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
    bool _estado;
};
