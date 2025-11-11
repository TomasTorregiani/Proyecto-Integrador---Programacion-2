#include <iostream>
#include "TodosLosMenu.h"
#include "Cliente.h"
#include "ArchivoClientes.h"
#include "ManagerClientes.h"


using namespace std;

void MenuGestionClientes()
{
    int opcion;
    while(true)
    {
        system("cls");
        cout << "**** GESTION DE CLIENTES ****" << endl;
        cout << "1) Nuevo Cliente" << endl;
        cout << "2) Modificar Datos Cliente" << endl;
        cout << "3) Buscar Cliente por Id" << endl;
        cout << "4) Eliminar Cliente" << endl;
        cout << "5) Listar todos los clientes" << endl;
        cout << "0) Volver al menu principal" << endl;
        cout << endl;
        cout << "Elige una opcion: " << endl;
        cin >> opcion;

        system("cls");
        switch(opcion)
        {
        case 1:
        {
            ManagerClientes gestorCliente;
            gestorCliente.nuevoCliente();
        }
        break;
        case 2:
        {
            ManagerClientes gestorCliente;
            gestorCliente.modificarCliente();
        }
        break;
        case 3:
        {
						ManagerClientes gestorCliente;
						gestorCliente.mostrarCliente();
        }
        break;
        case 4:
        {
						ManagerClientes gestorCliente;
						gestorCliente.eliminarCliente();
        }
        break;
        case 5:
        {
            cout << "LISTAR LOS CLIENTES" << endl;
            ArchivoClientes archivoC("clientes.dat");
            archivoC.listarClientes();
        }
        break;
        case 0:
            cout << "Volviendo al menu principal" << endl;
            return;
        default:
            cout << "Ingrese un valor valido" << endl;
            break;
        }
        system("pause");
    }

}
