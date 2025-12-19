#include <iostream>
#include "TodosLosMenu.h"
#include "ArchivoProductos.h"
#include "ManagerProductos.h"
#include "Producto.h"

using namespace std;

void MenuGestionProductos(){
    int opcion;
    while(true){
        system("cls");
        cout << "**** MENU PRODUCTOS ****" << endl;
        cout << "1) Nuevo Producto" << endl;
        cout << "2) Modificar datos producto" << endl;
        cout << "3) Eliminar producto" << endl;
        cout << "4) Activar producto" << endl; 
        cout << "5) Ver stock producto" << endl;
        cout << "0) Volver al menu principal" << endl;
        cout << endl;
        cout << "Elige una opcion: " << endl;
        cin >> opcion;
        system("cls");
        switch(opcion){
            case 1: {
                cout << "**** NUEVO PRODUCTO ****" << endl;
                ManagerProductos gestorProductos;
                gestorProductos.crearNuevoProducto();
            }
            break;
            case 2: {
                cout << "**** MODIFICAR PRODUCTO ****" << endl;
                ManagerProductos gestorProductos;
                gestorProductos.modificarProducto();
            }
            break;
            case 3: {
                cout << "**** ELIMINAR PRODUCTO****" << endl;
                ManagerProductos gestorProductos;
                gestorProductos.eliminarProducto();
            }
            break;
            case 4:{
								cout << "**** ACTIVAR PRODUCTO ****" << endl; 
								ManagerProductos gestorProductos;
								gestorProductos.activarProducto();
            }
            break;
            case 5:{
                cout << "**** VER STOCK PRODUCTO ****" << endl;
                ManagerProductos gestorProductos;
                gestorProductos.verStockProducto();
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
