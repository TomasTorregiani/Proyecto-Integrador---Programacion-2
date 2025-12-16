#include <iostream>
#include "ManagerVentas.h"
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

ManagerVentas::ManagerVentas()
    :_archivoVentas("ventas.dat"), _ventaActual() {}


float ManagerVentas::calcularTotal(int idVenta)
{
    ArchivoDetalles archivoD("detalles_venta.dat");

    int cantidad = contarRegistros("detalles_venta.dat", sizeof(DetalleVenta));
    float total = 0;

    for (int i = 0; i < cantidad; i++)
    {
        DetalleVenta d = archivoD.leerRegistro(i);

        if (d.getIdVenta() == idVenta)
        {
            total += d.getSubtotal();
        }
    }

    return total;
}

bool ManagerVentas::testingCrearVenta()
{

cout << endl;

//agregar FECHA MANUALMENTE:

int dia, mes, anio;

cout << "Ingrese un dia: " << endl;
cin >> dia;
cout << endl;

cout << "Ingrese un mes: " << endl;
cin >> mes;
cout << endl;

cout << "Ingrese un anio" << endl;
cin >> anio;
cout << endl;

Fecha fechaParaVenta(dia, mes, anio);


//agregar CLIENTE:

    int idCliente;
    cout << "Ingrese ID del cliente: ";
    cin >> idCliente;

    ArchivoClientes archivoC("clientes.dat");
    Cliente clienteEncontrado = archivoC.buscarClientePorId(idCliente);

     if(clienteEncontrado.getIdCliente() == 0)
    {
        cout << "No se encontro ningun registro con ese id" << endl;
        cout << "Agregar Nuevo Cliente: " << endl;
        cout << "---------------------" << endl;

        ManagerClientes managerCliente;
        clienteEncontrado = managerCliente.crearNuevoCliente();
        managerCliente.guardarUnCliente(clienteEncontrado);
    }

		Cliente clienteParaVenta = clienteEncontrado;

    cout << "Cliente: (" << idCliente << ") = " << clienteParaVenta.getNombre() << " " << clienteParaVenta.getApellido()<<  endl << endl;

    //agregar VENDEDOR:

    int idVendedor;
    cout << "Ingrese id Vendedor: " << endl;
    cin >> idVendedor;

    ArchivoVendedores archivoV("vendedores.dat");
    Vendedor vendedorEncontrado = archivoV.buscarVendedorPorId(idVendedor); //devuelve un Vendedor

    //Vendedor nuevoVendedor;

    if(vendedorEncontrado.getIdVendedor() == 0)
    {
        cout << "No se encontro ningun registro con ese id" << endl;
        cout << "Agregar Nuevo Vendedor: " << endl;
        cout << "---------------------" << endl;

        ManagerVendedores gestorVendedores;
        vendedorEncontrado = gestorVendedores.crearNuevoVendedor();
        gestorVendedores.guardarUnVendedor(vendedorEncontrado);
    }

    Vendedor vendedorParaVenta = vendedorEncontrado;

    cout << "Vendedor: (" << idVendedor << ") = "<< vendedorParaVenta.getNombre() << " " << vendedorParaVenta.getApellido()<<  endl << endl;

    //Recien aca se crea la VENTA.

    Venta nuevaVenta(clienteParaVenta.getIdCliente(), vendedorParaVenta.getIdVendedor(), fechaParaVenta);

    int agregoVenta = _archivoVentas.agregarVenta(nuevaVenta);
    if(agregoVenta == 0)
    {
        cout << "Error al agregar el archivo" << endl;
    }
    else
    {
        cout << "Venta agregada correctamente" << endl;
    }

    cout << "El id de la venta es: " << nuevaVenta.getIdVenta() << endl;

    //agregar PRODUCTO:

    int opcion;

    do // <<----- acá empieza un do while
    {
        int idProducto;
        cout << "Ingrese id del producto a agregar: " << endl;
        cin >> idProducto;

        ArchivoProductos archivoProducto("productos.dat");

        Producto productoAAgregar = archivoProducto.buscarProductoPorId(idProducto);

        cout << productoAAgregar.getDescripcion() << " - Precio unitario: $" << productoAAgregar.getPrecio() << endl;

        ArchivoDetalles archivoDetalles("detalles_venta.dat");

        if(productoAAgregar.getIdProducto() != 0)
        {
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
        }
        cout << "Desea agregar productos? (1 = Si / 2 = No)" << endl;
        cin >> opcion;
    }
    while(opcion == 1);
    return true;

}


