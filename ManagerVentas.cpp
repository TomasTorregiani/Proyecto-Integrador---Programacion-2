#include "ArchivoProductos.h"
#include "ArchivoClientes.h"

using namespace std;

ManagerVentas::ManagerVentas()
: _archivo("ventas.dat"){}

bool ManagerVentas::crearVenta()
{
    //agregar CLIENTE:
    int idCliente;
    cout << "Ingrese id del cliente: " << endl;
    cin >> idCliente;

    ArchivoClientes archivoC("clientes.dat");
    Cliente encontrado = archivoC.archivoBuscarClientePorId(idCliente);
    Cliente clienteParaVenta;
    if(encontrado.getIdCliente() == 0)
    {
        cout << "No se encontro ningun registro con ese id" << endl;
        cout << "Agregar Nuevo Cliente: " << endl;
        cout << "---------------------" << endl;

        ManagerClientes managerCliente;
        int escribio = managerCliente.crearCliente();
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

        ManagerVendedores gestorVendedores;
        Vendedor nuevoVendedor = gestorVendedores.crearVendedor();

		//Recien aca se crea la VENTA.

    Venta nuevaVenta(clienteParaVenta.getIdCliente(), nuevoVendedor.getIdVendedor(), "11/11/1111");

    int agregoVenta = _archivoVentas.agregarVenta(nuevaVenta) //archivoVenta.agregarVenta(nuevaVenta);
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
    cout << "Desea agregar productos? (1 = Si / 2 = No)" << endl;
    cin >> opcion;
    while(opcion == 1);
}
