#include <iostream>
#include <string>
#include "ManagerProductos.h"
#include "FuncionesGlobales.h"
#include "ArchivoProductos.h"

using namespace std;

ManagerProductos::ManagerProductos():_archivo("productos.dat"){
	
}

void ManagerProductos::nuevoProducto()
{
    Producto nuevoProducto;
    
    int idProducto, cantidad;
    string descripcion, marca, tipo;
    float precio;

    cout << "Ingrese la descripcion: " << endl;
    cin.ignore();
    getline(cin, descripcion);

    while(descripcion == "")
    {
        cout << "Este campo no puede estar vacio. Ingrese la descripcion del producto: " << endl;
        getline(cin, descripcion);
    }

    nuevoProducto.setDescripcion(descripcion);

    cout << "Ingrese la marca: " << endl;
    getline(cin, marca);

    while(marca == "")
    {
        cout << "Este campo no puede estar vacio. Ingrese la marca del producto: " << endl;
        getline(cin, marca);
    }

    nuevoProducto.setMarca(marca);

    cout << "Ingrese el tipo de producto: " << endl;
    getline(cin, tipo);

    while(tipo == "")
    {
        cout << "Este campo no puede estar vacio. Ingrese el tipo de producto: " << endl;
        getline(cin, tipo);
    }

    nuevoProducto.setTipoProducto(tipo);

    cout << "Ingrese la cantidad: " << endl;
    
    while (!(cin >> cantidad) || cantidad < 0 || cin.peek() == '.') //si cin no guarda correctamente un int o si guarda pero el int es menor a 0.
    {
        cout << "Error: Ingrese un numero entero valido (no decimal): " << endl;
        cin.clear();						//limpia el error de cin después de que falló al leer, para que cin pueda leer de nuevo.
        cin.ignore(10000, '\n');	//Borra lo que guardó el buffer de entrada hasta 10000 caracteres (o hasta encontrar un salto de línea \n)
    }
    cin.ignore(10000, '\n');

    nuevoProducto.setCantidadDisponible(cantidad);

    cout << "Ingrese el precio final: " << endl;

    while(!(cin >> precio) || precio < 0)
    {
        cout << "Error: ingrese un precio final valido: " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }

    nuevoProducto.setPrecio(precio);

    nuevoProducto.setEstado(true);
    
    idProducto = contarRegistros("productos.dat", sizeof(Producto)) + 1;
    
    nuevoProducto.setIdProducto(idProducto);


    //***** fin de los ingresos *****//


    ArchivoProductos archivoProductos("productos.dat");
    int agregoArchivo = archivoProductos.agregarNuevoProducto(nuevoProducto);
    if(agregoArchivo == 1)
    {
        cout << "Archivo agregado correctamente" << endl;
    }
    else
    {
        cout << "No se agrego el archivo" << endl;
    }
}

void ManagerProductos::modificarProducto()
{
    cout << "**** MODIFICAR PRODUCTO ****" << endl;

    int idProductoAModificar;
    cout << "Ingrese id del producto a modificar: " << endl;
    cin >> idProductoAModificar;

    ArchivoProductos archivoProd("productos.dat");
    int posicionProductoAModificar = archivoProd.buscarPosicionPorId(idProductoAModificar);

    if(posicionProductoAModificar != -1)
    {
        cout << "Producto Encontrado" << endl;
        Producto productoAModificar = archivoProd.buscarProductoPorId(idProductoAModificar);
        productoAModificar.modificarProducto();
        int agregoProducto = archivoProd.agregarProductoModificado(productoAModificar, 				posicionProductoAModificar);
        if(agregoProducto == 1)
        {
            cout << "Producto agregado correctamente" << endl;
        }
        else
        {
            cout << "No se pudo agregar el producto" << endl;
        }
    }
}

void ManagerProductos::eliminarProducto()
{

    cout << "**** ELIMINAR PRODUCTO ****" << endl;

    int idProductoAEliminar;
    cout << "Ingrese id del producto a eliminar: " << endl;
    cin >> idProductoAEliminar;

    ArchivoProductos archivoProd("productos.dat");
    int posicionProductoAEliminar = archivoProd.buscarPosicionPorId(idProductoAEliminar);

    if(posicionProductoAEliminar != -1)
    {
        cout << "Producto Encontrado" << endl;
        Producto productoAEliminar = archivoProd.buscarProductoPorId(idProductoAEliminar);
        productoAEliminar.eliminarProducto();
        int agregoProducto = archivoProd.agregarProductoModificado(productoAEliminar, 				posicionProductoAEliminar);
        if(agregoProducto == 1)
        {
            cout << "Producto eliminado correctamente" << endl;
        }
        else
        {
            cout << "No se pudo eliminar el producto" << endl;
        }
    }



}

void ManagerProductos::listarProductos()
{
//TODO//
}
