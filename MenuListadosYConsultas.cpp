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
#include "ManagerListadosYConsultas.h"

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
            listadoClientes();
        }
        break;
        case 2:
        {
           listadoProductos();
        }
        break;
        case 3:
        {
            listadoVendedores();
        }
        break;
        case 4:
        {
            MenuVentasPorFecha();
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





