#include <iostream>
#include "TodosLosMenu.h"
#include "ArchivoProductos.h"

using namespace std;

void MenuGestionProductos(){
    int opcion;
    while(true){
        system("cls");
        cout << "****";
        cout << "1) Nuevo Producto" << endl;
        cout << "2) Modificar datos producto" << endl;
        cout << "3) Eliminar producto" << endl;
        cout << "4) Ver stock producto" << endl;
        cout << "0) Volver al menu principal" << endl;
        cout << endl;
        cout << "Elige una opcion: " << endl;
        cin >> opcion;
        system("cls");
        switch(opcion){
            case 1: {
                cout << "**** NUEVO PRODUCTO ****" << endl;

                Producto nuevoProducto;
                nuevoProducto.crearNuevoProducto();

                ArchivoProductos archivoProductos("productos.dat");
                int agregoArchivo = archivoProductos.agregarNuevoProducto(nuevoProducto);
                if(agregoArchivo == 1){
                    cout << "Archivo agregado correctamente" << endl;
                }else{
                    cout << "No se agrego el archivo" << endl;
                }
            }
            case 2: {
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
                    int agregoProducto = archivoProd.agregarProductoModificado(productoAModificar, posicionProductoAModificar);
                    if(agregoProducto == 1){
                        cout << "Producto agregado correctamente" << endl;
                    }else {
                        cout << "No se pudo agregar el producto" << endl;
                    }
                }
            }
        }
    }



}
