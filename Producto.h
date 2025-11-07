#pragma once
#include <iostream>

class Producto{
public:
    //Constructores
    Producto();
    Producto(int idProducto, std::string descripcion,
             std::string marca, std::string tipoProducto,
             int cantidadDisponible, long long precio);

    void crearNuevoProducto();
    void modificarProducto();
    void eliminarProducto();

    //Setters
    //Setter de idProducto no es necesario
    void setDescripcion(std::string descripcion);
    //Setter de idMarca no es necesario;
    void setTipoProducto(std::string tipoProducto);
    void setCantidadDisponible(int cantidadDisponible);
    void setPrecio(long long precio);

    //Getters
    int getIdProducto();
    std::string getDescripcion();
    std::string getMarca();
    std::string getTipoProducto();
    int getCantidadDisponible();
    long long getPrecio();

protected:

private:
    int _idProducto;
    char _descripcion[100];
    char _marca[50];
    char _tipoProducto[50];
    int _cantidadDisponible;
    long long _precio;
    bool _activo;
};
