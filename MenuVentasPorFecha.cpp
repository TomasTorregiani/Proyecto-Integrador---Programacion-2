#include <iostream>
#include "TodosLosMenu.h"
#include "ArchivoDetalles.h"
#include "Fecha.h"
#include "ArchivoClientes.h"
#include "Cliente.h"
#include "Vendedor.h"
#include "ArchivoVendedores.h"
#include "ArchivoVentas.h"
#include "ArchivoProductos.h"
#include "Producto.h"
#include "ManagerVendedores.h"
#include "ManagerVentas.h"
#include "ManagerListadosYConsultas.h"

using namespace std;

void MenuVentasPorFecha()
{
	  int opcion;
    while(true)
    {

        system("cls");
        cout << "*** VENTAS POR FECHA *** " << endl << endl;

        cout << "1. Ventas por anio" << endl;
        cout << "2. Ventas por mes" << endl;
        cout << "3. Ventas por fecha exacta" << endl;
        cout << "4. Ventas por intervalo de fecha" << endl;
        cout << "0. Volver al menu anterior" << endl;
        cout << endl;
        cout << "Elegi una opcion: " << endl;

        cin >> opcion;
        system("cls");

        switch(opcion)
        {
        case 1:
        {
            ventasPorAnio();
        }
        break;
        case 2:
        {
            ventasPorMes();
        }
        break;
        case 3:
        {
            ventasPorFechaExacta();
        }
        break;
        case 4:
        {
            ventasPorIntervaloDeFecha();
        }
        break;
        case 0:
            MenuListadosYConsultas();
        default:
            cout << "Ingrese un valor valido" << endl;
            break;
        }
        system("pause");
    }
}
