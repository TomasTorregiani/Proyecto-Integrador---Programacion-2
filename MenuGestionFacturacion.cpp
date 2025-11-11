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
								ManagerVentas gestorVentas;
								gestorVentas.nuevaVenta();
            }
            break;
            case 2: {
                int idVenta;
                cout << "Ingrese el id de venta: " << endl;
                cin >> idVenta;

                ArchivoVentas archivoV("ventas.dat");

                Venta ventaObtenida = archivoV.obtenerVenta(idVenta);
                if(ventaObtenida.getIdVenta() == 0){
                    cout << "No se encontro la venta";

                } else{
                    ArchivoClientes archivoC("clientes.dat");
                    Cliente clienteObtenido = archivoC.buscarClientePorId(ventaObtenida.getIdCliente());

                    ArchivoVendedores registroArchivoVendedores("vendedores.dat");
                    Vendedor vendedorObtenido = registroArchivoVendedores.buscarVendedorPorId(ventaObtenida.getIdVendedor());

                    if(clienteObtenido.getIdCliente() == 0 || vendedorObtenido.getIdVendedor() == 0){
                        cout << "Error al buscar cliente o vendedor";
                    }else{
                        //Mostramos la cabecera de la factura
                        cout << "Cliente: " << clienteObtenido.getNombre() << " "
                        << clienteObtenido.getApellido() << endl;
                        cout << "Vendedor: " << vendedorObtenido.getNombre() << " "
                        << vendedorObtenido.getApellido() << endl;
                        cout << "Fecha: " << ventaObtenida.getFecha()<< endl;
                        cout << "Estado de la factura: " << (ventaObtenida.getAnulada() == false ? "Vigente" : "Anulada");
                    }

                    ArchivoDetalles archivo("detalle_ventas.dat");
                    DetalleVenta detalles[50];

                    int cantidadDetalles = archivo.verDetalleVenta(idVenta, detalles);
                    for(int i = 0; i < cantidadDetalles; i++){
                        //Mostramos los detalles de la factura
                        cout << "Producto: " << detalles[i].getProducto().getDescripcion() << endl;
                        cout << "Cantidad: " << detalles[i].getCantidad() << endl;
                        cout << "Subtotal: " << detalles[i].getSubtotal() << endl;
                        cout << "-----------------------------------" << endl;
                    }
                }
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
                    ventaAModificar.anularVenta();
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
