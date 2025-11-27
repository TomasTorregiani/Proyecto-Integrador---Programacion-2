#include <iostream>
#include "Cliente.h"
#include "ArchivoClientes.h"
#include "Producto.h"
#include "ArchivoProductos.h"
#include "Venta.h"
#include "ArchivoVentas.h"
#include "DetalleVenta.h"
#include "ArchivoDetalles.h"
#include "Vendedor.h"
#include "ArchivoVendedores.h"
#include "TodosLosMenu.h"
#include "FuncionesGlobales.h"
#include "FuncionesInformesYReportes.h"

using namespace std;

void MenuInformesYReportes(){
    int opcion;
    while(true){
        system("cls");
        cout << "**** MENU INFORMES Y REPORTES ****" << endl;
        cout << "1) Recaudacion mensual/anual" << endl;
        cout << "2) Productos mas vendidos" << endl;
        cout << "3) Productos con bajo stock" << endl;
        cout << "4) Ventas por vendedor" << endl;
        cout << "5) Clientes que mas compraron" << endl;
        cout << "0) Salir" << endl;
        cout << "-------------------------------------" <<  endl;
        cout << "Elige una opcion: " << endl;
        cin >> opcion;
        system("cls");
        switch(opcion){
            case 1: {
                cout << "**** RECAUDACION MENSUAL/ANUAL ****" << endl;
                recaudacionMensualYAnual();
            }
            break;
            case 2: {
                cout << "**** PRODUCTOS MAS VENDIDOS ****" << endl;
                productosMasVendidos();
            }
            break;
            case 3: {
                cout << "**** PRODUCTOS CON BAJO STOCK ****" << endl;
                productosConBajoStock();
            }
            break;
            case 4: {
                cout << "**** VENTAS POR VENDEDOR ****" << endl;
                ventasPorVendedor();
            }
            break;
            case 5: {
                cout << "**** CLIENTES QUE MAS COMPRARON ****" << endl;
                clientesQueMasCompraron();
            }
            break;
            case 0: cout << "Volviendo al menu principal..." << endl;
                    return;
            default: cout << "Ingrese un valor valido" << endl;
            break;
        }
        system("pause");
    }
}
