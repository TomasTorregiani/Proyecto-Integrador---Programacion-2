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

using namespace std;

void MenuGestionFacturacion(){
    int opcion;
    while(true){
        system("cls");
        cout << "**** MENU FACTURACION ****" << endl;
        cout << "1) Nueva venta" << endl;
        cout << "2) Ver detalle de factura" << endl;
        cout << "3) Eliminar Factura" << endl;
        cout << "0) Volver al menu principal" << endl;
        cout << endl;
        cout << "Elige una opcion" << endl;
        cin >> opcion;

        system("cls");
        switch(opcion){
            case 1: {
                cout << "**** NUEVA VENTA ****" << endl;
                ManagerVentas gestorVentas;
                gestorVentas.crearVenta();

            }
            break;
            case 2: {
                ManagerVentas gestorVentas;
                gestorVentas.verDetalleFactura();
            }
            break;
            case 3: {
                ManagerVentas gestorVentas;
                gestorVentas.eliminarVenta();
            }
            break;
            case 0: cout << "Volviendo al menu principal" << endl;
            return;
            default: cout << "Ingrese un valor valido" << endl;
            break;
        }
        system("pause");
    }

}
