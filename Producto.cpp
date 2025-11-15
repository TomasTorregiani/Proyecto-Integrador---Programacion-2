#include <iostream>
#include <cstring>
#include "Producto.h"
#include "FuncionesGlobales.h"

using namespace std;

Producto::Producto(){
    _idProducto = 1; //Mejorar el id para que sea automatico y autoincrementable
    strcpy(_descripcion, "");
    strcpy(_descripcion, "");
    strcpy(_tipoProducto, "");
    _cantidadDisponible = 0;
    _precio = 0;
    _estado = true;
}

Producto::Producto(int idProducto, string descripcion,
             string marca, string tipoProducto,
             int cantidadDisponible, long long precio){

                    _idProducto = idProducto; //Mejorar el id para que sea automatico y autoincrementable
                    strcpy(_descripcion, descripcion.c_str());
                    strcpy(_marca, marca.c_str());
                    strcpy(_tipoProducto, tipoProducto.c_str());
                    _cantidadDisponible = cantidadDisponible;
                    _precio = precio;
}

void Producto::crearNuevoProducto(){
    _idProducto = contarRegistros("productos.dat", sizeof(Producto)) + 1; //Deberiamos cambiar esto. Y que el id de cada producto
    cout << "Ingrese descripcion: " << endl;                              //asi como de cada venta o lo que sea se deberia trabajar
    cin >> _descripcion;                                                  //directamente en archivos
    cout << "Ingrese marca: " << endl;
    cin >> _marca;
    cout << "Ingrese tipo de producto: " << endl;
    cin >> _tipoProducto;
    cout << "Ingrese cantidad disponible: " << endl;
    cin >> _cantidadDisponible;
    cout << "Ingrese precio: " << endl;
    cin >> _precio;
    _estado = true;
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

long Producto::getPrecio(){
    return _precio;
}
int Producto::getIdProducto(){
    return _idProducto;
}
void Producto::eliminarProducto(){
	_estado = false;
}
string Producto::getDescripcion(){
    return _descripcion;
}

bool Producto::getEstado(){
	return _estado; 
}
