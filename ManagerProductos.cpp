#include <iostream>
#include <string>
#include "ManagerProductos.h"
#include "ArchivoProductos.h"

using namespace std;

ManagerProductos::ManagerProductos(){
	_archivo = new ArchivoProductos(); 
}

void ManagerProductos::nuevoProducto()
{

    cout << "**** NUEVO PRODUCTO ****" << endl;

    Producto nuevoProducto;
    int id, cantidad;
    string descripcion, marca, tipo;
    float precio;
    
    cout << "Ingrese la descripcion: " << endl;
    cin.ignore();
    getline(cin, descripcion);

    //validar

    nuevoProducto.setDescripcion(descripcion);

    cout << "Ingrese la marca: " << endl;
    getline(cin, marca);

    //validar

    nuevoProducto.setMarca(marca);

    cout << "Ingrese el tipo de producto: " << endl;
    getline(cin, tipo);
    
    //validar
    
    nuevoProducto.setTipoProducto(tipo);

    cout << "Ingrese la cantidad: " << endl;
    cin >> cantidad; 
    
    //validar 
    
    nuevoProducto.setCantidadDisponible(cantidad);

    cout << "Ingrese el precio final: " << endl;
    cin >> precio;
    
    //validar
    
    nuevoProducto.setPrecio(precio);
    
    nuevoProducto.setEstado(true);
        
        
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

	if(posicionProductoAModificar != -1){
		cout << "Producto Encontrado" << endl;
		Producto productoAModificar = archivoProd.buscarProductoPorId(idProductoAModificar);
		productoAModificar.modificarProducto();
		int agregoProducto = archivoProd.agregarProductoModificado(productoAModificar, 				posicionProductoAModificar);
		if(agregoProducto == 1){
				cout << "Producto agregado correctamente" << endl;
		}else {
				cout << "No se pudo agregar el producto" << endl;
		}
	}
}

void ManagerProductos::eliminarProducto(){
	
	cout << "**** ELIMINAR PRODUCTO ****" << endl;
	
	int idProductoAEliminar;
	cout << "Ingrese id del producto a eliminar: " << endl;
	cin >> idProductoAEliminar;
	
	ArchivoProductos archivoProd("productos.dat");
	int posicionProductoAEliminar = archivoProd.buscarPosicionPorId(idProductoAEliminar);

	if(posicionProductoAEliminar != -1){
		cout << "Producto Encontrado" << endl;
		Producto productoAEliminar = archivoProd.buscarProductoPorId(idProductoAEliminar);
		productoAEliminar.eliminarProducto();
		int agregoProducto = archivoProd.agregarProductoModificado(productoAEliminar, 				posicionProductoAEliminar);
		if(agregoProducto == 1){
				cout << "Producto eliminado correctamente" << endl;
		}else {
				cout << "No se pudo eliminar el producto" << endl;
		}
	}
	
	
	
}

void ManagerProductos::listarProductos()
{
 //TODO//
}

ManagerProductos::~ManagerProductos(){
	if(_archivo != nullptr){
		delete _archivo; 
		_archivo = nullptr;
	}
}
