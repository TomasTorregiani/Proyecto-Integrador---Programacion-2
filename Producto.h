#pragma once

class Producto{
public:
    //Constructores
    Producto();
    Producto(int idProducto, std::string descripcion,
             std::string marca, std::string tipoProducto,
             int cantidadDisponible, float precio);

    //Setters
    //Setter de idProducto no es necesario
    void setDescripcion(std::string descripcion);
    //Setter de idMarca no es necesario;
    void setTipoProducto(std::string tipoProducto);
    void setCantidadDisponible(int cantidadDisponible);
    void setPrecio(float precio);

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
    char _descripcion[100];
    char _marca[50];
    char _tipoProducto[50];
    int _cantidadDisponible;
    float _precio;
};
