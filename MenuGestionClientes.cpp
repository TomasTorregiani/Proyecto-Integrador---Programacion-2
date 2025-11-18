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
                int clienteAgregado = managerCliente.crearCliente();
                if(clienteAgregado == 1){
                    cout << "Cliente agregado correctamente" << endl;
                }else{
                    cout << "Error al agregar cliente" << endl;
                }
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
                int idCliente;
                cout << "Ingresar id de cliente: " << endl;
                cin >> idCliente;

                ManagerClientes managerCliente;
                Cliente clienteObtenido = managerCliente.buscarClientePorId(idCliente);

                if(clienteObtenido.getIdCliente() != 0){
                    cout << "Cliente encontrado" << endl;
                    clienteObtenido.mostrarCliente();
                }else{
                    cout << "No se encontro el cliente" << endl;
                }
            }
            break;
            case 4:{
                cout << "**** ELIMINAR CLIENTE ****" << endl;
                int idClienteAEliminar;
                cout << "Ingrese id cliente a eliminar" << endl;
                cin >> idClienteAEliminar;

                ManagerClientes managerCliente;
                int clienteEliminado = managerCliente.eliminarCliente(idClienteAEliminar);

                if(clienteEliminado != 0){
                    cout << "Cliente eliminado exitosamente" << endl;
                }else{
                    cout << "No se pudo eliminar el cliente" << endl;
                }
            }
            break;
            case 5: {
                cout << "**** ACTIVAR CLIENTE ****" << endl;
                int idClienteAActivar;
                cout << "Ingrese el id del cliente a activar nuevamente" << endl;
                cin >> idClienteAActivar;

                ManagerClientes managerCliente;
                int clienteAActivar = managerCliente.activarCliente(idClienteAActivar);
                if(clienteAActivar != 0){
                    cout << "Cliente activado correctamente" << endl;
                }else {
                    cout << "Error al activar el cliente" << endl;
                }
            }
            break;
            case 6: {
                cout << "LISTAR LOS CLIENTES" << endl; //Listar clientes ya lo tenemos en listados
                int cantidadClientes = contarRegistros("clientes.dat", sizeof(Cliente));
                ArchivoClientes archivoC("clientes.dat");
                Cliente* arrayclientes = archivoC.obtenerClientes(cantidadClientes);

                for(int i = 0; i < cantidadClientes; i++){
                    if(arrayclientes[i].getActivo() == true){
                        arrayclientes[i].mostrarCliente();
                    }
                }
                delete[] arrayclientes;
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
