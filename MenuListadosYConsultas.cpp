#include <iostream>
#include "Cliente.h"
#include "ArchivoClientes.h"
#include "Producto.h"
#include "ArchivoProductos.h"
#include "Venta.h"
#include "ArchivoVentas.h"
#include "Vendedor.h"
#include "ArchivoVendedores.h"
#include "TodosLosMenu.h"
#include "FuncionesGlobales.h"

using namespace std;

void MenuListadosYConsultas()
{
    int opcion;
    while(true)
    {
        system("cls");
        cout << "**** MENU INFORMES Y REPORTES ****" << endl;
        cout << "1) Listado de clientes" << endl;
        cout << "2) Listado de productos" << endl;
        cout << "3) Listado de vendedores" << endl;
        cout << "4) Listado de ventas(Por fecha, mes, anio, dias)" << endl;
        cout << "0) Salir" << endl;
        cout << "-------------------------------------" <<  endl;
        cout << "Elige una opcion: " << endl;
        cin >> opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
        {
            cout << "**** LISTADO DE CLIENTES ****" << endl;

            int cantidadClientes = contarRegistros("clientes.dat",sizeof(Cliente));
            ArchivoClientes archivoCliente("clientes.dat");
            Cliente* arrayClientes = archivoCliente.obtenerClientes(cantidadClientes);

            for(int i = 0; i < cantidadClientes; i++)
            {
                arrayClientes[i].mostrarCliente();
            }
            delete[] arrayClientes;
        }
        break;
        case 2:
        {
            cout << "**** LISTADO DE PRODUCTOS ****" << endl;  //Este case es identico al anterior,
            ArchivoProductos archivoProducto("productos.dat"); //sin embargo lo encare de una manera
            //mucho mas rebuscada
            int cantidadProductos = contarRegistros("productos.dat", sizeof(Producto));

            Producto* productosObtenidos;
            productosObtenidos = archivoProducto.obtenerProductos(cantidadProductos);

            for(int i = 0; i < cantidadProductos; i++)
            {
                productosObtenidos[i].mostrarProducto();
            }

            delete[] productosObtenidos;
        }
        break;
        case 3:
        {
            cout << "**** LISTADO DE VENDEDORES ****" << endl;
            ArchivoVendedores archivoVendedor("vendedores.dat");

            int cantidadVendedores = contarRegistros("vendedores.dat", sizeof(Vendedor));
            Vendedor* arrayVendedores = archivoVendedor.obtenerVendedores(cantidadVendedores);
            for(int i = 0; i < cantidadVendedores; i++)
            {
                arrayVendedores[i].mostrarVendedor();
            }
            delete[] arrayVendedores;
        }
        break;
        case 4:
        {
            cout << "**** LISTADO DE VENTAS POR FECHA(MES/ANIO/DIA)" << endl;

        }
        case 0:
            cout << "Volviendo al menu principal" << endl;
            return;
        default:
            cout << "Ingrese una opcion valida" << endl;
            break;
        }
        system("pause");
    }
}
