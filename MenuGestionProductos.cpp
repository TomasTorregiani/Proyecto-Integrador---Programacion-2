#include <iostream>
#include "TodosLosMenu.h"
#include "ArchivoProductos.h"
#include "ManagerProductos.h"

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
							  ManagerProductos gestorProductos;
                gestorProductos.nuevoProducto();
            }
            case 2: {
                ManagerProductos gestorProductos; 
                gestorProductos.modificarProducto();
            }
            case 3: {
								ManagerProductos gestorProductos; 
								gestorProductos.eliminarProducto();
            }
        }
    }



}
