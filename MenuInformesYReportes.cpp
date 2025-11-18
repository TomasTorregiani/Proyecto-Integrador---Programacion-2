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
                int solicituRecaudacion;
                do{
                    cout << "Ingrese si quiere solicitud 1.Mensual o 2.Anual: " << endl;
                    cin >> solicituRecaudacion;
                    switch(solicituRecaudacion){
                        case 1:
                            int mesSeleccionado;
                            cout << "Ingrese el mes: " << endl;
                        break;
                        case 2:
                            int anioSeleccionado;
                            cout << "Ingrese el anio: " << endl;
                            cin >> anioSeleccionado;
                        break;
                        default:
                            cout << "Ingrese una opcion correcta" << endl;
                        break;
                    }
                }while(solicituRecaudacion < 1 && solicituRecaudacion > 2);
            }
            break;
            case 2: {
                cout << "**** PRODUCTOS MAS VENDIDOS ****" << endl;

                int cantidadDetallesVendidos = contarRegistros("detalles_venta.dat", sizeof(DetalleVenta));
                ArchivoDetalles archivoDetalles("detalles_venta.dat");

                int tamanio;
                int *detalles = archivoDetalles.obtenerVentasPorProducto(cantidadDetallesVendidos, tamanio);

                int *idsProductos;
                idsProductos = new int[tamanio]();

                for(int i = 0; i < tamanio; i++){
                    idsProductos[i] = i;
                }
                //Ordeno los array de mayor a menor. Utilizando burbuja
                for (int i = 0; i < tamanio - 1; i++) {
                    for (int j = 0; j < tamanio - i - 1; j++) {
                        if (detalles[j] < detalles[j + 1]) {
                            int aux = detalles[j];
                            detalles[j] = detalles[j + 1];
                            detalles[j + 1] = aux;
                            int auxIds = idsProductos[j];
                            idsProductos[j] = idsProductos[j + 1];
                            idsProductos[j + 1] = auxIds;
                        }
                    }
                }
                ArchivoProductos archivoP("productos.dat");
                Producto productoObtenido;

                bool hayVentas = false;
                cout << "Productos de mas vendidos a menos vendidos" << endl;
                for(int i = 0; i < tamanio; i++){
                    if(detalles[i] > 0){
                        productoObtenido = archivoP.buscarProductoPorId(idsProductos[i]);
                        cout << "ID" << idsProductos[i] << ". " << productoObtenido.getDescripcion() << ", cantidad vendida: " << detalles[i] << endl;
                        hayVentas = true;
                    }
                }
                if(!hayVentas){
                    cout << "No se vendio ningun producto" << endl;
                }
                delete[] detalles;
                delete[] idsProductos;
            }
            break;
            case 3: {
                cout << "PRODUCTOS CON BAJO STOCK" << endl;
                ArchivoProductos archivoProducto("productos.dat");

                int cantidadProductos = contarRegistros("productos.dat", sizeof(Producto));
                Producto *productos = archivoProducto.obtenerProductos(cantidadProductos);

                int cantidadProductosConStockMenorA10 = 0;
                for(int i = 0; i < cantidadProductos; i++){
                    if(productos[i].getCantidadDisponible() <= 10){
                        cantidadProductosConStockMenorA10++;
                    }
                }

                Producto *arrayProductosConBajoStock;
                arrayProductosConBajoStock = new Producto[cantidadProductosConStockMenorA10];
                int indice = 0;
                for(int i = 0; i < cantidadProductos; i++){
                    if(productos[i].getCantidadDisponible() <= 10){
                        arrayProductosConBajoStock[indice] = productos[i];
                        indice++;
                    }
                }

                for(int i = 0; i < cantidadProductosConStockMenorA10; i++){
                    for(int j = 0; j < cantidadProductosConStockMenorA10 - i - 1; j++){
                        if(arrayProductosConBajoStock[j].getCantidadDisponible() < arrayProductosConBajoStock[j+1].getCantidadDisponible()){
                            Producto auxiliar = arrayProductosConBajoStock[j];
                            arrayProductosConBajoStock[j] = arrayProductosConBajoStock[j+1];
                            arrayProductosConBajoStock[j+1] = auxiliar;
                        }
                    }
                }
                delete[] productos;
                delete[] arrayProductosConBajoStock;
            }
            break;
            case 4: {
                cout << "**** VENTAS POR VENDEDOR ****" << endl;

                ArchivoVentas archivoVenta("ventas.dat");
                int cantidadVentas = contarRegistros("ventas.dat", sizeof(Venta));

                Venta *arrayVentas;
                arrayVentas = archivoVenta.obtenerTodasLasVentas(cantidadVentas);

                int idVendedor;
                cout << "Ingrese id vendedor: " << endl;
                cin >> idVendedor;
                int ventasPorVendedor = 1;
                bool encontroVentas = false;
                for(int i = 0; i < cantidadVentas; i++){
                    if(arrayVentas[i].getIdVendedor() == idVendedor){
                        cout << "Venta ****" << ventasPorVendedor << "****" << endl;
                        cout << "Vendedor: " << arrayVentas[i].getIdVendedor() << endl;
                        cout << "Cliente: " << arrayVentas[i].getIdCliente() << endl;

                        //Buscamos los detalles en el archivo 'detalles_venta.dat'
                        ArchivoDetalles archivoDetalle("detalles_venta.dat");
                        DetalleVenta arrayDetalles[50];
                        int cantidadDetalles = archivoDetalle.verDetalleVenta(arrayVentas[i].getIdVenta(),arrayDetalles);
                        cout << "Cantidad detalles: " << cantidadDetalles << endl;
                        for(int j = 0; j < cantidadDetalles; j++){
                            cout << j+1 << "." << arrayDetalles[j].getProducto().getDescripcion() << endl;
                        }
                        encontroVentas = true;
                        ventasPorVendedor++;
                    }
                }
                if(!encontroVentas){
                    cout << "No se encontraron ventas para ese vendedor" << endl;
                }
                delete[] arrayVentas;
            }
            break;
            case 5: {
                cout << "**** CLIENTES QUE MAS COMPRARON ****" << endl;

                int cantidadVentas = contarRegistros("ventas.dat", sizeof(Venta));
                ArchivoVentas archivoVenta("ventas.dat");
                Venta* arrayVentasObtenidas = archivoVenta.obtenerTodasLasVentas(cantidadVentas);

                int maximoId = 0;
                for(int i = 0; i < cantidadVentas; i++){
                    if(arrayVentasObtenidas[i].getIdCliente() > maximoId){
                        maximoId = arrayVentasObtenidas[i].getIdCliente();
                    }
                }

                int* arrayIdsClientes;
                arrayIdsClientes = new int[maximoId + 1]();

                for(int i = 0; i < maximoId; i++){
                    arrayIdsClientes[i] = i;
                }

                float* arrayTotalesClientes;
                arrayTotalesClientes = new float[maximoId + 1]();

                for(int i = 0; i < cantidadVentas; i++){
                    arrayTotalesClientes[arrayVentasObtenidas[i].getIdCliente()] +=  arrayVentasObtenidas[i].getTotal();
                }

                for(int i = 0; i < maximoId; i++){
                    for(int j = 0; j < maximoId - i - 1; j++){
                        if(arrayTotalesClientes[j] < arrayTotalesClientes[j+1]){
                            float auxiliar = arrayTotalesClientes[j];
                            arrayTotalesClientes[j] = arrayTotalesClientes[j+1];
                            arrayTotalesClientes[j+1] = auxiliar;
                            int auxiliarIds = arrayIdsClientes[j];
                            arrayIdsClientes[j] = arrayIdsClientes[j+1];
                            arrayIdsClientes[j+1] = auxiliarIds;
                        }
                    }
                }
                delete[] arrayVentasObtenidas;
                delete[] arrayIdsClientes;
                delete[] arrayTotalesClientes;
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
