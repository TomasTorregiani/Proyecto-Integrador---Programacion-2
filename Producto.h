#pragma once
#include <iostream>

class Producto{
public:
    //Constructores
    Producto();
    Producto(std::string descripcion,
             std::string marca, std::string tipoProducto,
             int cantidadDisponible, float precio);

    void crearNuevoProducto();
    void modificarProducto();
    void eliminarProducto();
    void mostrarProducto();

    //Setters
    void setIdProducto(int idProducto);
    void setDescripcion(std::string descripcion);
    void setMarca(std::string marca);
    void setTipoProducto(std::string tipoProducto);
    void setCantidadDisponible(int cantidadDisponible);
    void setPrecio(float precio);
    void setEstado(bool value);

    //Getters
    int getIdProducto();
    std::string getDescripcion();
    std::string getMarca();
    std::string getTipoProducto();
    int getCantidadDisponible();
    float getPrecio();

protected:

private:
    int _idProducto;
    char _descripcion[50];
    char _marca[50];
    char _tipoProducto[50];
    int _cantidadDisponible;
    float _precio;
    bool _activo;
};
