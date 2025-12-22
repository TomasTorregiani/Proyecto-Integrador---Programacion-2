#include <iostream>
#include "TodosLosMenu.h"
#include "Vendedor.h"
#include "ArchivoVendedores.h"
#include "ManagerVendedores.h"

using namespace std;

void MenuGestionVendedores(){
    int opcion;
    while(true){
        system("cls");
        cout << "**** GESTION DE VENDEDORES ****" << endl << endl; 
        cout << "1) Nuevo Vendedor" << endl;
        cout << "2) Modificar Datos Vendedor" << endl;
        cout << "3) Buscar Vendedor por Id" << endl;
        cout << "4) Eliminar Vendedor" << endl;
        cout << "5) Activar Vendedor" << endl; 
        cout << "6) Listar todos los vendedores activos" << endl;
        cout << "0) Volver al menu principal" << endl;
        cout << endl;
        cout << "Elige una opcion: " << endl;
        cin >> opcion;
        system("cls");
        switch(opcion){
            case 1: {
                cout << "**** NUEVO VENDEDOR ****" << endl << endl; 
                ManagerVendedores gestorVendedor;
                gestorVendedor.crearVendedor();
            }
            break;
            case 2:{
                cout << "**** MODIFICAR DATOS DEL VENDEDOR ****" << endl << endl; 
                ManagerVendedores gestorVendedor;
                gestorVendedor.modificarVendedor();
            }
            break;
            case 3: {
                cout << "**** BUSCAR VENDEDOR POR ID ****" << endl << endl; 
                ManagerVendedores gestorVendedor;
                gestorVendedor.obtenerVendedorPorId();
            }
            break;
            case 4: {
                cout << "**** ELIMINAR VENDEDOR ****" << endl << endl; 
                ManagerVendedores gestorVendedor;
                gestorVendedor.eliminarVendedor();
            }
            break;
            case 5: {
								ManagerVendedores gestorVendedor;
								gestorVendedor.activarVendedor(); 
            }
            break;
            case 6: {
                cout << "**** LISTAR TODOS LOS VENDEDORES ****" << endl << endl; 
                ManagerVendedores gestorVendedor;
                gestorVendedor.listarVendedores();
            }
            break;
            case 0: cout << "Volviendo al menu principal..." << endl;
            return;
            default: cout << "Ingrese un valor valido" << endl;
            break;
        }
        system("pause");
    }
}
