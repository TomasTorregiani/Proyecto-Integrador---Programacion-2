#pragma once
#include <iostream>
#include <string>
#include <cstring>

class Producto{
public:
    //Constructores
    Producto();
    Producto(int idProducto, std::string descripcion, std::string marca, std::string tipoProducto,int cantidadDisponible, float precio);

    void modificarProducto();
    void mostrarProducto();
    void eliminarProducto();

    //Setters
    //Setter de idProducto no es necesario, se crea automaticamente.
    int setIdProducto(int idProducto);
    void setDescripcion(std::string descripcion);
    void setMarca(std::string marca);
    void setTipoProducto(std::string tipoProducto);
    void setCantidadDisponible(int cantidadDisponible);
    void setPrecio(float precio);
    bool setEstado(bool estado);

    //Getters
    int getIdProducto();
    std::string getDescripcion();
    std::string getMarca();
    std::string getTipoProducto();
    int getCantidadDisponible();
    float getPrecio();
    bool getEstado(); 

private:
    int _idProducto;
    char _descripcion[100];
    char _marca[50];
    char _tipoProducto[50];
    int _cantidadDisponible;
    float _precio;
    bool _activo;
};
