#include <iostream>
#include "TodosLosMenu.h"
#include "ArchivoProductos.h"

using namespace std;

void MenuGestionProductos(){
    int opcion;
    while(true){
        system("cls");
        cout << "**** MENU PRODUCTOS ****" << endl;
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
            break;
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
            break;
            case 3: {
                cout << "**** ELIMINAR PRODUCTO****" << endl;
                int idProducto;
                cout << "Ingrese id producto a eliminar: " << endl;
                cin >> idProducto;

                ArchivoProductos archivoProducto("productos.dat");
                Producto productoAEliminar = archivoProducto.buscarProductoPorId(idProducto);

                if(productoAEliminar.getIdProducto() != 0){
                    cout << "Registro encontrado" << endl;
                    int posicionProductoAEliminar = archivoProducto.buscarPosicionPorId(idProducto);
                    productoAEliminar.eliminarProducto();
                    int eliminoProducto = archivoProducto.agregarProductoModificado(productoAEliminar, posicionProductoAEliminar);
                    if(eliminoProducto == 1){
                        cout << "Registro eliminado correctamente" << endl;
                    }else{
                        cout << "Error al eliminar el registro" << endl;
                    }
                }else{
                    cout << "Registro no encontrado" << endl;
                }
            }
            break;
            case 4:{
                cout << "**** VER STOCK PRODUCTO ****" << endl;
                int idProducto;
                cout << "Ingrese id del producto: " << endl;
                cin >> idProducto;

                ArchivoProductos archivoProducto("productos.dat");
                Producto producto = archivoProducto.buscarProductoPorId(idProducto);
                if(producto.getIdProducto() != 0){
                    cout << "Producto encontrado correctamente" << endl;
                    cout << "Stock del producto " << producto.getDescripcion() <<": " << producto.getCantidadDisponible() << endl;
                }else{
                    cout << "Error al encontrar el producto" << endl;
                }
            }
            break;
            case 0:
                cout << "Volviendo al menu principal" << endl;
                return;
            default: cout << "Ingrese un valor valido" << endl;
            break;
        }
        system("pause");
    }
}
