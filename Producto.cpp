#include <iostream>
#include <cstring>
#include <string>
#include "Producto.h"
#include "FuncionesGlobales.h"
#include "ArchivoProductos.h"

using namespace std;

Producto::Producto(){
    _idProducto = 1; //Mejorar el id para que sea automatico y autoincrementable
    strcpy(_descripcion, "");
    strcpy(_descripcion, "");
    strcpy(_tipoProducto, "");
    _cantidadDisponible = 0;
    _precio = 0;
    _activo = true;
}

Producto::Producto(int idProducto, string descripcion, string marca, string tipoProducto,
int cantidadDisponible, float precio){

_idProducto = idProducto; //Mejorar el id para que sea automatico y autoincrementable
strcpy(_descripcion, descripcion.c_str());
strcpy(_marca, marca.c_str());
strcpy(_tipoProducto, tipoProducto.c_str());
_cantidadDisponible = cantidadDisponible;
_precio = precio;
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

/*Producto *ArchivoProductos::obtenerProductos(int cantidadProductos){ **** ESTO YA ESTA EN ARCHIVOPRODUCTOS ****
    FILE *p = nullptr;
    p = fopen(_nombre, "rb");
    if(p == nullptr){
        return nullptr;
    }

    Producto *arrayProductos;
    arrayProductos = new Producto[cantidadProductos]();
    Producto registroProducto;

    for(int i = 0; i < cantidadProductos; i++){
        fread(&registroProducto, _tamanioRegistro, 1, p);
        arrayProductos[i] = registroProducto;
    }
    fclose(p);
    return arrayProductos;
}*/

void Producto::setDescripcion(string descripcion){
		strncpy(_descripcion, descripcion.c_str(),99); //busca a descripcion en la memoria heap y le asigna un "largo" de hasta 99;
		_descripcion[99] = '\0'; //valida que no se puedan ingresar mas de 99 caracteres, xq mi char _decripcion es de [100];
}

int Producto::setIdProducto(int idProducto){
		_idProducto = idProducto; 
}

void Producto::setMarca(string marca){
		strncpy(_marca, marca.c_str(),49);
		_marca[49] = '\0';
}

void Producto::setTipoProducto(string tipoProducto){
	  strncpy(_tipoProducto, tipoProducto.c_str(), 49);
	  _tipoProducto[49] = '\0';
}

void Producto::setCantidadDisponible(int cantidadDisponible){
		_cantidadDisponible = cantidadDisponible; 
}

void Producto::setPrecio(float precio){
		_precio = precio; 
}

bool Producto::setEstado(bool estado){
		_activo = estado; 
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

void Producto::eliminarProducto(){
	_activo = false;
}
string Producto::getDescripcion(){
    return _descripcion;
}

bool Producto::getEstado(){
	return _activo; 
}
