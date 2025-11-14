#include <iostream>
#include "ManagerVentas.h"
#include "ArchivoClientes.h"
#include "ArchivoVendedores.h"
#include "Venta.h"

using namespace std;

ManagerVentas ManagerVentas(){}

bool ManagerVentas::nuevaVenta()
{
	_ventaActual = Venta(); 
	
	bool agregarFecha();
	bool agregarVendedor();
	bool agregarCliente();
	bool agregarDetalleVenta();
	void mostrarResumen();

	bool guardarVenta();

	void generarFactura();

	void listarVentas();
	void eliminarVenta(int idVenta);

	~ManagerVenta();
}

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

    registro.cargarCliente(); //mi no entender.

}
else
{
    clienteParaVenta = encontrado;
}

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
    vendedorEncontrado.cargarVendedor();
    int escribio = archivoV.agregarVendedor(nuevoVendedor);
    if(escribio == 1)
    {
        cout << "Vendedor guardado correctamente" << endl;
    }
}
else
{
    nuevoVendedor = vendedorEncontrado;
}
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
do
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
    int opcion;
    cout << "Desea agregar productos? (1 = Si / 2 = No)" << endl;
    cin >> opcion;
}
while(opcion == 1);

/*Venta venta;

ArchivoVentas archivoVenta("ventas.dat");
int agregado = archivoVenta.agregarVenta(venta);
if(agregado == 1){
cout << "Venta agregada correctamente" << endl;
}else{
cout << "Error al agregar la venta" << endl;
}*/
}

void ManagerVentas::cargarCliente()
{
    Venta registroVenta;
    int escribio = archivoC.agregarCliente(nuevoCliente);
    if(escribio == 1)
    {
        cout << "El archivo se escribio correctamente" << endl;
        clienteParaVenta = nuevoCliente;
    }
}

void ManagerVentas::listarVentas()
{

//TODO

}

void ManagerVentas::modificarVenta()
{

//TODO

}

void ManagerVentas::eliminarVenta(int idVenta)
{

    /*int pos = _archivo;//FIXME

    _activo = false;*/
}