bool ManagerVentas::crearVenta()
{
    //Primero se agrega automaticamente la fecha:

    Fecha fechaActual;
    fechaActual.obtenerFechaActual();

    Fecha fechaParaVenta = fechaActual.getFecha();
    cout << "Fecha de venta: " << fechaParaVenta.toString() << endl;

    //agregar CLIENTE:

    int idCliente;
    cout << "Ingrese ID del cliente: ";
    cin >> idCliente;

    ArchivoClientes archivoC("clientes.dat");
    Cliente clienteEncontrado = archivoC.buscarClientePorId(idCliente);

    if(clienteEncontrado.getIdCliente() == 0)
    {
        cout << "No se encontro ningun registro con ese id" << endl;
        cout << "Agregar Nuevo Cliente: " << endl;
        cout << "---------------------" << endl;

        ManagerClientes managerCliente;
        clienteEncontrado = managerCliente.crearNuevoCliente();
        managerCliente.guardarUnCliente(clienteEncontrado);
    }

    Cliente clienteParaVenta = clienteEncontrado;

    cout << "Cliente: (" << idCliente << ") = " << clienteParaVenta.getNombre() << " " << clienteParaVenta.getApellido()<<  endl << endl;

    //agregar VENDEDOR:

    int idVendedor;
    cout << "Ingrese id Vendedor: " << endl;
    cin >> idVendedor;

    ArchivoVendedores archivoV("vendedores.dat");
    Vendedor vendedorEncontrado = archivoV.buscarVendedorPorId(idVendedor); //devuelve un Vendedor

    //Vendedor nuevoVendedor;

    if(vendedorEncontrado.getIdVendedor() == 0)
    {
        cout << "No se encontro ningun registro con ese id" << endl;
        cout << "Agregar Nuevo Vendedor: " << endl;
        cout << "---------------------" << endl;

        ManagerVendedores gestorVendedores;
        vendedorEncontrado = gestorVendedores.crearNuevoVendedor();
        gestorVendedores.guardarUnVendedor(vendedorEncontrado);
    }

    Vendedor vendedorParaVenta = vendedorEncontrado;

    cout << "Vendedor: (" << idVendedor << ") = "<< vendedorParaVenta.getNombre() << " " << vendedorParaVenta.getApellido()<<  endl << endl;

    //Recien aca se crea la VENTA.

    Venta nuevaVenta(clienteParaVenta.getIdCliente(), vendedorParaVenta.getIdVendedor(), fechaParaVenta);

    //agregar PRODUCTO:

    int opcion;

    do // <<----- acá empieza un do while
    {
        int idProducto;
        cout << "Ingrese id del producto a agregar: " << endl;
        cin >> idProducto;

        ArchivoProductos archivoProducto("productos.dat");

        Producto productoAAgregar = archivoProducto.buscarProductoPorId(idProducto);

        cout << productoAAgregar.getDescripcion() << " - Precio unitario: $" << productoAAgregar.getPrecio() << endl;

        ArchivoDetalles archivoDetalles("detalles_venta.dat");

        if(productoAAgregar.getIdProducto() != 0)
        {
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
        }
        cout << "Desea agregar productos? (1 = Si / 2 = No)" << endl;
        cin >> opcion;
    }
    while(opcion == 1);

    int agregoVenta = _archivoVentas.agregarVenta(nuevaVenta);
    if(agregoVenta == 0)
    {
        cout << "Error al agregar el archivo" << endl;
    }
    else
    {
        cout << "Venta agregada correctamente" << endl;
    }

    cout << "El id de la venta es: " << nuevaVenta.getIdVenta() << endl;
    return true;
}

