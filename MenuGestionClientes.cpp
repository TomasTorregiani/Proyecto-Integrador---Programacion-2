#include <iostream>
#include "TodosLosMenu.h"
#include "Cliente.h"
#include "ArchivoClientes.h"
#include "FuncionesGlobales.h"
#include "ManagerClientes.h"


using namespace std;

void MenuGestionClientes(){
    int opcion;
    while(true){
        system("cls");
        cout << "**** GESTION DE CLIENTES ****" << endl;
        cout << "1) Nuevo Cliente" << endl;
        cout << "2) Modificar Datos Cliente" << endl;
        cout << "3) Buscar Cliente por Id" << endl;
        cout << "4) Eliminar Cliente" << endl;
        cout << "5) Activar Cliente" << endl;
        cout << "6) Listar todos los clientes" << endl;
        cout << "0) Volver al menu principal" << endl;
        cout << endl;
        cout << "Elige una opcion: " << endl;
        cin >> opcion;

        system("cls");
        switch(opcion){
            case 1: {
                cout << "**** NUEVO CLIENTE ****" << endl;
                ManagerClientes managerCliente;
                managerCliente.crearCliente();

            }
            break;
            case 2:{
                cout << "**** MODIFICAR DATOS CLIENTE ****" << endl;
                ManagerClientes managerCliente;
                managerCliente.modificarCliente();
            }
            break;
            case 3:{
                cout << "**** BUSCAR CLIENTE POR ID ****" << endl;
                ManagerClientes managerCliente;
                managerCliente.buscarClientePorId();
            }
            break;
            case 4:{
                cout << "**** ELIMINAR CLIENTE ****" << endl;
                ManagerClientes managerCliente;
                managerCliente.eliminarCliente();
            }
            break;
            case 5: {
                cout << "**** ACTIVAR CLIENTE ****" << endl;
                ManagerClientes managerCliente;
                managerCliente.activarCliente();
            }
            break;
            case 6: {
                cout << "LISTAR LOS CLIENTES" << endl; //Listar clientes ya lo tenemos en listados
                ManagerClientes managerCliente;
                managerCliente.listarClientes();
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
