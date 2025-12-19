#include <iostream>
#include <cstring>
#include "ArchivoProductos.h"
#include "FuncionesGlobales.h"
#include "Producto.h"

using namespace std;

ArchivoProductos::ArchivoProductos(const char* n)
{
    strcpy(_nombre, n);
    _tamanioRegistro = sizeof(Producto);
}

int ArchivoProductos::agregarNuevoProducto(Producto nuevoProducto)
{
    FILE* p = nullptr;
    p = fopen(_nombre, "ab");
    if(p == nullptr)
    {
        cout << "Problemas al abrir el archivo" << endl;
        return -1;
    }

    int escribrio = fwrite(&nuevoProducto, _tamanioRegistro, 1, p);
    if(escribrio == 1)
    {
        fclose(p);
        return 1;
    }
    else
    {
        fclose(p);
        return 0;
    }
}

Producto ArchivoProductos::buscarProductoPorId(int idProducto)
{

    if(idProducto <= 0)
    {
				cout << "ERROR: El ID ingresado es invalido" << endl; 
        return Producto();
    }

    FILE* p = nullptr;
    p = fopen(_nombre, "rb");

    if(p == nullptr)
    {
        cout << "ERROR: No se pudo abrir 'productos.dat'. " << endl;
        cout << "Asegurese de que el archivo existe y tiene productos cargados." << endl;
        return Producto();
    }

    fseek(p, 0, SEEK_SET);
    int cantidadRegistros = contarRegistros("productos.dat", _tamanioRegistro);

    Producto registro;
    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&registro, _tamanioRegistro, 1, p);

        if(registro.getIdProducto() == idProducto)
        {
            fclose(p);
            return registro;
        }
    }
    fclose(p);
    return Producto();
}


int ArchivoProductos::buscarPosicionPorId(int idProducto)  //retorna la posición donde se encontró el producto;
{

    if(idProducto<=0)
    {
        return -1;
    }

    FILE* p = nullptr;
    p = fopen(_nombre, "rb");

    if(p == nullptr)
    {
        cout << "No se abrio correctamente el archivo" << endl;
        return -1;
    }

    fseek(p, 0, SEEK_SET); //solo posiciona el buscador al principio del registro.

    Producto registroProducto;

    int cantidadDeRegistros = contarRegistros(_nombre, _tamanioRegistro);
    for(int i = 0; i < cantidadDeRegistros; i++)
    {

        if(fread(&registroProducto, _tamanioRegistro, 1, p)!= 1)
        {
            fclose(p);
            return -1;
        }

        if(registroProducto.getIdProducto() == idProducto)
        {
            fclose(p);
            return i; //retorna la posición en la que encontró el registro. Sino, devuelve -1;
        }

    }
    fclose(p);
    return -1;
}

int ArchivoProductos::agregarProductoModificado(Producto productoModificado, int posicionProdModificado)
{
    FILE* p = nullptr;
    p = fopen(_nombre, "rb+");
    if(p == nullptr)
    {
        cout << "Error al abrir el archivo" << endl;
        return 0;
    }

    fseek(p, (posicionProdModificado * _tamanioRegistro), SEEK_SET);
    int cantidadRegistros = contarRegistros(_nombre, _tamanioRegistro);

    int escribio = fwrite(&productoModificado, _tamanioRegistro, 1, p);
    if(escribio == 1)
    {
        fclose(p);
        return 1;
    }
    fclose(p);
    return 0;
}

Producto *ArchivoProductos::obtenerProductos(int cantidadProductos)
{
    FILE *p = nullptr;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        return nullptr;
    }

    Producto *arrayProductos;
    arrayProductos = new Producto[cantidadProductos]();
    Producto registroProducto;

    for(int i = 0; i < cantidadProductos; i++)
    {
        fread(&registroProducto, _tamanioRegistro, 1, p);
        arrayProductos[i] = registroProducto;
    }
    fclose(p);
    return arrayProductos;
}

















