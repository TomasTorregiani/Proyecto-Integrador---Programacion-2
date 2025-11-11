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
            int idCliente;
            cout << "Ingresar id de cliente: " << endl;
            cin >> idCliente;

            ArchivoClientes archivo("clientes.dat");
            Cliente registro = archivo.buscarClientePorId(idCliente);
            if(registro.getIdCliente() == 0)
            {
                cout << "No se encontro ningun cliente con ese id" << endl;
            }
            else
            {
							registro.mostrarCliente();
            }
        }
        break;
        case 4:
        {
            cout << "**** ELIMINAR CLIENTE ****" << endl;
            int idCliente;
            cout << "Ingrese id cliente a eliminar" << endl;
            cin >> idCliente;

            ArchivoClientes archivoC("clientes.dat");
            int posicionClienteAEliminar = archivoC.obtenerPosicionCliente(idCliente);

            if(posicionClienteAEliminar == -1)
            {
                cout << "Cliente no encontrado" << endl;
            }
            else
            {
                Cliente clienteAEliminar = archivoC.buscarClientePorId(idCliente);
                clienteAEliminar.eliminarCliente();

                bool modificarCliente = archivoC.modificarDatosCliente(clienteAEliminar, posicionClienteAEliminar);

                if(modificarCliente)
                {
                    cout << "Cliente eliminado con exito" << endl;
                }
                else
                {
                    cout << "Error al eliminar el cliente" << endl;
                }
            }
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
