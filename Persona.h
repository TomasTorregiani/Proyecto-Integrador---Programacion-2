#pragma once
#include <string>

class Persona
{

public:
    Persona();
    Persona(std::string nombre, std::string apellido, int numeroTelefono, std::string email, std::string direccion);
    
    //setters
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setNumeroTelefono(int numeroTelefono);
    void setEmail(std::string email);
    void setDireccion(std::string direccion);  
    
    
    //getters
    std::string getNombre();
    std::string getApellido();
    int getNumeroTelefono();
    std::string getEmail();
    std::string getDireccion();
    
protected:
	
		char _nombre[50];
    char _apellido[50];
    int _numeroTelefono;
    char _email[20];
    char _direccion[20];
};
