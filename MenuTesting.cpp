#include <iostream>
#include "ManagerVentas.h"
#include "TodosLosMenu.h"
#include "ArchivoClientes.h"
#include "ArchivoVendedores.h"
#include "ArchivoDetalles.h"
#include "Venta.h"
#include "Vendedor.h"
#include "ArchivoProductos.h"
#include "ManagerClientes.h"
#include "ManagerVendedores.h"
#include "FuncionesGlobales.h"
#include "Fecha.h"
#include <string>
#include <cstring>

using namespace std;

void MenuTesting()
{
    int opcion;
    while(true)
    {
        system("cls");
        cout << "**** MENU DE TESTING ****" << endl << endl;
        cout << "1) Crear Venta ingresando fecha manualmente" << endl;
        cout << "0) Salir" << endl;
        cout << "-------------------------------------" <<  endl;
        cout << "Elige una opcion: " << endl;
        cin >> opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
        {
            cout << "**** Crear venta ingresando fecha manualmente ****" << endl;
            ManagerVentas gestorVentas;
            gestorVentas.testingCrearVenta();
        }
        break;
        case 0:
            MenuPrincipal();
        default:
            cout << "Ingrese una opcion valida" << endl;
            break;
        }
        system("pause");
    }
}

