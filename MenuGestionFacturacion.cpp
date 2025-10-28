#include <iostream>
#include "TodosLosMenu.h"
#include "ArchivoDetalles.h"
#include "Fecha.h"
#inlcude "ArchivoCliente.h"
#include "Cliente.h"

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
                    int idNuevoCliente, cuilClienteNuevo, tipoClienteNuevo, numeroTelefonoClienteNuevo;
                    string nombreClienteNuevo, apellidoClienteNuevo,emailNuevoCliente,direccionClienteNuevo;

                    cout << "No se encontro ningun registro con ese id" << endl;
                    cout << "Agregar Nuevo Cliente: " << endl;
                    cout << "---------------------" << endl;
                    idNuevoCliente = contarRegistros("clientes.dat", sizeof(Cliente)) + 1;
                    cout << "Ingresar nombre cliente nuevo: " << endl;
                    cin >> nombreClienteNuevo;
                    cout << "Ingresar apellido cliente nuevo: " << endl;
                    cin >> apellidoClienteNuevo;
                    cout << "Ingresar cuit cliente nuevo: " << endl;
                    cin >> cuilClienteNuevo;
                    cout << "Ingresar tipo cliente nuevo: " << endl;
                    cin >> tipoClienteNuevo;
                    cout << "Ingresar numero de telefono: " << endl;
                    cin >> numeroTelefonoClienteNuevo;
                    cout << "Ingresar email cliente nuevo: " << endl;
                    cin >> emailNuevoCliente;
                    cout << "Ingresar direccion cliente nuevo: " << endl;
                    cin >> direccionClienteNuevo;

                    Cliente nuevoCliente(idNuevoCliente, nombreClienteNuevo, apellidoClienteNuevo,
                                        cuilClienteNuevo, tipoClienteNuevo, numeroTelefonoClienteNuevo,
                                        emailNuevoCliente, direccionClienteNuevo);
                    int escribio = archivoC.agregarCliente(nuevoCliente);
                    if(escribio == 1){
                        cout << "El archivo se escribio correctamente" << endl;
                        clienteParaVenta = nuevoCliente;
                    }
                }else{
                    clienteParaVenta = encontrado;
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
