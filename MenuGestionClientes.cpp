#include <iostream>
#include "TodosLosMenu.h"
#include "Cliente.h"
#include "ArchivoClientes.h"

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
        cout << "0) Volver al menu principal" << endl;
        cout << endl;
        cout << "Elige una opcion: " << endl;
        cin >> opcion;

        system("cls");
        switch(opcion){
            case 1: {
                Cliente nuevoCliente;
                nuevoCliente.cargarCliente();

                ArchivoClientes archivoNuevoCLiente("clientes.dat");
                int agregado = archivoNuevoCLiente.agregarCliente(nuevoCliente);

                if(agregado == 1){
                    cout << "Cliente agregado correctamente" << endl;
                }else{
                    cout << "Error al agregar cliente" << endl;
                }
            }
            break;
            case 2: {
                int idClienteAModificar;
                cout << "Ingrese el id del cliente que quiere modificar: " << endl;
                cin >> idClienteAModificar;

                ArchivoClientes clienteAModificar("clientes.dat");
                Cliente registro = clienteAModificar.buscarClientePorId(idClienteAModificar);
                int posicion = clienteAModificar.obtenerPosicionCliente(idClienteAModificar);
                if(posicion == -1){
                    cout << "Error al obtener la posicion del archivo" << endl;
                }else {
                    if(registro.getIdCliente() != 0){
                        registro.modificarCliente();
                        bool datosModificados = clienteAModificar.modificarDatosCliente(registro, posicion);
                        if(datosModificados){
                            cout << "Se modificaron los datos correctamente" << endl;
                        }else{
                            cout << "Hubo un error al actualizar los datos" << endl;
                        }
                    }
                }
            }
            break;
            case 3:{
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

                    bool modificarCliente = archivoC.modificarDatosCliente(clienteAEliminar, posicionClienteAEliminar);

                    if(modificarCliente){
                        cout << "Cliente eliminado con exito" << endl;
                    } else {
                        cout << "Error al eliminar el cliente" << endl;
                    }
                }
            }
            break;
            case 0:
                cout << "Volver al menu principal" << endl;
            return;
            default: cout << "Ingrese un valor valido" << endl;
            break;
        }
        system("pause");
    }

}
