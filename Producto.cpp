#include <iostream>
#include <cstring>
#include "Producto.h"
#include "FuncionesGlobales.h"

using namespace std;

Producto::Producto(){
    _idProducto = 0;
    strcpy(_descripcion, "");
    strcpy(_descripcion, "");
    strcpy(_tipoProducto, "");
    _cantidadDisponible = 0;
    _precio = 0;
    _activo = true;
}

Producto::Producto(string descripcion,
             string marca, string tipoProducto,
             int cantidadDisponible, long long precio){
                    _idProducto = contarRegistros("productos.dat", sizeof(Producto))+1;
                    strcpy(_descripcion, descripcion.c_str());
                    strcpy(_marca, marca.c_str());
                    strcpy(_tipoProducto, tipoProducto.c_str());
                    _cantidadDisponible = cantidadDisponible;
                    _precio = precio;
                    _activo = true;
}

void Producto::crearNuevoProducto(){
    _idProducto = contarRegistros("productos.dat", sizeof(Producto)) + 1; //Deberiamos cambiar esto. Y que el id de cada producto
    cout << "Ingrese descripcion: " << endl;                              //asi como de cada venta o lo que sea se deberia trabajar
    cin >> _descripcion;                                                  //directamente en archivos o manager
    cout << "Ingrese marca: " << endl;
    cin >> _marca;
    cout << "Ingrese tipo de producto: " << endl;
    cin >> _tipoProducto;
    cout << "Ingrese cantidad disponible: " << endl;
    cin >> _cantidadDisponible;
    cout << "Ingrese precio: " << endl;
    cin >> _precio;
    _activo = true;
}

void Producto::modificarProducto(){
    cout << "Ingrese descripcion: " << endl;
    cin >> _descripcion;
    cout << "Ingrese marca: " << endl;
    cin >> _marca;
    cout << "Ingrese tipo de producto: " << endl;
    cin >> _tipoProducto;
    cout << "Ingrese cantidad disponible: " << endl;
    cin >> _cantidadDisponible;
    cout << "Ingrese precio: " << endl;
    cin >> _precio;
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
void Producto::eliminarProducto(){
    _activo = false;
}
long long Producto::getPrecio(){
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
