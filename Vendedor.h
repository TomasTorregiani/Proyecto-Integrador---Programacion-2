#pragma once
#include <iostream>
#include <string>

class Vendedor{
public:
    //Constructores
    Vendedor();
    Vendedor(int idVendedor, std::string nombre,
            std::string apellido, int cuilVendedor, int numeroTelefono,
            std::string email, std::string direccion, bool estado);

    void crearVendedor();
    void mostrarVendedor();
    void modificarVendedor();
		void eliminarVendedor();
		
    //Setters
    
    //El setter de idVendedor no es necesario //Por??

    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setCuilVendedor(int cuilVendedor);
    void setNumeroTelefono(int numeroTelefono);
    void setEmail(std::string email);
    void setDireccion(std::string direccion);
    bool setEstado(bool estado); 

    //Getters
    int getIdVendedor();
    std::string getNombre();
    std::string getApellido();
    int getCuilVendedor(); 
    int getNumeroTelefono();
    std::string getEmail();
    std::string getDireccion();
    bool getEstado(); 
    

protected:

private:
    int _idVendedor;
    int _cuilVendedor; 
    char _nombre[50];
    char _apellido[50];
    int _numeroTelefono;
    char _email[50];
    char _direccion[50];
    bool _estado;
};
