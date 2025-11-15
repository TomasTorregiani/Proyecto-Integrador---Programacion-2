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
                cout << "**** NUEVA VENTA ****" << endl;
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

                    Cliente nuevoCliente;
                    nuevoCliente.crearCliente();
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

                ArchivoVendedores archivoV("vendedores.dat");
                Vendedor vendedorEncontrado = archivoV.buscarVendedorPorId(idVendedor);
                if(vendedorEncontrado.getIdVendedor() == 0){
                    cout << "No se encontro ningun registro con ese id" << endl;
                    cout << "Agregar Nuevo Vendedor: " << endl;
                    cout << "---------------------" << endl;
                    vendedorEncontrado.crearVendedor();
                    int escribio = archivoV.agregarVendedor(vendedorEncontrado);
                    if(escribio == 1){
                        cout << "Vendedor guardado correctamente" << endl;
                    }
                }
                Venta nuevaVenta(clienteParaVenta.getIdCliente(), vendedorEncontrado.getIdVendedor(), "11/11/1111");
                ArchivoVentas archivoVenta("ventas.dat");
                int agregoVenta = archivoVenta.agregarVenta(nuevaVenta);
                if(agregoVenta == 0 ){
                    cout << "Error al agregar el archivo" << endl;
                }else {
                    cout << "Venta agregada correctamente" << endl;
                }
                int opcion;
                do{
                    int idProducto;
                    cout << "Ingrese id del producto a agregar: " << endl;
                    cin >> idProducto;

                    ArchivoProductos archivoProducto("productos.dat");
                    Producto productoAAgregar = archivoProducto.buscarProductoPorId(idProducto);
                    ArchivoDetalles archivoDetalles("detalles_venta.dat");
                    if(productoAAgregar.getIdProducto() != 0){
                        cout << "Producto encontrado" << endl;
                        int cantidad;
                        cout << "Ingrese la cantidad: ";
                        cin >> cantidad;

                        // Crear detalle con producto y cantidad
                        DetalleVenta detalle(productoAAgregar, cantidad);

                        // Asociar al id de la venta
                        detalle.setIdVenta(nuevaVenta.getIdVenta());

                        // Guardar detalle
                        archivoDetalles.agregarDetalle(detalle);
                        cout << "Detalle agregado correctamente." << endl;
                    }else{
                        cout << "Producto no encontrado" << endl;
                        Producto nuevoProducto;
                        nuevoProducto.crearNuevoProducto();
                        ArchivoProductos archivoP("productos.dat");
                        int productoAgregado = archivoP.agregarNuevoProducto(nuevoProducto);
                        if(productoAgregado != 0){
                            cout << "Producto agregado correctamente" << endl;
                        }else{
                            cout << "Error al agregar el nuevo producto" << endl;
                        }
                    }
                    cout << "Desea agregar mas productos? (1 = Si / 2 = No)" << endl;
                    cin >> opcion;
                }while(opcion == 1);

            }
            break;
            case 2: {
                cout << "**** VER DETALLE DE FACTURA ****" << endl;
                int idVenta;
                cout << "Ingrese el id de venta: " << endl;
                cin >> idVenta;

                ArchivoVentas archivoV("ventas.dat");

                Venta ventaObtenida = archivoV.obtenerVenta(idVenta);
                cout << "DEBUG: ID Venta obtenida: " << ventaObtenida.getIdVenta() << endl;
                cout << "DEBUG: ID Cliente: " << ventaObtenida.getIdCliente() << endl;
                cout << "DEBUG: ID Vendedor: " << ventaObtenida.getIdVendedor() << endl;
                cout << "DEBUG: Fecha: " << ventaObtenida.getFecha() << endl;
                if(ventaObtenida.getIdVenta() == 0){
                    cout << "No se encontro la venta" << endl;

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
                        cout << "Estado de la factura: " << (ventaObtenida.getAnulada() == false ? "Vigente" : "Anulada") << endl;
                    }

                    ArchivoDetalles archivo("detalles_venta.dat");
                    DetalleVenta detalles[50];

                    int cantidadDetalles = archivo.verDetalleVenta(idVenta, detalles);
                    cout << "**** Detalles de la factura ****" << endl;
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
