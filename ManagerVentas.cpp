#include <iostream>
#include "ManagerVentas.h"
#include "ArchivoClientes.h"
#include "ArchivoVendedores.h"
#include "ArchivoDetalles.h"
#include "Venta.h"
#include "Vendedor.h"
#include "ArchivoProductos.h"

using namespace std;

ManagerVentas ManagerVentas() {}

bool ManagerVentas::nuevaVenta()
{
    //agregar CLIENTE:

    int idCliente;
    cout << "Ingrese id del cliente: " << endl;
    cin >> idCliente;

    ArchivoClientes archivoC("clientes.dat");
    Cliente encontrado = archivoC.buscarClientePorId(idCliente);
    Cliente clienteParaVenta;
    if(encontrado.getIdCliente() == 0)
    {
        cout << "No se encontro ningun registro con ese id" << endl;
        cout << "Agregar Nuevo Cliente: " << endl;
        cout << "---------------------" << endl;

        Cliente nuevoCliente;
        nuevoCliente.cargarCliente();
        int escribio = archivoC.agregarCliente(nuevoCliente);
        if(escribio == 1)
        {
            cout << "El archivo se escribio correctamente" << endl;
            clienteParaVenta = nuevoCliente;
        }

    }
    else
    {
        clienteParaVenta = encontrado;
    }

    //agregar VENDEDOR:

    int idVendedor;
    cout << "Ingrese id Vendedor: " << endl;
    cin >> idVendedor;

    ArchivoVendedores archivoV("vendedores.dat");
    Vendedor vendedorEncontrado = archivoV.buscarVendedorPorId(idVendedor);
    Vendedor nuevoVendedor;
    if(vendedorEncontrado.getIdVendedor() == 0)
    {
        cout << "No se encontro ningun registro con ese id" << endl;
        cout << "Agregar Nuevo Vendedor: " << endl;
        cout << "---------------------" << endl;
        
        vendedorEncontrado.crearVendedor();
        
        int escribio = archivoV.guardarVendedor(nuevoVendedor);
        if(escribio == 1)
        {
            cout << "Vendedor guardado correctamente" << endl;
        }
    }
    else
    {
        nuevoVendedor = vendedorEncontrado;
    }

		//Recien aca se crea la VENTA.
		
    Venta nuevaVenta(clienteParaVenta.getIdCliente(), nuevoVendedor.getIdVendedor(), "11/11/1111");
    ArchivoVentas archivoVenta("ventas.dat");

    int agregoVenta = archivoVenta.agregarVenta(nuevaVenta);
    if(agregoVenta == 0 )
    {
        cout << "Error al agregar el archivo" << endl;
    }
    else
    {
        cout << "Venta agregada correctamente" << endl;
    }

    //agregar PRODUCTO:

    int opcion;
    cout << "Desea agregar productos? (1 = Si / 2 = No)" << endl;
    cin >> opcion;

    do // <<----- acá empieza un do while
    {

        int idProducto;
        cout << "Ingrese id del producto a agregar: " << endl;
        cin >> idProducto;

        ArchivoProductos archivoProducto("productos.dat");
        Producto productoAAgregar = archivoProducto.buscarProductoPorId(idProducto);
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

    }
    while(opcion == 1);
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
        cout << "No se encontro la venta";

    }
    else
    {
        ArchivoClientes archivoC("clientes.dat");
        Cliente clienteObtenido = archivoC.buscarClientePorId(ventaObtenida.getIdCliente());

        ArchivoVendedores registroArchivoVendedores("vendedores.dat");
        Vendedor vendedorObtenido = registroArchivoVendedores.buscarVendedorPorId(ventaObtenida.getIdVendedor());

        if(clienteObtenido.getIdCliente() == 0 || vendedorObtenido.getIdVendedor() == 0)
        {
            cout << "Error al buscar cliente o vendedor";
        }
        else
        {
            //Mostramos la cabecera de la factura
            cout << "Cliente: " << clienteObtenido.getNombre() << " "
                 << clienteObtenido.getApellido() << endl;
            cout << "Vendedor: " << vendedorObtenido.getNombre() << " "
                 << vendedorObtenido.getApellido() << endl;
            cout << "Fecha: " << ventaObtenida.getFecha()<< endl;
            cout << "Estado de la factura: " << (ventaObtenida.getEstado() == false ? "Vigente" : "Anulada");
        }

        ArchivoDetalles archivo("detalle_ventas.dat");
        DetalleVenta detalles[50];

        int cantidadDetalles = archivo.verDetalleVenta(idVenta, detalles);
        for(int i = 0; i < cantidadDetalles; i++)
        {
            //Mostramos los detalles de la factura
            cout << "Producto: " << detalles[i].getProducto().getDescripcion() << endl;
            cout << "Cantidad: " << detalles[i].getCantidad() << endl;
            cout << "Subtotal: " << detalles[i].getSubtotal() << endl;
            cout << "-----------------------------------" << endl;
        }
    }
}
//{

/*Validaciones
bool validarStock(int idProducto, int cantidad);

// Actualizar datos relacionados
bool actualizarStock(const Venta& venta);
}*/

bool ManagerVentas::agregarDetalleVenta()
{


}

void ManagerVentas::listarVentas() {}

void ManagerVentas::eliminarVenta(int idVenta) {}

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

void ManagerVentas::eliminarVenta(int idVenta)
{

    /*int pos = _archivo;//FIXME

    _activo = false;
}*/



