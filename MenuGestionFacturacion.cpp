#include <iostream>
#include "TodosLosMenu.h"
#include "ArchivoDetalles.h"

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
                ArchivoDetalles archivo("detalle_ventas.dat");
            }
            break;
            case 2: {
                ArchivoVentas archivo("detalle_ventas.dat");
                DetalleVenta detalles[50];

                int idVenta;
                cout << "Ingrese el id de venta: " << endl;

                cin >> idVenta;

                int cantidad = archivo.verDetalleVenta(idVenta, detalles);
                for(int i = 0; i < cantidad; i++){
                    cout << "Producto: " << detalles[i].getProducto().getDescripcion() << endl;
                    cout << "Cantidad: " << detalles[i].getCantidad() << endl;
                    cout << "Subtotal: " << detalles[i].getSubtotal() << endl;
                    cout << "-----------------------------------" << endl;
                }
            }
            break;
            case 3: cout << "Eliminar venta" << endl;
            break;
            case 0: cout << "Volviendo al menu principal" << endl;
            return;
            default: cout << "Ingrese un valor valido" << endl;
            break;
        }
        system("pause");
    }

}
