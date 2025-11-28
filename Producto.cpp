#include <iostream>
#include <cstring>
#include "Producto.h"
#include "FuncionesGlobales.h"

using namespace std;

Producto::Producto(){
    _idProducto = 0;
    strcpy(_descripcion, "");
    strcpy(_marca, "");
    strcpy(_tipoProducto, "");
    _cantidadDisponible = 0;
    _precio = 0;
    _activo = true;
}

Producto::Producto(string descripcion,
             string marca, string tipoProducto,
             int cantidadDisponible, float precio){
                    _idProducto = contarRegistros("productos.dat", sizeof(Producto))+1;

                    strcpy(_descripcion, descripcion.c_str());
                    strcpy(_marca, marca.c_str());
                    strcpy(_tipoProducto, tipoProducto.c_str());

                    _cantidadDisponible = cantidadDisponible;
                    _precio = precio;
                    _activo = true;
}

void Producto::mostrarProducto(){
    cout << "=== DATOS DEL PRODUCTO ===" << endl;
    cout << "ID Producto: " << _idProducto << endl;
    cout << "Descripcion: " << _descripcion << endl;
    cout << "Marca: " << _marca << endl;
    cout << "Tipo de producto: " << _tipoProducto << endl;
    cout << "Cantidad Disponible: " << _cantidadDisponible << endl;
    cout << "Precio: " << _precio << endl;
    cout << "Estado: " << _activo << endl;
}
void Producto::setMarca(string marca){
    strncpy(_marca, marca.c_str(), sizeof(_marca) - 1);
    _marca[49] = '\0';
}
void Producto::setEstado(bool value){
    _activo = value;
}
void Producto::eliminarProducto(){
    _activo = false;
}
void Producto::setIdProducto(int idProducto){
    _idProducto = idProducto;
}
void Producto::setDescripcion(string descripcion){
     strncpy(_descripcion, descripcion.c_str(), sizeof(_descripcion) - 1);
    _descripcion[49] = '\0';
}
void Producto::setTipoProducto(string tipoProducto){
     strncpy(_tipoProducto, tipoProducto.c_str(), sizeof(_tipoProducto) - 1);
    _tipoProducto[49] = '\0';
}
void Producto::setCantidadDisponible(int cantidadDisponible){
    _cantidadDisponible = cantidadDisponible;
}
void Producto::setPrecio(float precio){
    _precio = precio;
}
float Producto::getPrecio(){
    return _precio;
}
int Producto::getIdProducto(){
    return _idProducto;
}
int Producto::getCantidadDisponible(){
    return _cantidadDisponible;
}
string Producto::getDescripcion(){
    return _descripcion;
}
