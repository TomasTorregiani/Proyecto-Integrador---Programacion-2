#include <iostream>
#include <cstring>
#include "ArchivoProductos.h"
#include "FuncionesGlobales.h"
#include "Producto.h"

using namespace std;

ArchivoProductos::ArchivoProductos(const char* n){
    strcpy(_nombre, n);
    _tamanioRegistro = sizeof(Producto);
}

Producto ArchivoProductos::buscarProductoPorId(int idProducto){
    FILE* p = nullptr;
    p = fopen(_nombre, "rb");

    if(p == nullptr){
        cout << "El archivo no se abrio correctamente" << endl;
        return Producto();
    }

    fseek(p, 0, SEEK_SET);
    int cantidadRegistros = contarRegistros("productos.dat", _tamanioRegistro);

    Producto registro;
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&registro, _tamanioRegistro, 1, p);
        if(registro.getIdProducto() == idProducto){
            cout << "Registro encontrado" << endl;
            fclose(p);
            return registro;
        }
    }
    cout << "Registro no encontrado" << endl;
    return Producto();
}
















