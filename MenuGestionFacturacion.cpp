#include <iostream>
#include "TodosLosMenu.h"
#include "ManagerVentas.h"
#include "ArchivoDetalles.h"
#include "Fecha.h"
#include "ArchivoClientes.h"
#include "Cliente.h"
#include "Vendedor.h"
#include "ArchivoVendedores.h"
#include "ArchivoVentas.h"
#include "ArchivoProductos.h"


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
								ManagerVentas gestorVentas;
								gestorVentas.nuevaVenta();
            }
            break;
            case 2: {
								ManagerVentas gestorVentas;
								gestorVentas.verDetalleFactura();
            }
            break;
            case 3: {
                int idVentaAEliminar;
                cout << "Ingrese id de la venta a eliminar: " << endl;
                cin >> idVentaAEliminar;

                ArchivoVentas archivo("ventas.dat");

                int posicion = archivo.buscarPosicionPorID(idVentaAEliminar);
                if(posicion == -1){
                    cout << "No se encontro el archivo" << endl;
                }else{
                    Venta ventaAModificar = archivo.obtenerVenta(idVentaAEliminar);
                    ventaAModificar.eliminarVenta();
                    int ventaActualizada = archivo.actualizarVentaEnPosicion(posicion, ventaAModificar);
                    if(ventaActualizada == 0){
                        cout << "No se pudo sobreescribir la venta" << endl;
                    }else{
                        cout << "Venta modificada correctamente" << endl;
                    }
                }
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
