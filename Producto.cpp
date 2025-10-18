
#include "Producto.h"
#include <cstring>

using namespace std;

Producto::Producto(){
    _idProducto = 1; //Mejorar el id para que sea automatico y autoincrementable
    strcpy(_descripcion, "");
    strcpy(_descripcion, "");
    strcpy(_tipoProducto, "");
    _cantidadDisponible = 0;
    _precio = 0;
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

long long Producto::getPrecio(){
    return _precio;
}
