#include <iostream>
#include "TodosLosMenu.h"
#include "ArchivoDetalles.h"
#include "Fecha.h"
#include "ArchivoCliente.h"
#include "Cliente.h"
#include "Vendedor.h"
#include "ArchivoVendedores.h"

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
                int idCliente;
                cout << "Ingrese id del cliente: " << endl;
                cin >> idCliente;

                ArchivoClientes archivoC("clientes.dat");
                Cliente encontrado = archivoC.buscarClientePorId(idCliente);
                Cliente clienteParaVenta;
                if(encontrado.getIdCliente() == 0){
                    cout << "No se encontro ningun registro con ese id" << endl;
                    cout << "Agregar Nuevo Cliente: " << endl;
                    cout << "---------------------" << endl;

                    clienteParaVenta = encontrado.cargarCliente();
                    int escribio = archivoC.agregarCliente(nuevoCliente);
                    if(escribio == 1){
                        cout << "El archivo se escribio correctamente" << endl;
                        clienteParaVenta = nuevoCliente;
                    }
                }else{
                    clienteParaVenta = encontrado;
                }

                int idVendedor;
                cout << "Ingrese id Vendedor: " << endl;
                cin >> idVendedor;

                ArchivoVendedor archivoV("vendedores.dat");
                Vendedor encontrado = archivoV.buscarVendedorPorId(idVendedor);
                Vendedor nuevoVendedor;
                if(encontrado.getIdVendedor() == 0){
                    cout << "No se encontro ningun registro con ese id" << endl;
                    cout << "Agregar Nuevo Vendedor: " << endl;
                    cout << "---------------------" << endl;
                    nuevoVendedor = encontrado.cargarVendedor();
                    int escribio = archivoV.agregarVendedor(nuevoVendedor);
                    if(escribio == 1){
                        cout << "Vendedor guardado correctamente" << endl;
                    }

                }else {
                    nuevoVendedor = encontrado;
                }
                Venta nuevaVenta(clienteParaVenta.getIdCliente(), nuevoVendedor.getIdVendedor(), "11/11/1111");
                ArchivoVentas archivoVenta("ventas.dat");
                int agregoVenta = archivoVenta.agregarVenta(nuevaVenta);
                if(agregoVenta == 0 ){
                    cout << "Error al agregar el archivo" << endl;
                }else {
                    cout << "Venta agregada correctamente" << endl;
                }
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
                    cout << "Cliente: " << ventaObtenida.getCliente().getNombre() << " "
                    << ventaObtenida.getCliente().getApellido() << endl;
                    cout << "Vendedor: " << ventaObtenida.getVendedor().getNombre() << " "
                    << ventaObtenida.getVendedor().getApellido() << endl;
                    cout << "Fecha: " << ventaObtenida.getFecha << endl;

                    ArchivoDetalles archivo("detalle_ventas.dat");
                    DetalleVenta detalles[50];

                    int cantidadDetalles = archivo.verDetalleVenta(idVenta, detalles);
                    for(int i = 0; i < cantidadDetalles; i++){
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

                int posicion = archivo.buscarPosicionPorID(idVentaAEliminar); //Aca quede....


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