void ManagerVentas::verDetalleFactura()
{
    int idVenta;
    cout << "Ingrese el id de venta: " << endl;
    cin >> idVenta;

    ArchivoVentas archivoV("ventas.dat");

    Venta ventaObtenida = archivoV.obtenerVenta(idVenta);

    if(ventaObtenida.getIdVenta() == 0)
    {
        cout << "No se encontro la venta" << endl;

    }
    else
    {
        ArchivoClientes archivoC("clientes.dat");
        Cliente clienteObtenido = archivoC.buscarClientePorId(ventaObtenida.getIdCliente());

        ArchivoVendedores registroArchivoVendedores("vendedores.dat");
        Vendedor vendedorObtenido = registroArchivoVendedores.buscarVendedorPorId(ventaObtenida.getIdVendedor());

        if(clienteObtenido.getIdCliente() == 0 || vendedorObtenido.getIdVendedor() == 0)
        {
            cout << endl;
            cout << "ERROR al buscar cliente o vendedor !!" << endl << endl;
        }
        else
        {
            //Mostramos la cabecera de la factura
            cout << "Cliente: " << clienteObtenido.getNombre() << " "
                 << clienteObtenido.getApellido() << endl;
            cout << "Vendedor: " << vendedorObtenido.getNombre() << " "
                 << vendedorObtenido.getApellido() << endl;
            cout << "Fecha: " << ventaObtenida.getFechaString()<< endl;
            cout << "Estado de la factura: " << (ventaObtenida.getAnulada() == false ? "Vigente" : "Anulada") << endl;
        }

        ArchivoDetalles archivo("detalles_venta.dat");
        DetalleVenta detalles[50]; 											// quizás se podría hacer un vector dinámico.

        cout << endl;

        int cantidadDetalles = archivo.verDetalleVenta(idVenta, detalles); // ver esto.
        cout << "**** Detalles de la factura ****" << endl << endl;
        for(int i = 0; i < cantidadDetalles; i++)
        {
            //Mostramos los detalles de la factura
            cout << "Producto: " << detalles[i].getProducto().getDescripcion() << endl;
            cout << "Cantidad: " << detalles[i].getCantidad() << endl;
            cout << "Subtotal: $" << detalles[i].getSubtotal() << endl;
            cout << "-----------------------------------" << endl;
        }
        float totalVenta = calcularTotal(ventaObtenida.getIdVenta());
        cout << "TOTAL FACTURA: $" << totalVenta << endl;
    }
}

void ManagerVentas::eliminarVenta()
{
    int idVentaAEliminar;
    cout << "Ingrese id de la venta a eliminar: " << endl;
    cin >> idVentaAEliminar;

    ArchivoVentas archivo("ventas.dat");

    int posicion = archivo.buscarPosicionPorID(idVentaAEliminar);
    if(posicion == -1)
    {
        cout << "No se encontro el archivo" << endl;
    }
    else
    {
        Venta ventaAModificar = archivo.obtenerVenta(idVentaAEliminar);
        ventaAModificar.anularVenta();
        int ventaActualizada = archivo.actualizarVentaEnPosicion(posicion, ventaAModificar);
        if(ventaActualizada == 0)
        {
            cout << "No se pudo sobreescribir la venta" << endl;
        }
        else
        {
            cout << "Venta modificada correctamente" << endl;
        }
    }
}

//{

/*Validaciones
bool validarStock(int idProducto, int cantidad);

// Actualizar datos relacionados
bool actualizarStock(const Venta& venta);
}

bool ManagerVentas::agregarDetalleVenta()
{


}

void ManagerVentas::listarVentas() {}

void ManagerVentas::eliminarVenta(int idVenta){

	//TODO//

}


/*Venta venta;

ArchivoVentas archivoVenta("ventas.dat");
int agregado = archivoVenta.agregarVenta(venta);
if(agregado == 1){
cout << "Venta agregada correctamente" << endl;
}else{
cout << "Error al agregar la venta" << endl;
}*/


/*void ManagerVentas::cargarCliente()
{
    Venta registroVenta;
    int escribio = archivoC.agregarCliente(nuevoCliente);
    if(escribio == 1)
    {
        cout << "El archivo se escribio correctamente" << endl;
        clienteParaVenta = nuevoCliente;
    }
}*/

/*void ManagerVentas::listarVentas()
{

//TODO

}*/

/*void ManagerVentas::modificarVenta()
{

//TODO

}
ManagerVentas::~ ManagerVentas(){
	if (_archivo != nullptr) {
        delete _archivo;
        _archivo = nullptr;
	}
}
*/
