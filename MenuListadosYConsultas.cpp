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
#include "FuncionesListadosYConsultas.h"

using namespace std;

void MenuListadosYConsultas()
{
    int opcion;
    while(true)
    {
        system("cls");
        cout << "**** MENU LISTADOS Y CONSULTAS ****" << endl << endl;
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
            listadoClientes();
        }
        break;
        case 2:
        {
           cout << "**** LISTADO DE PRODUCTOS ****" << endl;
           listadoProductos();
        }
        break;
        case 3:
        {
            cout << "**** LISTADO DE VENDEDORES ****" << endl;
            listadoVendedores();

        }
        break;
        case 4:
        {
        	cout << "**** LISTADO DE VENTAS(POR FECHA/MES/ANIO/DIAS)" << endl;
            MenuVentasPorFecha();

        }
        case 0:
            MenuPrincipal();
        default:
            cout << "Ingrese una opcion valida" << endl;
            break;
        }
        system("pause");
    }
}







