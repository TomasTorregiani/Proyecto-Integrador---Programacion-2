#include <iostream>
#include "TodosLosMenu.h"
#include "Vendedor.h"
#include "ArchivoVendedores.h"
#include "ManagerVendedores.h"

using namespace std;

void MenuGestionVendedores()
{
    int opcion;
    while(true)
    {
        system("cls");
        cout << "**** GESTION DE VENDEDORES ****" << endl;
        cout << "1) Nuevo Vendedor" << endl;
        cout << "2) Modificar Datos Vendedor" << endl;
        cout << "3) Buscar Vendedor por Id" << endl;
        cout << "4) Eliminar Vendedor" << endl;
        cout << "5) Listar todos los vendedores" << endl;
        cout << "0) Volver al menu principal" << endl;
        cout << endl;
        cout << "Elige una opcion: " << endl;
        cin >> opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
        {
            cout << "**** NUEVO VENDEDOR ****" << endl;

            ManagerVendedores gestorVendedores;
            gestorVendedores.nuevoVendedor();

        }
        break;
        case 2:
        {
            int idVendedor;
            cout << "**** MODIFICAR DATOS DEL VENDEDOR ****" << endl;
            cout << "Ingrese id del vendedor a modificar: " << endl;
            cin >> idVendedor;

            ArchivoVendedores archivoVendedor("vendedores.dat");
            int posicionVendedor = archivoVendedor.buscarPosicionDelVendedor(idVendedor);
            if(posicionVendedor != -1)
            {
                Vendedor vendedorAModificar = archivoVendedor.buscarVendedorPorId(idVendedor);
                vendedorAModificar.modificarVendedor();
                int modifico = archivoVendedor.modificarDatosVendedor(vendedorAModificar, posicionVendedor);
                if(modifico == 1)
                {
                    cout << "Se escribio correctamente" << endl;
                }
                else
                {
                    cout << "El archivo no pudo escribirse correctamente" << endl;
                }
            }
        }
        break;
        case 3:
        {
            cout << "**** BUSCAR VENDEDOR POR ID ****" << endl;
            int idVendedor;
            cout << "Ingrese id del vendedor: " << endl;
            cin >> idVendedor;

            ArchivoVendedores archivoVendedor("vendedores.dat");
            Vendedor registroVendedor = archivoVendedor.buscarVendedorPorId(idVendedor);
            if(registroVendedor.getIdVendedor() == 0)
            {
                cout << "No se encontro el vendedor" << endl;
            }
            else
            {
                cout << "Vendedor encontrado:" << endl;
                cout << "Nombre: " << registroVendedor.getNombre() << endl;
                cout << "Apellido: " << registroVendedor.getApellido() << endl;
                cout << "Estado: " << (registroVendedor.getEstado() == 1 ? "Activo" : "Inactivo") << endl;
            }
        }
        break;
        case 4:
        {
            cout << "**** ELIMINAR VENDEDOR ****" << endl;
            int idVendedor;
            cout << "Ingrese el id del vendedor: " << endl;
            cin >> idVendedor;

            ArchivoVendedores archivoVendedor("vendedores.dat");
            int posicionVendedor = archivoVendedor.buscarPosicionDelVendedor(idVendedor);
            if(posicionVendedor != -1)
            {
                cout << "Registro encontrado exitosamente" << endl;
                Vendedor vendedorAEliminar = archivoVendedor.buscarVendedorPorId(idVendedor);
                vendedorAEliminar.eliminarVendedor();

                int eliminoVendedor = archivoVendedor.modificarDatosVendedor(vendedorAEliminar, posicionVendedor);
                if(eliminoVendedor != 0)
                {
                    cout << "Vendedor eliminado correctamente" << endl;
                }
                else
                {
                    cout << "Error al eliminar el vendedor" << endl;
                }
            }
            else
            {
                cout << "No se encontro el registro" << endl;
            }
        }
        break;
        case 5:
        {
            cout << "**** LISTAR TODOS LOS VENDEDORES ****" << endl;
            
            ArchivoVendedores archivoVendedor("vendedores.dat");
						archivoVendedor.listarVendedores();
						
        }
        break;
        case 0:
            cout << "Volviendo al menu principal..." << endl;
            return;
        default:
            cout << "Ingrese un valor valido" << endl;
            break;
        }
        system("pause");
    }
}
