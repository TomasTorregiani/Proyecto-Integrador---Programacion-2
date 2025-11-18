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
            case 2: {
                cout << "**** MODIFICAR DATOS CLIENTE ****" << endl;
                int idClienteAModificar;
                cout << "Ingrese el id del cliente que quiere modificar: " << endl;
                cin >> idClienteAModificar;
                ManagerClientes managerCliente;
                int clienteModificado = managerCliente.modificarCliente(idClienteAModificar);

                if(clienteModificado > 0){
                    cout << "Se modificaron los datos correctamente" << endl;
                }else{
                    cout << "Hubo un error al actualizar los datos" << endl;
                    }
                }
            break;
            case 3:{
                cout << "**** BUSCAR CLIENTE POR ID ****" << endl;
                int idCliente;
                cout << "Ingresar id de cliente: " << endl;
                cin >> idCliente;

                ArchivoClientes archivo("clientes.dat");
                Cliente registro = archivo.buscarClientePorId(idCliente);
                if(registro.getIdCliente() == 0){
                    cout << "No se encontro ningun cliente con ese id" << endl;
                }else{
                    registro.mostrarCliente();
                }
            }
            break;
            case 4:{
                cout << "**** ELIMINAR CLIENTE ****" << endl;
                int idCliente;
                cout << "Ingrese id cliente a eliminar" << endl;
                cin >> idCliente;

                ArchivoClientes archivoC("clientes.dat");
                int posicionClienteAEliminar = archivoC.obtenerPosicionCliente(idCliente);

                if(posicionClienteAEliminar == -1){
                    cout << "Cliente no encontrado" << endl;
                } else {
                    Cliente clienteAEliminar = archivoC.buscarClientePorId(idCliente);
                    clienteAEliminar.eliminarCliente();

                    int modificarCliente = archivoC.modificarDatosCliente(clienteAEliminar, posicionClienteAEliminar);

                    if(modificarCliente > 0){
                        cout << "Cliente eliminado con exito" << endl;
                    } else {
                        cout << "Error al eliminar el cliente" << endl;
                    }
                }
            }
            break;
            case 5: {
                cout << "**** ACTIVAR CLIENTE ****" << endl;
                int idCliente;
                cout << "Ingrese el id del cliente a activar nuevamente" << endl;
                cin >> idCliente;

                ArchivoClientes archivoC("clientes.dat");
                int posicion = archivoC.obtenerPosicionCliente(idCliente);
                if(posicion == -1){
                    cout << "No se encontro el cliente" << endl;
                }else{
                    Cliente cliente = archivoC.buscarClientePorId(idCliente);
                    cliente.activarCliente();
                    int activoCliente = archivoC.modificarDatosCliente(cliente, posicion);
                    if(activoCliente > 0){
                        cout << "Se activo cliente correctamente" << endl;
                    }else {
                        cout << "Error al activar el cliente" << endl;
                    }
                }
            }
            break;
            case 6: {
                cout << "LISTAR LOS CLIENTES" << endl;
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
